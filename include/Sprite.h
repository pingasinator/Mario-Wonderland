#include "Mathf.h"
#include "Enemies.h"
#include "Objects.h"
#include <gb\gb.h>

#ifndef Sprite_H
#define Sprite_H

int Add_Sprite(int size)BANKED;
int Remove_Sprite(int Place,int size)BANKED;
int Remove_NonMarioObject_Sprite(int Place,int size) BANKED;

void Tile_Tilmap_display_xy(int x,int y) BANKED;
void Display_Tile(unsigned char Sprite,int x,int y)BANKED;
void Set_Tile_Palette(int i)BANKED;
unsigned char Get_Tile(int x,int y)BANKED;
void Set_Tile(unsigned char Tile,int x,int y)BANKED;

void Reset_Vram(void)BANKED;
void Reset_Sprite_Vram(void)BANKED;
void Reset_BKG_Vram(void)BANKED;

void Set_Mario_Palette(int i)NONBANKED;

void init_World_Vram(void) BANKED;
void init_World_Mario_Vram(void)BANKED;

void init_World_BKG(int i)BANKED;

void init_GBDK_Title(void) BANKED;

void init_Objects_Vram(void)BANKED;
void init_Enemies_Vram(void)BANKED;
void init_HUD_Vram(void)BANKED;

void DisplayMario(void)BANKED;
void Display_Goomba(Enemy *e) BANKED;
void Display_Koopa(Enemy *e) BANKED;
void Display_Item(Object *o) BANKED;
#endif