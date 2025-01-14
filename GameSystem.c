#include "include\GameSystem.h"
#include <gb\gb.h>

char Time = 1;
char Coins;
char Lifes = 3;

char GameMode = 0;

unsigned char allInputsDown[9] = {0,0,0,0,0,0,0,0,0};
unsigned char allInputs[9] = {NULL,J_RIGHT,J_LEFT,J_UP,J_DOWN,J_A,J_B,J_SELECT,J_START};

int Get_GameMode(void)
{
    return GameMode;
}

void Set_GameMode(int i)
{
    GameMode = i;
}

int GetButtonDown(unsigned char input)
{
    unsigned char PressedInputs = joypad();
    
    for(int i = 8; i >= 0;i--)
    {
        if(PressedInputs >= allInputs[i])
        {
            if(input == allInputs[i])
            {
                if(allInputsDown[i] == 0)
                {
                    allInputsDown[i] = 1;
                    return 1;
                }
            }else
            {
                PressedInputs -= allInputs[i];
            }
        }else
        {
            allInputsDown[i] = 0;
        }
    }
    return 0;
}

int GetButton(unsigned char input)
{
    unsigned char PressedInputs = joypad();
    for(int i = 8; i >= 0;i--)
    {
        if(PressedInputs >= allInputs[i])
        {
            if(input == allInputs[i])
            {
                return 1;
            }else
            {
                PressedInputs -= allInputs[i];
            }
        }
    }
    return 0;
}