#include "World.h"

#ifndef Game_System_H
#define Game_System_H

typedef struct 
{
    World *Worlds;
}SaveFile;

int Get_GameMode(void);
void Set_GameMode(int i);
void Input_Update(void);
void Save(void);
void Pause(void);
#endif