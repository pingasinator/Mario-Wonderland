#include "Mathf.h"
#include "collision.h"

#ifndef Enemies_H
#define Enemies_H

typedef struct
{
    char State;
    Vector2 velocity;
    Vector2 dir;
    Vector2 SpawnPoint;
    char type;
    char animState;
    char Sprite_tile;
    char Sprite_size;
    Collision Hitbox;
    char deathDelay;
    char dead;
    char Knockback;
    char Enabled;
} Enemy;

void Update_Enemy(void);

void Set_All_Enemies(int Level);

void Update_Goomba(int i);

void Koopa_Start(Enemy *e);
void Update_Koopa(int i);

void Enemy_KnockBack(Enemy *e,int dir);

#endif