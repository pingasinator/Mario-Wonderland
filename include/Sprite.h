#include "Mathf.h"
#include <gb\gb.h>

#ifndef Sprite_H
#define Sprite_H

int Add_Sprite(int size)BANKED;
int Remove_Sprite(int Place,int size)BANKED;
void Set_Sprite_Tile(unsigned char Sprite,int x,int y)BANKED;
void Set_Tile_Palette(int i)BANKED;
unsigned char Get_Tile(int x,int y)BANKED;
void Set_Tile(unsigned char Tile,int x,int y)BANKED;

void Reset_Vram(void)BANKED;
void Reset_Sprite_Vram(void)BANKED;
void Reset_BKG_Vram(void)BANKED;

void init_Worldmap_Mario_Vram(void)BANKED;

void init_Level_Vram(void)BANKED;
void init_Objects_Vram(void)BANKED;
void init_Enemies_Vram(void)BANKED;
void init_Mario_Vram(void)BANKED;
void init_HUD_Vram(void)BANKED;
#endif