#include <gb\gb.h>

#ifndef Anim_Mario_Great
#define Anim_Mario_Great

void Anim_Mario_Great_Idle(void) BANKED;
void Anim_Mario_Great_Slide(void) BANKED;
void Anim_Mario_Great_Fall(void) BANKED;
void Anim_Mario_Great_Move(int animstate) BANKED;
void Anim_Mario_Great_Run(int animstate) BANKED;
void Anim_Mario_Great_Jump(void) BANKED;
void Anim_Mario_Great_Jump_Run(void) BANKED;
void Anim_Mario_Great_Crounch(void) BANKED;
void Anim_Mario_Great_Win(int animstate) BANKED;

#endif