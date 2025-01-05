#include "Mathf.h"
#include "collision.h"

#ifndef Enemies_H
#define Enemies_H

typedef struct
{
    char start;
    Vector2 position;
    Vector2 velocity;
    Vector2 dir;
    char Hiden;
    char type;
    char animState;
    char Sprite_tile;
    char Sprite_size;
    Collision Hitbox;
    char deathDelay;
    char dead;
    char Knockback;
    char Destroyed;
} Enemy;

void Update_Enemy(void);

Enemy *Get_Enemies(void);
void Set_All_Enemies(int Level);
void Set_All_Enemies(int Level);

void Update_Goomba(Enemy *e);
void Start_Goomba(Enemy *e);

void Koopa_Start(Enemy *e);
void Koopa_Update(Enemy *e);

void Enemy_KnockBack(Enemy *e,int dir);

#endif