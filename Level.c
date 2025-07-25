#include "include\Level.h"
#include "include\Camera.h"
#include "include\Mario.h"
#include "include\Enemies.h"
#include "include\Sprite.h"
#include "include\Objects.h"
#include "include\GameSystem.h"

#include "include\Animations\BKG.h"
#include "include\Animations\Objects.h"

#include <stdio.h>
#include <gb\gb.h>
#include <asm\sm83\string.h>

#include <stdlib.h>

extern Vector2 Camera;

extern Level Level_11;
extern Level Level_12;
extern Level Level_13;
extern Level Level_14;

extern Vector2 Mario_Velocity;
extern Collision Mario_Hitbox;
extern char Mario_Win;
extern char Mario_dead;
extern char Mario_dir;

extern char GameMode;

extern unsigned char Tilemap[];

extern char Time;
extern char Coins;
extern char Lifes;

Level currentLevel;
EndLevelObject currentEndLevelObject;
int currentLevel_Size;

int Timer = 300;
int milisec = 30;

int EndofLevel = 0;

void Reset_Level(void)
{
    EndofLevel = 0;
    Timer = 300;
    milisec = 30;
}

void SetLevel(int LevelSelected)
{
    ENABLE_RAM;
    SWITCH_RAM(2);
    Reset_Vram();
    Reset_Level();
    Object_Reset();
    Set_Mario_Palette(0);
    Set_Camera_Position(0,16*29);
    SWITCH_ROM(20 + LevelSelected / 2);
    currentLevel = GetLevel(LevelSelected);
    currentLevel_Size = currentLevel.Length * currentLevel.Width;
    Set_All_Enemies(LevelSelected);
    currentEndLevelObject = currentLevel.Endblock;
    init_Enemies_Vram();
    init_Objects_Vram();
    init_HUD_Vram();
    init_Mario(GetLevel(LevelSelected).Spawnpoint.x,GetLevel(LevelSelected).Spawnpoint.y);

    memcpy(Tilemap,GetLevel(LevelSelected).Tilemap,sizeof(uint8_t) * currentLevel_Size);

    Set_Tile_Palette(currentLevel.Palette);
    for(int y = 0;y < 32;y++)
    {
        for(int x = 0;x < 16;x++)
        {
            Display_Tile(Tilemap[Camera.x / 16 + x  + y * currentLevel.Length],(Camera.x / 16 * 2) + x * 2,y * 2);
        }
    }
    DISABLE_RAM;
}

void Level_Update(void)
{
    init_win(0);
    SHOW_SPRITES;
    SHOW_WIN;
    SHOW_BKG;
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
            Mario_Win = 1;
            Set_Level_Clear(currentLevel.LevelID);
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
    milisec -= Time * !Mario_Win &&! Mario_dead;
    Timer -= (milisec <= 0);
    milisec = milisec <= 0 ? 30 : milisec;

    if(Timer <= 0 &&! Mario_dead)
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
        return Level_11;
        break;

        case 2:
        return Level_12;
        break;

        case 3:
        return Level_13;
        break;

        case 4:
        return Level_14;
        break;
    }
    return Level_11;
}