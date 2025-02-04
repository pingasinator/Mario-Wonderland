#include "include\GameSystem.h"
#include <gb\gb.h>

char Time = 1;
char Coins;
char Lifes = 3;

char GameMode = 0;

unsigned char allInputsDown[9] = {0,0,0,0,0,0,0,0,0};
unsigned char allInputsPressed[9] = {0,0,0,0,0,0,0,0,0};
unsigned char allInputs[9] = {NULL,J_RIGHT,J_LEFT,J_UP,J_DOWN,J_A,J_B,J_SELECT,J_START};

int Get_GameMode(void)
{
    return GameMode;
}

void Set_GameMode(int i)
{
    GameMode = i;
}

void Input_Update(void)
{
    unsigned char PressedInputs = joypad();
    
    for(int i = 8; i >= 0;i--)
    {
        allInputsDown[i] = 0;
        if(PressedInputs >= allInputs[i])
        {
            if(allInputsPressed[i] == 0)
            {
                allInputsDown[i] = 1;

            }
            allInputsPressed[i] = 1;
            PressedInputs -= allInputs[i];
        }else
        {
            allInputsPressed[i] = 0;
        }
    }
}
