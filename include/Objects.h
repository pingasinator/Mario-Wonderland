#include "Mathf.h"
#include "collision.h"

#ifndef Objects_H
#define Objects_H

typedef struct 
{
    Vector2 originalPosition;
    Collision hitbox;
    Vector2 Velocity;
    int dir;
    char Used;
    char returnToPoint;
    char Sprite;
    char animstate;
    char type;
}Object;

void Use_Coin(int x,int y) BANKED;
void Objects_Update(void) BANKED;
void Coin_Update(int i) BANKED;
void Blocks_Update(int i) BANKED;
void Q_Block(int Type,int x,int y) BANKED;
void Make_FireBall(int dir,int x,int y) BANKED;
void FireBall_Update(Object *o) BANKED;
#endif