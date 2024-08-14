#include "Mathf.h"

#ifndef Sprite_H
#define Sprite_H

static unsigned char Sprites[40] =
{
    1,1,1,1,1,1,1,1,1,1,
    1,1,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0
};

void AddSprite(int* i,int size,int Tile);
void FreeSprite(int* sprite,int size);
int CheckVramPlace(void);

#endif