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
extern unsigned char Tanuki_Leaf[];
extern unsigned char FireBall_H[];
extern unsigned char FireBall_V[];
extern unsigned char Obj_Block[];
extern unsigned char Obj_Coin_0[];
extern unsigned char Obj_Coin_1[];
extern unsigned char Obj_Coin_2[];
extern unsigned char Obj_Brick[];

extern unsigned char null[];
extern unsigned char Mario_Small_Idle[];
extern unsigned char Mario_Small_Move_0[];
extern unsigned char Mario_Small_Move_1[];
extern unsigned char Mario_Small_Move_2[];
extern unsigned char Mario_Small_Jump[];
extern unsigned char Mario_Small_Fall[];
extern unsigned char Mario_Small_Slide[];
extern unsigned char Mario_Small_Crounch[];
extern unsigned char Mario_Small_Front[];
extern unsigned char Mario_Dead[];
extern unsigned char Mario_Small_Swim_0[];
extern unsigned char Mario_Small_Swim_1[];
extern unsigned char Mario_Great_Idle[];
extern unsigned char Mario_Great_Move_0[];
extern unsigned char Mario_Great_Move_1[];
extern unsigned char Mario_Great_Move_2[];
extern unsigned char Mario_Great_Jump[];
extern unsigned char Mario_Great_Fall[];
extern unsigned char Mario_Great_Slide[];
extern unsigned char Mario_Great_Crounch[];
extern unsigned char Mario_Great_Front[];
extern unsigned char Mario_Great_Swim_0[];
extern unsigned char Mario_Great_Swim_1[];
extern unsigned char Mario_Fire[];

extern unsigned char Mario_WorldMap_Small[];

extern unsigned char Goomba_Idle[];
extern unsigned char Goomba_Move[];
extern unsigned char Goomba_Death[];
extern unsigned char Koopa_Idle[];
extern unsigned char Koopa_Move_0[];
extern unsigned char Koopa_Move_1[];

extern unsigned char Overworld_Ground[];
extern unsigned char Overworld_Background[];

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
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0
};

int Add_Sprite(int size)
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
        set_bkg_data(31,18,Overworld_Ground);
        set_bkg_data(49,4,Overworld_Background);
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
        set_bkg_tile_xy(x,y,Current_Palette[Tile - 18][0]);
        set_bkg_tile_xy(x + 1,y,Current_Palette[Tile - 18][1]);
        set_bkg_tile_xy(x,y + 1,Current_Palette[Tile - 18][2]);
        set_bkg_tile_xy(x + 1,y + 1,Current_Palette[Tile - 18][3]);
    }else
    {
        set_bkg_tile_xy(x,y,DefaultPalette[Tile][0]);
        set_bkg_tile_xy(x + 1,y,DefaultPalette[Tile][1]);
        set_bkg_tile_xy(x,y + 1,DefaultPalette[Tile][2]);
        set_bkg_tile_xy(x + 1,y + 1,DefaultPalette[Tile][3]);
    }
    
}

void Reset_Vram(void)
{
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;
    Reset_Sprite_Vram();
    Reset_BKG_Vram();
}

void Reset_Sprite_Vram(void)
{
    SWITCH_ROM(3);
    Remove_Sprite(0,40);
    for(int i = 0; i < 256;i++)
    {
        set_sprite_data(i,1,null);
    }
}

void Reset_BKG_Vram(void)
{   
    SWITCH_ROM(3);
    for(int i = 0; i < 128;i++)
    {
        set_bkg_data(i,1,null);
    }

    for(int x = 0; x < 32;x++)
    {
        for(int y =0; y < 32;y++)
        {
            set_bkg_tile_xy(x,y,0);
        }
    }
}

void Reset_Win_Vram(void)
{

}

void init_Worldmap_Mario_Vram(void)
{
    SWITCH_ROM(3);
     set_sprite_data(0,2,Mario_WorldMap_Small);
}

void init_Level_Vram(void)
{
    SWITCH_ROM(2);
    for(int z = 0; z < 5; z++)
    {
        set_bkg_data(1 + z * 4,4,Default_Tiles[z]);
    }
    set_bkg_data(21,5,Pipe_H);
    set_bkg_data(26,5,Pipe_V);
    set_bkg_data(64,10,Tiny_Castle);
    set_bkg_data(74,7,Flag);
    set_bkg_data(0x7F,1,S_Full);
}

void init_Objects_Vram(void)
{
    SWITCH_ROM(5);
    set_sprite_data(0x80,4,Mushroom);
    set_sprite_data(0x84,2,FireFlower);
    set_sprite_data(0x86,4,Tanuki_Leaf);
    set_sprite_data(0x8A,2,FireBall_H);
    set_sprite_data(0x8C,2,FireBall_V);
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
    set_sprite_data(0xAC,2,Goomba_Death);
    set_sprite_data(0xAE,5,Koopa_Idle);
    set_sprite_data(0xB3,1,Koopa_Move_0);
    set_sprite_data(0xB4,1,Koopa_Move_1);
}

void init_Mario_Vram(void)
{
    SWITCH_ROM(3);
    set_sprite_data(0x00,1,null);
    set_sprite_data(0x01,6,Mario_Small_Idle);
    set_sprite_data(0x07,4,Mario_Small_Move_0);
    set_sprite_data(0x0B,4,Mario_Small_Move_1);
    set_sprite_data(0x0F,4,Mario_Small_Move_2);
    set_sprite_data(0x13,6,Mario_Small_Jump);
    set_sprite_data(0x19,1,Mario_Small_Fall);
    set_sprite_data(0x1A,5,Mario_Small_Slide);
    set_sprite_data(0x1F,4,Mario_Small_Crounch);
    set_sprite_data(0x23,3,Mario_Small_Front);
    set_sprite_data(0x26,3,Mario_Dead);
    set_sprite_data(0x29,6,Mario_Small_Swim_0);
    set_sprite_data(0x2F,6,Mario_Small_Swim_1);
    set_sprite_data(0x34,8,Mario_Great_Idle);
    set_sprite_data(0x3C,2,Mario_Great_Move_0);
    set_sprite_data(0x3E,4,Mario_Great_Move_1);
    set_sprite_data(0x42,4,Mario_Great_Move_2);
    set_sprite_data(0x46,8,Mario_Great_Jump);
    set_sprite_data(0x4E,1,Mario_Great_Fall);
    set_sprite_data(0x4F,8,Mario_Great_Slide);
    set_sprite_data(0x57,4,Mario_Great_Crounch);
    set_sprite_data(0x5B,4,Mario_Great_Front);
    set_sprite_data(0x5F,6,Mario_Great_Swim_0);
    set_sprite_data(0x65,5,Mario_Great_Swim_1);
    set_sprite_data(0x6A,3,Mario_Fire);
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