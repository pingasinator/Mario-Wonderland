
#include "include/Level.h"
#include "include/World.h"
#include "include/GameSystem.h"
#include "include/Sprite.h"
#include <gb/gb.h>

extern char Lifes;
extern unsigned char allInputsDown[];
extern char GameMode;

void main(void)
{
    GBDKTitleScreen();
    OBP0_REG = 0xC4;
    OBP1_REG = 0xE0;
    Load_Save(0);
    while (1)
    {
        if(Lifes > 0)
        {
            switch(GameMode)
            {
                case 0:
                BGP_REG = 0xE4;
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

void GBDKTitleScreen(void)
{
    unsigned char pos_Y = 8 * 12;
    init_GBDK_Title();

    while(1)
    {
        pos_Y--;
        Input_Update();
        move_bkg(0,pos_Y);
        SHOW_BKG;
        vsync();
        if(allInputsDown[Joy_Button_START])
        {
            break;
        }else if(pos_Y == 0)
        {
            delay(1000);
            break;
        }
    }

}

void GameOverScreen(void)
{
    Reset_Vram();

    if(allInputsDown[8])
    {
        GameMode = 0;
        Lifes = 3;
        Save();
    }
}