#include "include\GameSystem.h"
#include <gb\gb.h>

int Time = 1;
int Coin_Number;
int Lifes_Number = 3;

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
    return Lifes_Number;
}

void Add_Life(int i)
{
    Lifes_Number += i;
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
    for(int i = 0;i < 9;i++)
    {
        if(allInputs[i] == input && !allInputsDown[i])
        {

            for(int j = 0;j < 9;j++)
            {
                if(joypad() == input + allInputs[j] && allInputs[j] != input)
                {
                    allInputsDown[i] = 1;
                    return 1;
                }
            }
            break;
        }
    }
    return 0;
}

int GetButton(unsigned char input)
{
    for(int i = 0; i < 9;i++)
    {
        if(joypad() == input + allInputs[i] && allInputs[i] !=  input)
        {
            return 1;
        }
    }

    for(int i = 0; i < 9;i++)
    {
        if(allInputs[i] == input && allInputsDown[i])
        {
            allInputsDown[i] = 0;
            break;
        }
    }
    return 0;
}