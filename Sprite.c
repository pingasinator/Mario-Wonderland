#include "include\Sprite.h"
#include "include\Level.h"
#include <gb\gb.h>

#pragma bank 2

extern unsigned char *S_Default_Tiles[];
extern unsigned char S_Pipe_H[];
extern unsigned char S_Pipe_V[];
extern unsigned char S_Full[];
extern unsigned char S_Light_Grey[];
extern unsigned char S_Dark_Grey[];
extern unsigned char S_Water_0[];
extern unsigned char S_Water_1[];
extern unsigned char S_Water_2[];
extern unsigned char S_Lava_0[];
extern unsigned char S_EndLevel_Background[];
extern unsigned char S_EndLevel_Block[];

unsigned char **Current_Ground_Palette;
unsigned char **Current_Background_Palette;

extern unsigned char S_Mushroom[];
extern unsigned char S_FireFlower[];
extern unsigned char S_Leaf[];
extern unsigned char S_Star[];
extern unsigned char S_FireBall_H[];
extern unsigned char S_FireBall_V[];
extern unsigned char S_Obj_Block[];
extern unsigned char S_Obj_Coin_0[];
extern unsigned char S_Obj_Coin_1[];
extern unsigned char S_Obj_Coin_2[];
extern unsigned char S_Obj_Brick[];

extern unsigned char S_null[];
extern unsigned char S_Mario_Small_Idle[];
extern unsigned char S_Mario_Small_Move_0[];
extern unsigned char S_Mario_Small_Move_1[];
extern unsigned char S_Mario_Small_Move_2[];
extern unsigned char S_Mario_Small_Jump[];
extern unsigned char S_Mario_Small_Fall[];
extern unsigned char S_Mario_Small_Slide[];
extern unsigned char S_Mario_Small_Crounch[];
extern unsigned char S_Mario_Small_Front[];
extern unsigned char S_Mario_Dead[];
extern unsigned char S_Mario_Small_Swim_0[];
extern unsigned char S_Mario_Small_Swim_1[];
extern unsigned char S_Mario_Great_Idle[];
extern unsigned char S_Mario_Great_Move_0[];
extern unsigned char S_Mario_Great_Move_1[];
extern unsigned char S_Mario_Great_Move_2[];
extern unsigned char S_Mario_Great_Jump[];
extern unsigned char S_Mario_Great_Fall[];
extern unsigned char S_Mario_Great_Slide[];
extern unsigned char S_Mario_Great_Crounch[];
extern unsigned char S_Mario_Great_Front[];
extern unsigned char S_Mario_Great_Swim_0[];
extern unsigned char S_Mario_Great_Swim_1[];
extern unsigned char S_Mario_Fire[];
extern unsigned char S_Mario_Racoon[];

extern unsigned char S_Mario_World_Small[];

extern unsigned char S_Goomba_Idle[];
extern unsigned char S_Goomba_Move[];
extern unsigned char S_Goomba_Death[];
extern unsigned char S_Koopa_Idle[];
extern unsigned char S_Koopa_Move_0[];
extern unsigned char S_Koopa_Move_1[];
extern unsigned char S_Koopa_Shell_0[];
extern unsigned char S_Koopa_Shell_1[];
extern unsigned char S_Koopa_Shell_2[];
extern unsigned char S_Koopa_Shell_3[];

extern unsigned char S_Overworld_Ground[];
extern unsigned char S_Overworld_Background_Cloud[];
extern unsigned char S_Overworld_Background_Cloud_1[];
extern unsigned char S_Overworld_Background_Bush[];

extern unsigned char S_Underground_Ground[];

extern unsigned char S_Airship_Ground[];

extern unsigned char S_World_Overworld[];
extern unsigned char S_World_HUD[];

extern unsigned char S_HUD_Life_Mario[];
extern unsigned char S_HUD_Coin[];
extern unsigned char S_HUD_Star[];
extern unsigned char S_HUD_T[];
extern unsigned char S_HUD_Font[];
extern unsigned char S_HUD_X[];

extern unsigned char *Overworld_Background_Palette[];
extern unsigned char *Overworld_Ground_Palette[];
extern unsigned char *Underground_Background_Palette[];
extern unsigned char *Underground_Ground_Palette[];
extern unsigned char *Airship_Ground_Palette[];
extern unsigned char *Airship_Background_Palette[];

extern Level currentLevel;

extern unsigned char Tilemap[];


unsigned char Sprites[40] =
{
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0
};

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

int Remove_Sprite(int Place,int size) BANKED
{
    for(int i = 0; i < size;i++)
    {
        Sprites[Place + i] = 0;
        set_sprite_tile(Place + i,0);
        set_sprite_prop(Place + i,0);
        move_sprite(Place + i,0,0);
    }
    return 0;
}

void Set_Tile_Palette(int i) BANKED
{
    switch(i)
    {
        case 0:
        Current_Background_Palette = Overworld_Background_Palette;
        Current_Ground_Palette = Overworld_Ground_Palette;
        set_bkg_data(0x31,18,S_Overworld_Ground);
        set_bkg_data(0x43,12,S_Overworld_Background_Cloud);
        set_bkg_data(0x4F,8,S_Overworld_Background_Cloud_1);
        break;

        case 1:
        Current_Background_Palette = Underground_Background_Palette;
        Current_Ground_Palette = Underground_Ground_Palette;
        set_bkg_data(0x31,18,S_Underground_Ground);
        break;

        case 2:

        break;

        case 4:
        Current_Background_Palette = Airship_Background_Palette;
        Current_Ground_Palette = Airship_Ground_Palette;
        set_bkg_data(0x31,18,S_Airship_Ground);
        break;
    }
}

unsigned char Get_Tile(int x,int y) BANKED
{
    ENABLE_RAM;
    SWITCH_RAM(2);
    unsigned char tempTile = Tilemap[x/16 + y/16*currentLevel.Length];
    DISABLE_RAM;
    return tempTile;
}

void Set_Tile(unsigned char Tile,int x,int y) BANKED
{
    ENABLE_RAM;
    SWITCH_RAM(2);
    Tilemap[x/16 + y/16*currentLevel.Length] = Tile;
    DISABLE_RAM;
    Set_Sprite_Tile(Tile,x/16*2,y/16*2);
}

void Set_Sprite_Tile(unsigned char Tile,int x,int y) BANKED
{
    x -= 32 * (x / 32);
    y -= 32 * (y / 32);
    if(Tile < 0x80)
    {
        set_bkg_tile_xy(x,y,Current_Background_Palette[Tile][0]);
        set_bkg_tile_xy(x + 1,y,Current_Background_Palette[Tile][1]);
        set_bkg_tile_xy(x,y + 1,Current_Background_Palette[Tile][2]);
        set_bkg_tile_xy(x + 1,y + 1,Current_Background_Palette[Tile][3]);
    }else
    {
        set_bkg_tile_xy(x,y,Current_Ground_Palette[Tile - 0x80][0]);
        set_bkg_tile_xy(x + 1,y,Current_Ground_Palette[Tile - 0x80][1]);
        set_bkg_tile_xy(x,y + 1,Current_Ground_Palette[Tile - 0x80][2]);
        set_bkg_tile_xy(x + 1,y + 1,Current_Ground_Palette[Tile - 0x80][3]);
    }
    
}

void Reset_Vram(void) BANKED
{
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;
    Reset_Sprite_Vram();
    Reset_BKG_Vram();
}

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

    set_sprite_data(0,32,S_Mario_World_Small);
}

void init_World_BKG(unsigned char *World_Tilemap)BANKED
{
    set_bkg_tiles(0,0,20,18,World_Tilemap);
}

void init_Level_Vram(void) BANKED
{

    for(int z = 0; z < 6; z++)
    {
        set_bkg_data(1 + z * 4,4,S_Default_Tiles[z]);
    }
    set_bkg_data(0x19,5,S_Pipe_H);
    set_bkg_data(0x1E,5,S_Pipe_V);
    set_bkg_data(0x23,2,S_Water_0);
    set_bkg_data(0x25,2,S_Lava_0);
    set_bkg_data(0x27,2,S_EndLevel_Background);
    set_bkg_data(0x29,8,S_EndLevel_Block);
    set_bkg_data(0x7D,1,S_Light_Grey);
    set_bkg_data(0x7E,1,S_Dark_Grey);
    set_bkg_data(0x7F,1,S_Full);
}

void init_Objects_Vram(void) BANKED
{

    set_sprite_data(0x80,4,S_Mushroom);
    set_sprite_data(0x84,2,S_FireFlower);
    set_sprite_data(0x86,4,S_Leaf);
    set_sprite_data(0x8A,2,S_Star);
    set_sprite_data(0x8C,2,S_FireBall_H);
    set_sprite_data(0x8E,2,S_FireBall_V);
    set_sprite_data(0x90,4,S_Obj_Block);
    set_sprite_data(0x94,4,S_Obj_Coin_0);
    set_sprite_data(0x98,1,S_Obj_Coin_1);
    set_sprite_data(0x99,1,S_Obj_Coin_2);
    set_sprite_data(0x9A,4,S_Obj_Brick);
}

void init_Enemies_Vram(void) BANKED
{

    set_sprite_data(0xA4,4,S_Goomba_Idle);
    set_sprite_data(0xA8,4,S_Goomba_Move);
    set_sprite_data(0xAC,2,S_Goomba_Death);
    set_sprite_data(0xAE,5,S_Koopa_Idle);
    set_sprite_data(0xB3,1,S_Koopa_Move_0);
    set_sprite_data(0xB4,3,S_Koopa_Move_1);
    set_sprite_data(0xB7,2,S_Koopa_Shell_0);
    set_sprite_data(0xB9,4,S_Koopa_Shell_1);
    set_sprite_data(0xBD,2,S_Koopa_Shell_2);
    set_sprite_data(0xBF,2,S_Koopa_Shell_3);

}

void init_Mario_Vram(void) BANKED
{

    set_sprite_data(0x00,1,S_null);
    set_sprite_data(0x01,6,S_Mario_Small_Idle);
    set_sprite_data(0x07,4,S_Mario_Small_Move_0);
    set_sprite_data(0x0B,4,S_Mario_Small_Move_1);
    set_sprite_data(0x0F,4,S_Mario_Small_Move_2);
    set_sprite_data(0x13,6,S_Mario_Small_Jump);
    set_sprite_data(0x19,1,S_Mario_Small_Fall);
    set_sprite_data(0x1A,5,S_Mario_Small_Slide);
    set_sprite_data(0x1F,4,S_Mario_Small_Crounch);
    set_sprite_data(0x23,3,S_Mario_Small_Front);
    set_sprite_data(0x26,3,S_Mario_Dead);
    set_sprite_data(0x29,6,S_Mario_Small_Swim_0);
    set_sprite_data(0x2F,6,S_Mario_Small_Swim_1);
    set_sprite_data(0x34,8,S_Mario_Great_Idle);
    set_sprite_data(0x3C,2,S_Mario_Great_Move_0);
    set_sprite_data(0x3E,4,S_Mario_Great_Move_1);
    set_sprite_data(0x42,4,S_Mario_Great_Move_2);
    set_sprite_data(0x46,8,S_Mario_Great_Jump);
    set_sprite_data(0x4E,1,S_Mario_Great_Fall);
    set_sprite_data(0x4F,8,S_Mario_Great_Slide);
    set_sprite_data(0x57,4,S_Mario_Great_Crounch);
    set_sprite_data(0x5B,4,S_Mario_Great_Front);
    set_sprite_data(0x5F,6,S_Mario_Great_Swim_0);
    set_sprite_data(0x65,5,S_Mario_Great_Swim_1);
    set_sprite_data(0x6A,3,S_Mario_Fire);
    set_sprite_data(0x6D,2,S_Mario_Racoon);
}

void init_HUD_Vram(void) BANKED
{

    set_bkg_data(0x6D,1,S_HUD_Life_Mario);
    set_bkg_data(0x6E,1,S_HUD_X);
    set_bkg_data(0x6F,1,S_HUD_Coin);
    set_bkg_data(0x70,2,S_HUD_Star);
    set_bkg_data(0x72,1,S_HUD_T);
    set_bkg_data(0x73,10,S_HUD_Font);
}