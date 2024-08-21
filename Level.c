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

Screen **loadedLevel;

Item* Items;

Screen currentLevel[16];

void SetLevel(void)
{
    SWITCH_ROM(2);
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
    Enemy e = {.position={.x=32,.y=32},.type=0,.sprite=0};
    Set_Mario_Position(2 * 8,27 * 8);
    while (1)
    {
        Update_Mario();
        Update_Enemy(&e);
        Update_Camera();
        SHOW_SPRITES;
        SHOW_BKG;
    }
}

void initLevelVram(void)
{
    for(int z = 0; z < 5; z++)
    {
        set_bkg_data(1 + z * 4,4,Default_Tiles[z]);
    }

    set_bkg_data(22,6,Pipe);
}

Screen *GetCurrentLevel(void)
{
    return currentLevel;
}