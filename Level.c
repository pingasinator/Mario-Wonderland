#include "include\Level.h"
#include "include\Camera.h"
#include "include\Mario.h"
#include "include\Enemies.h"
#include "include\Items.h"
#include "include\Sprite.h"
#include "TilePalettes\TilePalettes.h"
#include "TilePalettes\OverworldPalette.h"

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

Screen currentLevel[16];

void SetLevel(void)
{
    SWITCH_ROM(2);
    init_enemies_sprite();
    initLevelVram();
    SWITCH_ROM(4);

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
    while (1)
    {
        Update_Mario();
        Update_Camera();
        Update_Enemy(E);
        Update_bkg();
        SHOW_SPRITES;
        SHOW_BKG;
    }
}

Screen *GetCurrentLevel(void)
{
    return currentLevel;
}