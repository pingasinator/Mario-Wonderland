#include "include\Level.h"
#include "include\Camera.h"
#include "include\Mario.h"
#include "include\Enemies.h"
#include "include\Items.h"
#include "include\Sprite.h"
#include "include\Objects.h"
#include "include\GameSystem.h"
#include "TilePalettes\TilePalettes.h"
#include "TilePalettes\OverworldPalette.h"

#include "include\Animations\BKG.h"

#include <stdio.h>
#include <gb\gb.h>

#include <stdlib.h>

extern Screen *Level_00[];
extern Enemy Level_00_Enemies[3];

extern unsigned char Level_00_Tilemap[];

Enemy E[3];

Screen **loadedLevel;
Enemy *currentEnemies;

Item* Items;

int Timer = 300;
int milisec = 30;

Screen currentLevel[16];

void SetLevel(void)
{
    init_Enemies_Vram();
    init_Level_Vram();
    init_Objects_Vram();
    init_Mario_Vram();
    init_HUD_Vram();
    Timer = 300;
    SWITCH_ROM(20);

    for(int i = 0; i < 4096;i++)
    {
        Get_Tilemap()[i] = Level_00_Tilemap[i];
    }

    for(int i=0;i<sizeof(Level_00_Enemies) / sizeof(Enemy);i++)
    {
        E[i] = Level_00_Enemies[i];
    }

    
    Set_Tile_Palette(0);
    for(int y = 0;y < 16;y++)
    {
        for(int x = 0;x < 16;x++)
        {
            Set_Sprite_Tile(Get_Tilemap()[x + y * 128],x * 2,y * 2);
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

Screen *GetCurrentLevel(void)
{
    return currentLevel;
}