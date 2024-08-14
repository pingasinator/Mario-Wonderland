#include "collision.h"
#include "Mathf.h"

#ifndef Items_H
#define Items_H

typedef struct
{
    int type;
    int started;
    int* Sprite;
    Vector2 position;
    Vector2 velocity;
    Collision hitbox;
}Item;

void Item_Update(Item* i);
void Mushroom_Start(Item* i);
void Mushroom_Update(Item* i);

#endif