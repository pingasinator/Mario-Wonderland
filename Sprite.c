#include "include\Sprite.h"
#include "Sprites\AnimatedTiles.h"
#include "Sprites\Overworld.h"
#include <gb\gb.h>

extern unsigned char *Default_Tiles[];
extern unsigned char Pipe_H[];
extern unsigned char Pipe_V[];
extern unsigned char Flag[];
extern unsigned char Tiny_Castle[];

extern unsigned char *DefaultPalette[];
extern unsigned char *OverworldPalette[];
unsigned char **Current_Palette;

unsigned char Tilemap[4096];

int qblock_animstate = 0;
int coin_animstate = 0;

static unsigned char Sprites[40] =
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

void Set_Tile_Palette(int i)
{
    switch(i)
    {
        case 0:
        Current_Palette = OverworldPalette;
        set_bkg_data(48,18,Overworld_Ground);
        break;
    }
}

void Update_bkg(void)
{
    Update_qblock();
    Update_Coin();

}

void Update_Coin(void)
{
    switch (coin_animstate)
    {
        case 0:
        set_bkg_data(0x11,4,Coin_0);
        break;

        case 5:
        set_bkg_data(0x11,4,Coin_1);
        break;

        case 10:
        set_bkg_data(0x11,4,Coin_2);
        break;
       
        case 15:
        set_bkg_data(0x11,4,Coin_3);
        break;
    }

    coin_animstate++;
    coin_animstate = coin_animstate >= 20 ? 0 : coin_animstate;
}

void Update_qblock(void)
{
    switch(qblock_animstate)
    {
        case 0:
        set_bkg_data(0x0D,4,Block_Item_0);
        break;

        case 5:
        set_bkg_data(0x0D,4,Block_Item_1);
        break;

        case 10:
        set_bkg_data(0x0D,4,Block_Item_2);
        break;

        case 15:
        set_bkg_data(0x0D,4,Block_Item_3);
        break;
    }
    qblock_animstate++;
    qblock_animstate = qblock_animstate >= 20 ? 0 : qblock_animstate;
}

unsigned char *Get_Tilemap(void)
{
    return Tilemap;
}

unsigned char Get_Tile(int x,int y)
{
    return Tilemap[x/16 + y/16*128];
}

void Set_Sprite_Tile(unsigned char Tile,int x,int y)
{
    x -= 32 * (x / 32);
    y -= 32 * (y / 32);
    if(Tile >= 11)
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

void initLevelVram(void)
{
    SWITCH_ROM(2);
    for(int z = 0; z < 3; z++)
    {
        set_bkg_data(1 + z * 4,4,Default_Tiles[z]);
    }
    set_bkg_data(13,4,Block_Item_0);
    set_bkg_data(17,4,Coin_0);
    set_bkg_data(21,5,Pipe_H);
    set_bkg_data(26,5,Pipe_V);
    set_bkg_data(31,10,Tiny_Castle);
    set_bkg_data(41,7,Flag);
}

