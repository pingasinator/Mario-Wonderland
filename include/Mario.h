#include "collision.h"

#ifndef Mario_H
#define Mario_H

void init_Mario(int x,int y);
void Update_Mario(void);

void DisplayMario(void);

int Get_Transformation(void);
int Set_Transformation(int i);

int Mario_isDead(void);
void Mario_Set_Death(void);

void Set_Mario_Velocity(int x,int y);
void Set_Mario_Position(int x,int y);
void Get_TileObject(void);
void Mario_Hit(void);
#endif 