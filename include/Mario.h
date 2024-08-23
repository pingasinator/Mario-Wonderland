#include "collision.h"

#ifndef Mario_H
#define Mario_H

void Start_Mario(void);
void Update_Mario(void);
void Mario_Move(void);
void Mario_Idle(void);
void Mario_Jump(void);
void Mario_Fall(void);

void Mario_Slide(void);

void MoveSmall(void);
void MoveGreat(void);
void DisplayMario(void);

int Get_Transformation(void);
int Set_Transformation(int i);

void Set_Mario_Position(int x,int y);

Collision GetMarioCollision(void);

Vector2 Get_Mario_Velocity(void);
Vector2 *Get_Mario_Velocity_ptr(void);
Vector2 Get_Mario_Position(void);
void Set_Mario_Velocity(int x,int y);

#endif 