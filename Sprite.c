#include "include\Sprite.h"
#include "include\Level.h"
#include "include\Animations\Mario\Mario.h"
#include "include\Animations\Enemies.h"
#include <gb\gb.h>

#pragma bank 2

unsigned char current_Palette_Index;
unsigned char **Current_Ground_Palette;
unsigned char **Current_Background_Palette;

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

extern unsigned char S_Overworld_Ground[];
extern unsigned char S_Underground_Ground[];
extern unsigned char S_Airship_Ground[];

extern unsigned char S_World_Overworld[];
extern unsigned char S_World_HUD[];

extern unsigned char S_GBDK[];
extern unsigned char BKG_GBDK[];

extern unsigned char S_HUD[];

extern unsigned char *Overworld_Background_Palette[];
extern unsigned char *Overworld_Ground_Palette[];
extern unsigned char *Underground_Background_Palette[];
extern unsigned char *Underground_Ground_Palette[];
extern unsigned char *Airship_Ground_Palette[];
extern unsigned char *Airship_Background_Palette[];

extern Scene CurrentScene;

extern unsigned char Tilemap[];

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

int Remove_NonMarioObject_Sprite(int Place,int size) BANKED
{
    if(Place >= 10)
    {
        for(int i = 0; i < size;i++)
        {
            Sprites[Place + i] = 0;
            set_sprite_tile(Place + i,0);
            set_sprite_prop(Place + i,0);
            move_sprite(Place + i,0,0);
        }
    }
    return 0;
}

void Set_Tile_Palette(int i) BANKED
{
    current_Palette_Index = i;
    switch(i)
    {
        case 0:
        Current_Background_Palette = Overworld_Background_Palette;
        Current_Ground_Palette = Overworld_Ground_Palette;
        set_bkg_data(0x00,110,S_Overworld_Ground);
        break;

        case 1:
        Current_Background_Palette = Underground_Background_Palette;
        Current_Ground_Palette = Underground_Ground_Palette;
        set_bkg_data(0x0,18,S_Underground_Ground);
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

