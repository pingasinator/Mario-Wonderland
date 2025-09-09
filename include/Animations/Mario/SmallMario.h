#include <gb/gb.h>

#ifndef Anim_Mario_Small
#define Anim_Mario_Small

void Anim_Mario_Small_Idle(void) BANKED;
void Anim_Mario_Small_Slide(void) BANKED;
void Anim_Mario_Small_Fall(void) BANKED;
void Anim_Mario_Small_Move(int animstate) BANKED;
void Anim_Mario_Small_Jump(void) BANKED;
void Anim_Mario_Small_Jump_Run(void) BANKED;
void Anim_Mario_Small_Crounch(void) BANKED;
void Anim_Mario_Small_Win(int animstate) BANKED;
void Anim_Mario_Small_Run(int animstate)BANKED;

#endif