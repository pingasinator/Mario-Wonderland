#include "World.h"
#include <gb/gb.h>

#ifndef Game_System_H
#define Game_System_H

#define Joy_Button_NULL 0x00
#define Joy_Button_RIGHT 0x01
#define Joy_Button_LEFT 0x02
#define Joy_Button_UP 0x03
#define Joy_Button_DOWN 0x04
#define Joy_Button_A 0x05
#define Joy_Button_B 0x06
#define Joy_Button_SELECT 0x07
#define Joy_Button_START 0x08

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