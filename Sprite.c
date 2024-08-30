#include "include\Sprite.h"
#include <gb\gb.h>

extern unsigned char *Overworld_Palette[];
unsigned char **Current_Palette;
unsigned char Tilemap[4096];

static unsigned char Sprites[40] =
{
    1,1,1,1,1,1,1,1,1,1,
    1,1,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0
};

static unsigned char fakeVram[256] = 
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
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
        Current_Palette = Overworld_Palette;
        break;
    }
}

unsigned char *Get_Tilemap(void)
{
    return Tilemap;
}

void Set_Sprite_Tile(unsigned char Tile,int x,int y)
{
    x -= 32 * (x / 32);
    y -= 32 * (y / 32);
        set_bkg_tile_xy(x,y,Overworld_Palette[Tile][0]);
        set_bkg_tile_xy(x + 1,y,Overworld_Palette[Tile][1]);
        set_bkg_tile_xy(x,y + 1,Overworld_Palette[Tile][2]);
        set_bkg_tile_xy(x + 1,y + 1,Overworld_Palette[Tile][3]);
}
