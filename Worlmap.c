
#include "include\Worldmap.h"
#include "include\Sprite.h"
#include "include\GameSystem.h"
#include <gb\gb.h>

void init_WorldMap(void)
{

}

void WorldMap_Update(void)
{
    Reset_Vram();
    Set_Time(1);
    init_Worldmap_Mario_Vram();
    while(1)
    {
        if(joypad() == J_A)
        {
            Set_GameMode(1);
            break;
        }
    }
}