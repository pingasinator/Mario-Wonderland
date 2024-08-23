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
    int animState;
    int Sprite_tile;
    int Sprite_size;
    Collision Hitbox;
    int deathDelay;
    int dead;
} Enemy;

void Update_Enemy(Enemy *e);

void Update_Goomba(Enemy *e);
void Start_Goomba(Enemy *e);

void Koopa_Start(Enemy *e);
void Koopa_Update(Enemy *e);

void init_enemies_sprite(void);
#endif