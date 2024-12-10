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

#endif