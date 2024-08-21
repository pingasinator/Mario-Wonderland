#include "collision.h"

#ifndef Mario_H
#define Mario_H

void Start_Mario(void);
void Update_Mario(void);
void Move(void);
void Idle(void);
void Jump(void);

void Slide(void);

void MoveSmall(void);
void MoveGreat(void);
void DisplayMario(void);

int Get_Transformation(void);
int Set_Transformation(int i);

Collision GetMarioCollision(void);
#endif 