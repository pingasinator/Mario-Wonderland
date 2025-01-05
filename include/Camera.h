#include "Mathf.h"
#include <gb\gb.h>

#ifndef Game_H
#define Game_H

void Set_Camera_Position(int x,int y)BANKED;
void MoveCamera(int x,int y)BANKED;
void Update_Camera(void)BANKED;
void Update_HUD(int Lifes,int Coins,int Timer)BANKED;

#endif