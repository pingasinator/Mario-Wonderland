#include <gb\gb.h>
#include "..\..\collision.h"

#ifndef Animation_Mario_H
#define Animation_Mario_H

void Anim_Mario_Idle(int Transformation) BANKED;
void Anim_Mario_Move(int Transformation,int animstate) BANKED;
void Anim_Mario_Fall(int Transformation) BANKED;
void Anim_Mario_Jump(int Transformation) BANKED;
void Anim_Mario_Slide(int Transformation) BANKED;
void Anim_Mario_Death(Collision hitbox) BANKED;
void Anim_Mario_Star(void) BANKED;
#endif