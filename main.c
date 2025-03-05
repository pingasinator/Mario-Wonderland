
#include "include\Level.h"
#include "include\World.h"
#include "include\GameSystem.h"
#include "include\Sprite.h"
#include <gb\gb.h>

extern char Lifes;

void main(void)
{
    OBP0_REG = 0xC4;
    OBP1_REG = 0xE0;
    while (1)
    {
        if(Lifes > 0)
        {
            switch(Get_GameMode())
            {
                case 0:
                World_Update();
                break;

                case 1:
                Level_Update();
                break;
            }
        }else
        {
            GameOverScreen();
        }
    }
}

void GameOverScreen(void)
{
    Reset_Vram();
}