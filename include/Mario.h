#include "collision.h"

#ifndef Mario_H
#define Mario_H

void Update_Mario(void);

void DisplayMario(void);

int Get_Transformation(void);
int Set_Transformation(int i);

void Set_Mario_Position(int x,int y);

Collision GetMarioCollision(void);

Vector2 Get_Mario_Velocity(void);
Vector2 *Get_Mario_Velocity_ptr(void);
Vector2 Get_Mario_Position(void);
void Set_Mario_Velocity(int x,int y);
void Get_TileObject(void);
#endif 