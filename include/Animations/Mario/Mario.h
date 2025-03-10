#include <gb\gb.h>
#include "..\..\collision.h"

#ifndef Animation_Mario_H
#define Animation_Mario_H

void Anim_Mario_Idle(int Transformation) NONBANKED;
void Anim_Mario_Move(int Transformation,int animstate) NONBANKED;
void Anim_Mario_Fall(int Transformation) NONBANKED;
void Anim_Mario_Jump(int Transformation) NONBANKED;
void Anim_Mario_Slide(int Transformation) NONBANKED;
void Anim_Mario_Death(Collision hitbox) NONBANKED;
void Anim_Mario_Star(void) NONBANKED;
void Anim_Mario_Win(int Transformation,int animstate) NONBANKED;
#endif