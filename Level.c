#include "include\Level.h"
#include "include\Camera.h"
#include "include\Mario.h"
#include "include\Enemies.h"
#include "include\Sprite.h"
#include "include\Objects.h"
#include "include\GameSystem.h"
#include "TilePalettes\TilePalettes.h"
#include "TilePalettes\OverworldPalette.h"
#include "include\Items.h"

#include "include\Animations\BKG.h"

#include <stdio.h>
#include <gb\gb.h>

#include <stdlib.h>


extern Level Level_01;
extern Level Level_02;

Enemy E[20];

Enemy *currentEnemies;

int Timer = 300;
int milisec = 30;


void SetLevel(int LevelSelected)
{
    init_Enemies_Vram();
    init_Level_Vram();
    init_Objects_Vram();
    init_Mario_Vram();
    init_HUD_Vram();
    Timer = 300;
    SWITCH_ROM(19 + LevelSelected);

    for(int i = 0; i < 4096;i++)
    {
        Get_Tilemap()[i] = GetLevel(LevelSelected).Tilemap[i];
    }

    for(int i=0;i<20;i++)
    {
        E[i] = GetLevel(LevelSelected).Enemies[i];
    }

    Vector2 camera;
    camera = GetCamera();
    Set_Tile_Palette(0);
    for(int y = 0;y < 32;y++)
    {
        for(int x = 0;x < 16;x++)
        {
            Set_Sprite_Tile(Get_Tilemap()[camera.x / 16 + x  + y * 128],(camera.x / 16 * 2) + x * 2,y * 2);
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
        Update_HUD(Get_Life_Number(),Get_Coin_Number(),Timer);
        Update_Enemy(E);
        Objects_Update();
        Items_Update();
        Anim_BKG_Update();
        milisec--;
        if(milisec <= 0)
        {
            milisec = 30;
            Timer--;
        }
        SHOW_SPRITES;
        SHOW_WIN;
        SHOW_BKG;
    }
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