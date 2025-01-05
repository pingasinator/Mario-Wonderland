#include "collision.h"
#include "Mathf.h"

#ifndef Items_H
#define Items_H

typedef struct
{
    char start;
    Vector2 position;
    Vector2 originalPosition;
    Vector2 velocity;
    char dir;
    char Used;
    char type;
    char Sprite;
    Collision Hitbox;
}Item;

void Reset_Items(void)BANKED;
void Items_Update(void)BANKED;
void Create_Item(int type,int x,int y)BANKED;
void Mushroom_Update(Item* i)BANKED;
void FireFlower_Update(Item *i)BANKED;
void Leaf_Update(Item *i)BANKED;
void Star_Update(Item *i)BANKED;

#endif