#include <gb\gb.h>
#include "..\..\collision.h"

#ifndef Animation_Mario_H
#define Animation_Mario_H

#define Animator_Mario_State_Idle 0x00
#define Animator_Mario_State_Move 0x01
#define Animator_Mario_State_Run 0x02
#define Animator_Mario_State_Jump 0x03
#define Animator_Mario_State_Jump_Run 0x04
#define Animator_Mario_State_Fall 0x05
#define Animator_Mario_State_Slide 0x06
#define Animator_Mario_State_Crounch 0x07
#define Animator_Mario_State_Death 0x08
#define Animator_Mario_State_Win 0x09
#define Animator_Mario_State_Racoon_Glide 0x20
#define Animator_Mario_State_Racoon_Fly 0x21

void Anim_Mario_Update(void) NONBANKED;
void Anim_Mario_Idle(void) BANKED;
void Anim_Mario_Move(int animstate) BANKED;
void Anim_Mario_Run(int animstate) BANKED;
void Anim_Mario_Jump(void) BANKED;
void Anim_Mario_Jump_Run(void) BANKED;
void Anim_Mario_Fall(void) BANKED;
void Anim_Mario_Slide(void) BANKED;
void Anim_Mario_Crounch(void)BANKED;
void Anim_Mario_Death(void) NONBANKED;
void Anim_Mario_Star(void) BANKED;
void Anim_Mario_Win(int animstate) BANKED;

#endif