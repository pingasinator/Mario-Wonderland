#include <gb\gb.h>

#ifndef Animation_RacoonMario_H
#define Animation_RacoonMario_H


void Anim_Mario_Racoon_Idle(void) BANKED;
void Anim_Mario_Racoon_Slide(void) BANKED;
void Anim_Mario_Racoon_Fall(void) BANKED;
void Anim_Mario_Racoon_Move(int animstate) BANKED;
void Anim_Mario_Racoon_Jump(void) BANKED;
void Anim_Mario_Racoon_Win(int animstate) BANKED;

#endif