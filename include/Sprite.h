#include "Mathf.h"

#ifndef Sprite_H
#define Sprite_H



int Add_Sprite(int size);
void FreeSprite(int* sprite,int size);
int CheckVramPlace(void);
void Set_Sprite_Tile(unsigned char Sprite,int x,int y);
void Set_Tile_Palette(int i);
unsigned char *Get_Tilemap(void);
#endif