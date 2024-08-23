#include "include\GameSystem.h"
#include <gb\gb.h>

int Time = 1;

int Get_Time(void)
{
    return Time;
}

void Set_Time(int i)
{
    Time = i;
}

int GetButtonDown(unsigned char input)
{
    unsigned char allInputs[9] = {NULL,J_RIGHT,J_LEFT,J_UP,J_DOWN,J_A,J_B,J_SELECT,J_START};
    for(int i = 0; i < 9;i++)
    {
        if(joypad() == input + allInputs[i] && input != allInputs[i])
        {
            return 1;
        }
    }

    return 0;
}