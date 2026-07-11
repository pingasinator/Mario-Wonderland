#include "../../include/Sprite.h"
#include "../../include/Level.h"
#include <gb/gb.h>

#pragma bank 5

unsigned char current_Palette_Index;
unsigned char **Current_Ground_Palette;
unsigned char **Current_Background_Palette;

extern unsigned char S_Default_0[];
extern unsigned char S_Default_1[];

extern unsigned char S_Default_3[];

extern unsigned char S_Overworld_Ground[];
extern unsigned char S_Underground_Ground[];
extern unsigned char S_Desert_Ground[];
extern unsigned char S_Underwater_Ground[];
extern unsigned char S_Castle_Ground[];
extern unsigned char S_Snow_Ground[];
extern unsigned char S_Forest_Ground[];
extern unsigned char S_Sky_Ground[];
extern unsigned char S_Volcano_Ground[];
extern unsigned char S_Airship_Ground[];

extern unsigned char *Overworld_Background_Palette[];
extern unsigned char *Overworld_Ground_Palette[];
extern unsigned char *Underground_Background_Palette[];
extern unsigned char *Underground_Ground_Palette[];
extern unsigned char *Desert_Ground_Palette[];
extern unsigned char *Desert_Background_Palette[];
extern unsigned char *UnderWater_Ground_Palette[];
extern unsigned char *UnderWater_Background_Palette[];
extern unsigned char *Castle_Ground_Palette[];
extern unsigned char *Castle_Background_Palette[];
extern unsigned char *Snow_Ground_Palette[];
extern unsigned char *Snow_Background_Palette[];
extern unsigned char *Forest_Ground_Palette[];
extern unsigned char *Forest_Background_Palette[];
extern unsigned char *Sky_Ground_Palette[];
extern unsigned char *Sky_Background_Palette[];
extern unsigned char *Volcano_Ground_Palette[];
extern unsigned char *Volcano_Background_Palette[];
extern unsigned char *Airship_Ground_Palette[];
extern unsigned char *Airship_Background_Palette[];

extern Scene CurrentScene;

extern unsigned char Tilemap[];

/**
 * Change the Level tile palette and BKG color palette in the Vram
 * 
 * 0 = Overworld
 * 1 = Underground
 * 2 = Desert
 * 3 = UnderWater
 * 4 = Castle
 * 5 = Snow
 * 6 = Forest
 * 7 = Sky
 * 8 = Volcano
 * 9 = Airship
**/
void Set_Tile_Palette(int i) BANKED
{
    current_Palette_Index = i;
    switch(i)
    {
        case 0:
        Current_Background_Palette = Overworld_Background_Palette;
        Current_Ground_Palette = Overworld_Ground_Palette;
        set_bkg_data(0x00,54,S_Default_0);
        set_bkg_data(0x36,64,S_Overworld_Ground);
        BGP_REG = 0xE1;
        break;

        case 1:
        Current_Background_Palette = Underground_Background_Palette;
        Current_Ground_Palette = Underground_Ground_Palette;
        set_bkg_data(0x00,54,S_Default_1);
        set_bkg_data(0x36,45,S_Underground_Ground);
        BGP_REG = 0xC6;
        break;

        case 2:
        set_bkg_data(0x36,45,S_Desert_Ground);
        break;

        case 3:
        set_bkg_data(0x36,45,S_Underwater_Ground);
        break;

        case 4:
        Current_Background_Palette = Castle_Background_Palette;
        Current_Ground_Palette = Castle_Ground_Palette;
        set_bkg_data(0x00,54,S_Default_0);
        set_bkg_data(0x36,51,S_Castle_Ground);
        BGP_REG = 0xE1;
        break;

        case 5:
        set_bkg_data(0x36,45,S_Snow_Ground);
        break;

        case 6:
        set_bkg_data(0x36,45,S_Forest_Ground);
        break;

        case 7:
        set_bkg_data(0x00,54,S_Default_0);
        set_bkg_data(0x36,62,S_Sky_Ground);
        BGP_REG = 0xC6;
        break;

        case 8:
            set_bkg_data(0x36,103,S_Volcano_Ground);
        break;

        case 9:
        Current_Background_Palette = Airship_Background_Palette;
        Current_Ground_Palette = Airship_Ground_Palette;
        set_bkg_data(0x00,54,S_Default_3);
        set_bkg_data(0x36,20,S_Airship_Ground);
        BGP_REG = 0x27;
        break;
    }
}

/**
* Display a tile in the background
*
* @param Tile value of the tile in the current Ground/Background palette (below 128 is the background and equal or above is the ground)
* @param x positoin x in tile
* @param y position y in tile
*/
void Display_Tile(unsigned char Tile,int x,int y) BANKED
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

void Tile_Tilmap_display_xy(int x,int y) BANKED
{
    unsigned char Tile = Tilemap[x / 16 + y / 16 * CurrentScene.Length];
    int VramX = (x / 16 - 16 * (x / 16 / 16)) * 2;
    int VramY = (y / 16 - 16 * (y / 16 / 16)) * 2;

    if(Tile <= 0x80)
    {
        set_bkg_tile_xy(VramX,VramY,Current_Background_Palette[Tile][0]);
        set_bkg_tile_xy(VramX + 1,VramY,Current_Background_Palette[Tile][1]);
        set_bkg_tile_xy(VramX,VramY + 1,Current_Background_Palette[Tile][2]);
        set_bkg_tile_xy(VramX + 1,VramY + 1,Current_Background_Palette[Tile][3]);
    }else
    {
        set_bkg_tile_xy(VramX,VramY,Current_Ground_Palette[Tile - 0x80][0]);
        set_bkg_tile_xy(VramX + 1,VramY,Current_Ground_Palette[Tile - 0x80][1]);
        set_bkg_tile_xy(VramX,VramY + 1,Current_Ground_Palette[Tile - 0x80][2]);
        set_bkg_tile_xy(VramX + 1,VramY + 1,Current_Ground_Palette[Tile - 0x80][3]);
    }
}

/**
 * returns a tile from the tilemap of the current level
 * 
 * @param x position x in pixels
 * @param y position y in pixels
**/
unsigned char Get_Tile(int x,int y) BANKED
{
    ENABLE_RAM;
    SWITCH_RAM(2);
    unsigned char tempTile = Tilemap[x/16 + y/16*CurrentScene.Length];
    DISABLE_RAM;
    return tempTile;
}

void Set_Tile(unsigned char Tile,int x,int y) BANKED
{
    ENABLE_RAM;
    SWITCH_RAM(2);
    Tilemap[x/16 + y/16*CurrentScene.Length] = Tile;
    DISABLE_RAM;
    Display_Tile(Tile,x/16*2,y/16*2);
}
