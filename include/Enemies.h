#include "Mathf.h"
#include "collision.h"

#ifndef Enemies_H
#define Enemies_H

typedef struct
{
    char start;
    Vector2 position;
    Vector2 velocity;
    char Hiden;
    char type;
    int animState;
    int* sprite;
    Collision* Hitbox;
} Enemy;

void Enemy_Update(Enemy *e);

void Goomba_Update(Enemy *e);
void Goomba_Start(Enemy* e);

void Koopa_Start(Enemy *e);
void Koopa_Update(Enemy *e);
#endif