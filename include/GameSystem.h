#include "World.h"
#include <gb\gb.h>

#ifndef Game_System_H
#define Game_System_H

typedef struct 
{
    unsigned char init;
    unsigned char LastLevel;
    unsigned char LastWorld;
    unsigned char **Levels;
    unsigned char Coins;
    unsigned char Lifes;
    unsigned char MarioState;
}SaveFile;

void Input_Update(void);
void CheckSaveFiles(void);
void GBDKTitleScreen(void);
void Load_Save(int i);
void Save(void);
void Pause(void);
void GameOverScreen(void);
void init_SaveFile(int i);
#endif