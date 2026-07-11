#include "../../include/Sprite.h"
#include "../../include/Level.h"
#include "../../include/Animations/Mario/Mario.h"
#include "../../include/Animations/Enemies.h"
#include <gb/gb.h>

#pragma bank 2



extern unsigned char S_Items[];
extern unsigned char S_FireBall_H[];
extern unsigned char S_FireBall_V[];
extern unsigned char S_Obj_Block[];
extern unsigned char S_Obj_Coin[];
extern unsigned char S_Obj_Brick[];
extern unsigned char S_Obj_EndStar_0[];

extern unsigned char S_null[];
extern unsigned char S_Mario_Small[];
extern unsigned char S_Mario_Great[];
extern unsigned char S_Mario_Fire[];
extern unsigned char S_Mario_Racoon[];

extern unsigned char S_Mario_World_Small[];

extern unsigned char S_Goomba[];
extern unsigned char S_Koopa_Idle[];
extern unsigned char S_Koopa_Move_0[];
extern unsigned char S_Koopa_Move_1[];
extern unsigned char S_Koopa_Shell_0[];
extern unsigned char S_Koopa_Shell_1[];
extern unsigned char S_Koopa_Shell_2[];
extern unsigned char S_Koopa_Shell_3[];
extern unsigned char S_Muncher_0[];



extern unsigned char S_World_Overworld[];
extern unsigned char S_World_HUD[];

extern unsigned char S_GBDK[];
extern unsigned char BKG_GBDK[];

extern unsigned char S_HUD[];






extern unsigned char BKG_World_1_Tilemap[];

unsigned char currentMarioPalette;

extern Enemy *AllEnemies;

unsigned char Sprites[40] =
{
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0
};

/**
 * Adding some sprites to the OAM
 * return int 
**/
int Add_Sprite(int size) BANKED
{
    for(int i = 10; i < 40;i++)
    {
        if(Sprites[i] == 0 && Sprites[i + size - 1] == 0)
        {
            for(int j = 0;j < size;j++)
            {
                Sprites[i + j] = 1;
            }
            return i;
        }
    }

    return 0;
}

/**
 * removing sprites from the OAM and reseting the positions  
**/
int Remove_Sprite(int Place,int size) BANKED
{
    if(size <= 40){
        for(int i = 0; i < size ;i++)
        {
            Sprites[Place + i] = 0;
            set_sprite_tile(Place + i,0);
            set_sprite_prop(Place + i,0);
            move_sprite(Place + i,0,0);
        }
    }
    return 0;
}

/**
 * removing non Mario sprites from the OAM and reseting the positions  
 **/
int Remove_NonMarioObject_Sprite(int place,int size) BANKED
{
    if(place > 9)
    {
        Remove_Sprite(place,size);
    }
    return 0;
}









/**
* Reset everything in the VRAM and hide the layers
**/
void Reset_Vram(void) BANKED
{
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;
    Reset_Sprite_Vram();
    Reset_BKG_Vram();
}

/*
* reset the tiles and the OAM
*/
void Reset_Sprite_Vram(void) BANKED
{
    Remove_Sprite(0,40);
    for(int i = 0; i < 256;i++)
    {
        set_sprite_data(i,1,S_null);
    }
}


void Reset_BKG_Vram(void) BANKED
{   
    for(int i = 0; i < 128;i++)
    {
        set_bkg_data(i,1,S_null);
    }

    for(int x = 0; x < 32;x++)
    {
        for(int y =0; y < 32;y++)
        {
            set_bkg_tile_xy(x,y,0);
        }
    }
}

void init_World_Vram(void) BANKED
{
    set_bkg_data(0x00,96,S_World_Overworld);
    set_bkg_data(0x6D,19,S_World_HUD);
}

void init_World_Mario_Vram(void) BANKED
{
    set_sprite_data(0,56,S_Mario_World_Small);
}

void init_World_BKG(int i)BANKED
{
    set_bkg_tiles(0,0,20,18,BKG_World_1_Tilemap);
}

void init_Objects_Vram(void) BANKED
{
    set_sprite_data(0x80,22,S_Items);
    set_sprite_data(0x96,2,S_FireBall_H);
    set_sprite_data(0x98,2,S_FireBall_V);
    set_sprite_data(0x9A,4,S_Obj_Block);
    set_sprite_data(0x9E,6,S_Obj_Coin);
    set_sprite_data(0xA4,4,S_Obj_Brick);
    set_sprite_data(0xA8,2,S_Obj_EndStar_0);
}

void init_Enemies_Vram(void) BANKED
{
    set_sprite_data(0xB0,5,S_Goomba);
    set_sprite_data(0xB5,5,S_Koopa_Idle);
    set_sprite_data(0xBA,1,S_Koopa_Move_0);
    set_sprite_data(0xBB,3,S_Koopa_Move_1);
    set_sprite_data(0xBF,2,S_Koopa_Shell_0);
    set_sprite_data(0xC1,4,S_Koopa_Shell_1);
    set_sprite_data(0xC5,2,S_Koopa_Shell_2);
}

void init_GBDK_Title(void) BANKED
{
    set_bkg_data(0,66,S_GBDK);
    set_bkg_tiles(0,0,20,32,BKG_GBDK);
}

/**
* set the tiles of mario in the vram from 0x00 to 0x7F
*
* @param i select the transformation (
* 0 = Small Mario,
* 1 = Great Mario,
* 2 = Fire Mario,
* 3 = Racoon Mario,
* any other values = Small Mario
* )
**/
void Set_Mario_Palette(int i) NONBANKED
{
    currentMarioPalette = i;

    SWITCH_ROM(3);
    switch (i)
    {
        case 0:
        set_sprite_data(0x00,128,S_Mario_Small);
        break;

        case 1:
        set_sprite_data(0x00,128,S_Mario_Great);
        break;

        case 2:
        set_sprite_data(0x00,128,S_Mario_Fire);
        break;

        case 3:
        set_sprite_data(0x00,128,S_Mario_Racoon);
        break;
    
        default:
        set_sprite_data(0x00,128,S_Mario_Small);
        break;
    }
}

void init_HUD_Vram(void) BANKED
{
    set_sprite_data(0xF0,16,S_HUD);
}

