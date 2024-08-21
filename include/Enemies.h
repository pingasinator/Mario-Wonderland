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

void Update_Enemy(Enemy *e);

void Update_Goomba(Enemy *e);
void Goomba_Start(Enemy* e);

void Koopa_Start(Enemy *e);
void Koopa_Update(Enemy *e);
#endif