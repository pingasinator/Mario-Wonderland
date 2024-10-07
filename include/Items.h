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

void Reset_Items(void);
void Items_Update(void);
void Create_Item(int type,int x,int y);
void Mushroom_Update(Item* i);
void FireFlower_Update(Item *i);

#endif