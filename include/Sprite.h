#include "Mathf.h"

#ifndef Sprite_H
#define Sprite_H

int Add_Sprite(int size);
int Remove_Sprite(int Place,int size);
void Set_Sprite_Tile(unsigned char Sprite,int x,int y);
void Set_Tile_Palette(int i);
unsigned char Get_Tile(int x,int y);
void Set_Tile(unsigned char Tile,int x,int y);
unsigned char *Get_Tilemap(void);

void Reset_Vram(void);
void Reset_Sprite_Vram(void);
void Reset_BKG_Vram(void);
void Reset_Win_Vram(void);

void init_Worldmap_Mario_Vram(void);

void init_Level_Vram(void);
void init_Objects_Vram(void);
void init_Enemies_Vram(void);
void init_Mario_Vram(void);
void init_HUD_Vram(void);
#endif