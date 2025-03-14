#include "include\GameSystem.h"
#include <gb\gb.h>

char Time = 1;
char Coins;
char Lifes = 3;

char GameMode = 0;

extern SaveFile SaveFile_1;
extern SaveFile SaveFile_2;
extern SaveFile SaveFile_3;

SaveFile *currentSaveFile;

extern unsigned char *SaveFile_1_Levels[];

SaveFile *saveFiles_List[] = {&SaveFile_1,&SaveFile_2,&SaveFile_3};

extern unsigned char SavedPoint;
extern unsigned char World_Dir; 

extern unsigned char Mario_State;

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

void Save(void)
{
    ENABLE_RAM;
    SWITCH_RAM(1);
    currentSaveFile->Coins = Coins;
    currentSaveFile->Lifes = Lifes;
    currentSaveFile->LastLevel = World_Dir;
    currentSaveFile->MarioState = Mario_State;
    DISABLE_RAM;
}

void Pause(void)
{
    while(1)
    {
        Input_Update();
        if(allInputsDown[8])
        {
            break;
        }
    }
}

void CheckSaveFiles(void)
{
    ENABLE_RAM;
    SWITCH_RAM(1);
    for(int i = 0; i < 3; i++)
    {
        if(saveFiles_List[i]->init > 1)
        {
            init_SaveFile(i);
        }
    }
    DISABLE_RAM;

}

void Load_Save(int i)
{
    CheckSaveFiles();
    ENABLE_RAM;
    SWITCH_RAM(1);
    currentSaveFile = saveFiles_List[i];
    Lifes = currentSaveFile->Lifes;
    Coins = currentSaveFile->Coins;
    Mario_State = currentSaveFile->MarioState;
    DISABLE_RAM;
}

void init_SaveFile(int i)
{
    ENABLE_RAM;
    SWITCH_RAM(1);
    saveFiles_List[i]->init = 1;
    saveFiles_List[i]->LastLevel = 0;
    saveFiles_List[i]->LastWorld = 1;
    saveFiles_List[i]->Coins = 0;
    saveFiles_List[i]->Lifes = 3;
    for(int i = 0; i < 8; i++)
    {
        SaveFile_1_Levels[i][0] = 0;
        SaveFile_1_Levels[i][1] = 0;
        SaveFile_1_Levels[i][2] = 0;
        SaveFile_1_Levels[i][3] = 0;
    }
    saveFiles_List[i]->Levels = SaveFile_1_Levels;
    DISABLE_RAM;
}