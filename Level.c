#include "include\Level.h"
#include "include\Camera.h"
#include "include\Mario.h"
#include "include\Enemies.h"
#include "include\Items.h"
#include "include\Sprite.h"
#include "include\TilePalettes.h"

#include "Sprites\Level.h"

#include <stdio.h>
#include <gb\gb.h>

#include <stdlib.h>

extern Screen *Level_00[];
extern Enemy Level_00_Enemies[];

Screen **loadedLevel;
Enemy *currentEnemies;

Item* Items;

Screen currentLevel[16];

void SetLevel(void)
{
    SWITCH_ROM(2);
    currentEnemies = Level_00_Enemies;
    for(int i = 0; i < 16;i++)
    {
        if(Level_00[i] != NULL)
        {
            for(int y = 0;y < 16;y++)
            {
                for(int x = 0;x < 16;x++)
                {
                    Get_Tilemap()[x + i * 16 + y * 128 + (i / 8 * 1920)] = Level_00[i]->Tilemap[x + y * 16];
                }
            }
        }else
        {
            for(int y = 0;y < 16;y++)
            {
                for(int x = 0;x < 16;x++)
                {
                    Get_Tilemap()[x + i * 16 + y * 128 + (i / 8 * 1920)] = 0;
                }
            }
        }
    }

    initLevelVram();
    
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
        Update_Camera();
        Update_Mario();
        Update_Enemy(currentEnemies);

        SHOW_SPRITES;
        SHOW_BKG;
    }
}

void initLevelVram(void)
{
    init_enemies_sprite();

    for(int z = 0; z < 5; z++)
    {
        set_bkg_data(1 + z * 4,4,Default_Tiles[z]);
    }

    set_bkg_data(21,5,Pipe_H);
    set_bkg_data(26,5,Pipe_V);
}

Screen *GetCurrentLevel(void)
{
    return currentLevel;
}