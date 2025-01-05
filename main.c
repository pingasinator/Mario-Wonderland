
#include "include\Level.h"
#include "include\Worldmap.h"
#include "include\GameSystem.h"
#include "include\Sprite.h"
#include <gb\gb.h>

void main(void)
{
    OBP0_REG = 0xC4;
    OBP1_REG = 0xE0;
    while (1)
    {
        if(Get_Life_Number() > 0)
        {
            switch(Get_GameMode())
            {
                case 0:
                WorldMap_Update();
                break;

                case 1:
                SetLevel(1);
                Level_Update();
                break;
            }
        }else
        {

        }
    }
}

void GameOverScreen(void)
{
    Reset_Vram();
}