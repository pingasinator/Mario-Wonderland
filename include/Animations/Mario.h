#include <gb\gb.h>

#ifndef Animation_Mario_H
#define Animation_Mario_H

void Anim_Mario_Idle(int Transformation) BANKED;
void Anim_Mario_Fall(void) BANKED;
void Anim_Mario_Move(int animstate) BANKED;
void Anim_Mario_Jump(void) BANKED;
void Anim_Mario_Slide(void) BANKED;

#endif