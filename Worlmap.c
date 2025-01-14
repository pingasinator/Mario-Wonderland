
#include "include\Worldmap.h"
#include "include\Sprite.h"
#include "include\GameSystem.h"
#include "include\Level.h"
#include <gb\gb.h>

extern char Time;

char currentWorld;

void init_WorldMap(void)
{

}

void WorldMap_Update(void)
{
    Reset_Vram();
    Time = 1;
    init_Worldmap_Mario_Vram();
    while(1)
    {
        if(joypad() == J_A)
        {
            SetLevel(1);
            Set_GameMode(1);
            break;
        }
    }
}