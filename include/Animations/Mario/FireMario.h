#include <gb\gb.h>

#ifndef Anim_FireMario_H
#define Anim_FireMario_H

void Anim_Mario_Fire_Idle(void) BANKED;
void Anim_Mario_Fire_Slide(void) BANKED;
void Anim_Mario_Fire_Fall(void) BANKED;
void Anim_Mario_Fire_Move(int animstate) BANKED;
void Anim_Mario_Fire_Run(int animstate) BANKED;
void Anim_Mario_Fire_Jump(void) BANKED;
void Anim_Mario_Fire_Jump_Run(void) BANKED;
void Anim_Mario_Fire_Win(int animstate) BANKED;
#endif