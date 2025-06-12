#include "Mathf.h"
#include "collision.h"

#ifndef Enemies_H
#define Enemies_H

#define Enemy_Type_Goomba 0x01
#define Enemy_Type_Koopa 0x02

typedef struct
{
    char State;
    Vector2 velocity;
    Vector2 dir;
    Vector2 SpawnPoint;
    char type;
    char AnimatorState;
    char animState;
    char Sprite_tile;
    char Sprite_size;
    Collision Hitbox;
    char deathDelay;
    char dead;
    char Knockback;
    char Enabled;
} Enemy;

void Update_Enemy(void)BANKED;

void Set_All_Enemies(int Level)NONBANKED;

void Update_Goomba(Enemy *e)BANKED;

void Update_Koopa(Enemy *e)BANKED;

void Enemy_KnockBack(Enemy *e,int dir)BANKED;

#endif