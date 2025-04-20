#include <gb\gb.h>

#ifndef Mario_H
#define Mario_H

void init_Mario(int x,int y)BANKED;
void Update_Mario(void)BANKED;
void Mario_Update_AirMovement(void) BANKED;
void Mario_Update_GroundMovement(void) BANKED;
void Mario_Update_Death(void) BANKED;
void Mario_Update_Physics(void) BANKED;
void Mario_Update_Speed(void) BANKED;

int Set_Transformation(int i)BANKED;

void Mario_Set_Death(void)BANKED;

void Mario_Hit(void)BANKED;
void Mario_Update_CheckGround(void) BANKED;
#endif 