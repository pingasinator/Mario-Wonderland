#include "include\GameSystem.h"
#include <gb\gb.h>

int Time = 1;
int Coin_Number;
int Lifes = 3;

int GameMode = 1;

unsigned char allInputsDown[9] = {0,0,0,0,0,0,0,0,0};
unsigned char allInputs[9] = {NULL,J_RIGHT,J_LEFT,J_UP,J_DOWN,J_A,J_B,J_SELECT,J_START};

void Add_Coin(int i)
{
    Coin_Number += i;

    if(Coin_Number >= 100)
    {
        Coin_Number = 0;
        Add_Life(1);
    }
}

int Get_Coin_Number(void)
{
    return Coin_Number;
}

int Get_Life_Number(void)
{
    return Lifes;
}

void Add_Life(int i)
{
    Lifes += i;
}

int Get_Time(void)
{
    return Time;
}

void Set_Time(int i)
{
    Time = i;
}

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