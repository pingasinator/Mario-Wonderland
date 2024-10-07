#include "Mathf.h"

#ifndef Game_H
#define Game_H

Vector2 GetCamera(void);
void Set_Camera_Position(int x,int y);
void MoveCamera(int x,int y);
void Update_Camera(void);
void Update_HUD(int Lifes,int Coins,int Timer);

#endif