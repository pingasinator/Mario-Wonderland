#include "include\Level.h"
#include "include\Camera.h"
#include "include\Mario.h"
#include "include\Enemies.h"
#include "include\Sprite.h"
#include "include\Objects.h"
#include "include\GameSystem.h"
#include "include\Items.h"

#include "include\Animations\BKG.h"

#include <stdio.h>
#include <gb\gb.h>
#include <asm\sm83\string.h>

#include <stdlib.h>

extern Vector2 Camera;

extern Level Level_01;
extern Level Level_02;

extern unsigned char Tilemap[];

extern char Time;
extern char Coins;
extern char Lifes;

Level currentLevel;
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
    Reset_Vram();
    Reset_Level();
    Reset_Items();
    Set_Camera_Position(0,16*29);
    SWITCH_ROM(19 + LevelSelected);
    currentLevel = GetLevel(LevelSelected);
    currentLevel_Size = currentLevel.Length * currentLevel.Width;
    Set_All_Enemies(LevelSelected);
        init_Enemies_Vram();
    init_Level_Vram();
    init_Objects_Vram();
    init_Mario_Vram();
    init_HUD_Vram();
    init_Mario(GetLevel(LevelSelected).Spawnpoint.x,GetLevel(LevelSelected).Spawnpoint.y);

    memcpy(Tilemap,GetLevel(LevelSelected).Tilemap,sizeof(uint8_t) * currentLevel_Size);

    Set_Tile_Palette(0);
    for(int y = 0;y < 32;y++)
    {
        for(int x = 0;x < 16;x++)
        {
            Set_Sprite_Tile(Tilemap[Camera.x / 16 + x  + y * currentLevel.Length],(Camera.x / 16 * 2) + x * 2,y * 2);
        }
    }
}

void Level_Update(void)
{
    init_win(0);
    while (1)
    {
        Update_Mario();
        Update_Camera();
        Update_HUD(Lifes,Coins,Timer);
        Update_Enemy();
        Objects_Update();
        Items_Update();
        Timer_Update();
        Anim_BKG_Update();
        if(EndofLevel)
        {
            Set_GameMode(0);
            break;
        }

        SHOW_SPRITES;
        SHOW_WIN;
        SHOW_BKG;
    }
}

void Timer_Update(void)
{
    milisec -= Time;
    if(milisec <= 0)
    {
        milisec = 30;
        Timer--;
    }

    if(Timer <= 0 &&! Mario_isDead())
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
        return Level_01;
        break;

        case 2:
        return Level_02;
        break;
    }

    return Level_01;
}