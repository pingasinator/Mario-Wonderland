#include "collision.h"

#ifndef Mario_H
#define Mario_H

void init_Mario(int x,int y)BANKED;
void Update_Mario(void)BANKED;

void DisplayMario(void)BANKED;

int Get_Transformation(void)BANKED;
int Set_Transformation(int i)BANKED;

int Mario_isDead(void)BANKED;
void Mario_Set_Death(void)BANKED;

void Set_Mario_Velocity(int x,int y)BANKED;
void Set_Mario_Position(int x,int y)BANKED;
void Get_TileObject(void)BANKED;
void Mario_Hit(void)BANKED;
#endif 