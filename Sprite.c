#include "include\Sprite.h"
#include <gb\gb.h>

extern unsigned char *Default_Tiles[];
extern unsigned char Pipe_H[];
extern unsigned char Pipe_V[];
extern unsigned char Flag[];
extern unsigned char Tiny_Castle[];
extern unsigned char S_Full[];

extern unsigned char *DefaultPalette[];
extern unsigned char *OverworldPalette[];
unsigned char **Current_Palette;

extern unsigned char Mushroom[];
extern unsigned char FireFlower[];
extern unsigned char FireBall_H[];
extern unsigned char FireBall_V[];
extern unsigned char Obj_Block[];
extern unsigned char Obj_Coin_0[];
extern unsigned char Obj_Coin_1[];
extern unsigned char Obj_Coin_2[];
extern unsigned char Obj_Brick[];

extern unsigned char null[];
extern unsigned char Small_Idle[];
extern unsigned char Small_Move_0[];
extern unsigned char Small_Move_1[];
extern unsigned char Small_Move_2[];
extern unsigned char Small_Jump[];
extern unsigned char Small_Fall[];
extern unsigned char Small_Slide[];

extern unsigned char Goomba_Idle[];
extern unsigned char Goomba_Move[];
extern unsigned char Goomba_Death[];

extern unsigned char Overworld_Ground[];

extern unsigned char S_HUD_Life_Mario[];
extern unsigned char S_HUD_Coin[];
extern unsigned char S_HUD_Star[];
extern unsigned char S_HUD_T[];
extern unsigned char S_HUD_Font[];
extern unsigned char S_HUD_X[];

unsigned char Tilemap[4096];

unsigned char Sprites[40] =
{
    1,1,1,1,1,1,1,1,1,1,
    1,1,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0
};

int Add_Sprite(int size)
{
    
    for(int i = 12; i < 40;i++)
    {
        if(Sprites[i] == 0 && Sprites[i + size] == 0)
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

int Remove_Sprite(int Place,int size)
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

void Set_Tile_Palette(int i)
{
    switch(i)
    {
        case 0:
        SWITCH_ROM(6);
        Current_Palette = OverworldPalette;
        set_bkg_data(48,18,Overworld_Ground);
        break;
    }
}

unsigned char *Get_Tilemap(void)
{
    return Tilemap;
}

unsigned char Get_Tile(int x,int y)
{
    return Tilemap[x/16 + y/16*128];
}

void Set_Tile(unsigned char Tile,int x,int y)
{
    Tilemap[x/16 + y/16*128] = Tile;
    Set_Sprite_Tile(Tile,x/16*2,y/16*2);
}

void Set_Sprite_Tile(unsigned char Tile,int x,int y)
{
    x -= 32 * (x / 32);
    y -= 32 * (y / 32);
    if(Tile >= 18)
    {
        set_bkg_tile_xy(x,y,Current_Palette[Tile][0]);
        set_bkg_tile_xy(x + 1,y,Current_Palette[Tile][1]);
        set_bkg_tile_xy(x,y + 1,Current_Palette[Tile][2]);
        set_bkg_tile_xy(x + 1,y + 1,Current_Palette[Tile][3]);
    }else
    {
        set_bkg_tile_xy(x,y,DefaultPalette[Tile][0]);
        set_bkg_tile_xy(x + 1,y,DefaultPalette[Tile][1]);
        set_bkg_tile_xy(x,y + 1,DefaultPalette[Tile][2]);
        set_bkg_tile_xy(x + 1,y + 1,DefaultPalette[Tile][3]);
    }
    
}

void init_Level_Vram(void)
{
    SWITCH_ROM(2);
    for(int z = 0; z < 3; z++)
    {
        set_bkg_data(1 + z * 4,4,Default_Tiles[z]);
    }
    set_bkg_data(21,5,Pipe_H);
    set_bkg_data(26,5,Pipe_V);
    set_bkg_data(31,10,Tiny_Castle);
    set_bkg_data(41,7,Flag);
    set_bkg_data(0x7F,1,S_Full);
}

void init_Objects_Vram(void)
{
    SWITCH_ROM(5);
    set_sprite_data(0x80,4,Mushroom);
    set_sprite_data(0x84,2,FireFlower);
    set_sprite_data(0x8C,2,FireBall_H);
    set_sprite_data(0x8E,2,FireBall_V);
    set_sprite_data(0x90,4,Obj_Block);
    set_sprite_data(0x94,4,Obj_Coin_0);
    set_sprite_data(0x98,1,Obj_Coin_1);
    set_sprite_data(0x99,1,Obj_Coin_2);
    set_sprite_data(0x9A,4,Obj_Brick);
}

void init_Enemies_Vram(void)
{
    SWITCH_ROM(4);
    set_sprite_data(0xA4,4,Goomba_Idle);
    set_sprite_data(0xA8,4,Goomba_Move);
    set_sprite_data(0xAC,4,Goomba_Death);
}

void init_Mario_Vram(void)
{
    SWITCH_ROM(3);
    set_sprite_data(0x00,1,null);
    set_sprite_data(0x01,6,Small_Idle);
    set_sprite_data(0x07,4,Small_Move_0);
    set_sprite_data(0x0B,4,Small_Move_1);
    set_sprite_data(0x0F,4,Small_Move_2);
    set_sprite_data(0x13,6,Small_Jump);
    set_sprite_data(0x19,1,Small_Fall);
    set_sprite_data(0x1A,5,Small_Slide);
}

void init_HUD_Vram(void)
{
    SWITCH_ROM(7);
    set_bkg_data(0x6F,1,S_HUD_Life_Mario);
    set_bkg_data(0x70,1,S_HUD_X);
    set_bkg_data(0x71,1,S_HUD_Coin);
    set_bkg_data(0x72,2,S_HUD_Star);
    set_bkg_data(0x74,1,S_HUD_T);
    set_bkg_data(0x75,10,S_HUD_Font);
}