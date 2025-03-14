#include <gb\gb.h>
#include "..\Enemies.h"

#ifndef Animation_Enemies_H
#define Animation_Enemies_H

void Anim_Goomba_Move(Enemy *e) BANKED;
void Anim_Goomba_Death(Enemy *e) BANKED;
void Anim_Goomba_Knockback(Enemy *e)BANKED;

void Anim_Koopa_Move(Enemy *e) BANKED;
void Anim_Koopa_Shell_Idle(Enemy *e)BANKED;
void Anim_Koopa_Shell_Move(Enemy *e)BANKED;
void Anim_Koopa_Knockback(Enemy *e)BANKED;
#endif