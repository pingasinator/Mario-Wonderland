#include <gb\gb.h>

#ifndef Mario_H
#define Mario_H

#define Mario_State_Neutral 0x00
#define Mario_State_Win 0x01
#define Mario_State_Dead 0x02
#define Mario_State_EnterPipe 0x03

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