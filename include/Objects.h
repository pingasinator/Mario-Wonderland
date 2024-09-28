#include "Mathf.h"
#include "collision.h"


#ifndef Objects_H
#define Objects_H

typedef struct 
{
    Vector2 originalPosition;
    Vector2 position;
    Collision hitbox;
    char Used;
    char returnToPoint;
    int Sprite;
    int animstate;
    char type;
}Object;

void Use_Coin(int x,int y) BANKED;
void Objects_Update(void) BANKED;
void Coin_Update(int i) BANKED;
void Blocks_Update(int i) BANKED;
void Brick_Update(int i) BANKED;
void Q_Block(int Type,int x,int y) BANKED;
void Brick(int x,int y) BANKED;
#endif