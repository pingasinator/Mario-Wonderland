#include "include\Level.h"
#include "include\Camera.h"
#include "include\Mario.h"
#include "include\Items.h"

#include "Sprites\Level.h"

#include <stdio.h>
#include <gb\gb.h>

#include <stdlib.h>

extern Screen *Level_00[];

Item* Items;

Screen currentLevel[16];

void SetLevel(void)
{
    SWITCH_ROM(2);
    
    

    initLevelVram();

    for(int x = 0; x < 32;x++)
    {
        for(int y = 0; y < 32; y++)
        {
            
        }
    }

}

void Level_Update(void)
{
    while (1)
    {
        Update_Mario();

        SHOW_SPRITES;
        SHOW_BKG;
    }
}

void ShowLevel(void)
{
    Vector2 camera;
    camera = GetCamera();



}

void initLevelVram(void)
{
    for(int z = 0; z < 5; z++)
    {
        set_bkg_data(1 + z * 4,4,Default_Tiles[z]);
    }
}

Screen *GetCurrentLevel(void)
{
    return currentLevel;
}

unsigned char *GetScreenTilemap(int i)
{
    return &currentLevel[i].Tilemap[0];
}