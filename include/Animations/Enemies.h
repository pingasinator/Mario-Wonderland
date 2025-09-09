#include <gb/gb.h>
#include "../Enemies.h"

#ifndef Animation_Enemies_H
#define Animation_Enemies_H

#define Animator_Enemy_Goomba_State_Move 0x00
#define Animator_Enemy_Goomba_State_Death 0x01
#define Animator_Enemy_Goomba_State_Knockback 0x02

#define Animator_Enemy_Koopa_State_Move 0x00
#define Animator_Enemy_Koopa_State_Shell_Idle 0x01
#define Animator_Enemy_Koopa_State_Shell_Move 0x02
#define Animator_Enemy_Koopa_State_Knockback 0x03

void Anim_Goomba_Update(Enemy *e) BANKED;
void Anim_Goomba_Move(Enemy *e) BANKED;
void Anim_Goomba_Death(Enemy *e) BANKED;
void Anim_Goomba_Knockback(Enemy *e)BANKED;

void Anim_Koopa_Update(Enemy *e)BANKED;
void Anim_Koopa_Move(Enemy *e) BANKED;
void Anim_Koopa_Shell_Idle(Enemy *e)BANKED;
void Anim_Koopa_Shell_Move(Enemy *e)BANKED;
void Anim_Koopa_Knockback(Enemy *e)BANKED;
#endif