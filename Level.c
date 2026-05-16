#include "include/Level.h"
#include "include/Camera.h"
#include "include/Mario.h"
#include "include/Enemies.h"
#include "include/Sprite.h"
#include "include/Objects.h"
#include "include/GameSystem.h"
#include "include/Tile.h"

#include "include/Animations/BKG.h"
#include "include/Animations/Objects.h"

#include <stdio.h>
#include <gb/gb.h>
#include <asm/sm83/string.h>

#include <stdlib.h>

extern Vector2 Camera;

extern Level Level_1_1;

extern unsigned char Level_1_1_Tilemap[];

Level *Test[] = 
{
    &Level_1_1
};

extern Vector2 Mario_Velocity;
extern Collision Mario_Hitbox;
extern char Mario_State;
extern char Mario_dir;
extern unsigned char Mario_Transformation;

extern char GameMode;

extern unsigned char Tilemap[];

extern char Time;
extern char Coins;
extern char Lifes;

Level currentLevel;
Scene CurrentScene;

EndLevelObject currentEndLevelObject;
int currentScene_Size;

int Timer = 300;
int milisec = 30;
int SceneTransitionDelay = 30;

unsigned char spawnpointIndex;

unsigned char LoadScene;
unsigned char NextSceneIndex;
unsigned char currentSceneIndex;

int EndofLevel = 0;

void Reset_Level(void)
{
    EndofLevel = 0;
    Timer = 300;
    milisec = 30;
}

void Level_Load_Scene(int SelectedScene)
{
    DISPLAY_OFF;
    ENABLE_RAM;
    SWITCH_RAM(2);
    SWITCH_ROM(20);
    CurrentScene = currentLevel.Scenes[SelectedScene];
    SceneTransitionDelay = 30;
    LoadScene = 0;
    Reset_Vram();
    Object_Reset();
    Set_All_Enemies();
    Set_Mario_Palette(Mario_Transformation);
    SWITCH_ROM(20);
    init_Enemies_Vram();
    init_Objects_Vram();
    init_HUD_Vram();
    currentScene_Size = CurrentScene.Length * CurrentScene.Width;
    Set_Tile_Palette(CurrentScene.Palette);

    memcpy(Tilemap,CurrentScene.Tilemap,sizeof(uint8_t) * currentScene_Size);
    init_Mario(CurrentScene.Spawnpoints[spawnpointIndex].Point.x,CurrentScene.Spawnpoints[spawnpointIndex].Point.y);
    Set_Camera_Position(CurrentScene.Spawnpoints[spawnpointIndex].Camera.x,CurrentScene.Spawnpoints[spawnpointIndex].Camera.y);
    for(int y = 0;y < 16;y++)
    {
        for(int x = 0;x < 16;x++)
        {
            Tile_Tilmap_display_xy((Camera.x / 16 / 16) * 16 * 16 + x * 16 ,(Camera.y / 16 / 16) * 16 * 16 + y*16);
        }
    }
    init_win(0);
    SHOW_SPRITES;
    SHOW_WIN;
    SHOW_BKG;
    DISABLE_RAM;
    DISPLAY_ON;
}

void SetLevel(int LevelSelected)
{
    SWITCH_ROM(20);
    Reset_Level();
    spawnpointIndex = 0;
    NextSceneIndex = 0;
    currentLevel = GetLevel(LevelSelected);
    Level_Load_Scene(currentLevel.StartScene);
    currentEndLevelObject = CurrentScene.Endblock;
}


void Level_Set_Scene(unsigned char Index)
{
    if(!LoadScene)
    {
        switch(Index)
        {
            case 0x00:
            NextSceneIndex--;
            spawnpointIndex = NextSceneIndex*4 + 3;
            break;

            case 0x01:
            NextSceneIndex++;
            spawnpointIndex = NextSceneIndex*4 + 2;
            break;
        }
    }
}

void Level_Update(void)
{
    RS:
    while (1)
    {
        Input_Update();
        Update_Mario();
        Update_HUD(Lifes,Coins,Timer);
        Update_Enemy();
        Objects_Update();
        Timer_Update();
        Anim_BKG_Update();
        EndBlock_Update();
        if(LoadScene)
        {
            Level_Load_Scene(NextSceneIndex);
            SceneTransitionDelay=60;
            goto RS;
        }

        if(EndofLevel)
        {
            GameMode = 0;
            break;
        }
    }
}

void EndBlock_Update(void)
{
    if(currentEndLevelObject.hitbox.position.x > Camera.x && currentEndLevelObject.hitbox.position.x < Camera.x + 22 * 8 && currentEndLevelObject.hitbox.position.y > Camera.y - 16 && currentEndLevelObject.hitbox.position.y < Camera.y + 20 * 8)
    {

        Collision c;
        c = currentEndLevelObject.hitbox;
        currentEndLevelObject.hitbox.position.y -= 3 * (currentEndLevelObject.state == 1);
        if(OnCollision(Mario_Hitbox,c))
        {
            currentEndLevelObject.state = 1;
            Mario_dir = Sign(Mario_Hitbox.position.x - currentEndLevelObject.hitbox.position.x + 16 * 3);
            Mario_Velocity.x = 0;
            Mario_State = Mario_State_Win;
            Set_Level_Clear(CurrentScene.LevelID);
            Save();
        }
        Anim_Object_EndBlock(&currentEndLevelObject);
    }else
    {
        if(currentEndLevelObject.Sprite != 0)
        {
            currentEndLevelObject.Sprite = Remove_NonMarioObject_Sprite(currentEndLevelObject.Sprite,4);
        }
    }
}

void Timer_Update(void)
{
    milisec -= Time * !(Mario_State == Mario_State_Win) &&! (Mario_State == Mario_State_Dead);
    Timer -= (milisec <= 0);
    milisec = milisec <= 0 ? 30 : milisec;

    if(Timer <= 0 &&! (Mario_State == Mario_State_Dead))
    {
        Mario_Set_Death();
    }
}

void Set_Level_End(void)
{
    EndofLevel = 1;
}

Level GetLevel(int i)
{
    switch(i)
    {
        case 1:
        return Level_1_1;
        break;


    }
    return Level_1_1;
}