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
#endif 