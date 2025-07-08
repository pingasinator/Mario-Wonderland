#include "..\include\Tile.h"
#include "..\include\Objects.h"
#include "..\include\Mario.h"
#include "..\include\Sprite.h"

#pragma bank 2

extern unsigned char current_Palette_Index;
extern char Coins;
extern char Lifes;


void Tile_Mario_Interact(unsigned char Tile,int X,int Y,Vector2 velocity,int side) BANKED
{
    if(Tile >= 0x81 && Tile <= 0x95)
    {
        if(velocity.y < 0 && side == 1)
        {
            Q_Block(Tile,X,Y);
        }
    }else if( Tile == 0x04 || Tile == 0x05)
    {
        switch(Tile)
        {
            case 0x04:
            Tile_Use_Coin(X,Y);
            break;

            case 0x05:
            Object_Create_HiddenCoin(X,Y);
            break;
        }
    }else
    {
        switch(current_Palette_Index)
        {
            case 0:
            Tile_Overworld_Mario_Interact(Tile,X,Y,velocity,side);
            break;
        }
    }
}

void Tile_Use_Coin(int x,int y) BANKED
{
    Set_Tile(0,x,y);
    Coins++;
    if(Coins >= 100)
    {
        Coins = 0;
        Lifes++;
        Lifes = Clamp(Lifes,0,99);
    }
}

void Tile_Overworld_Mario_Interact(unsigned char Tile,int X,int Y,Vector2 Velocity,int side) BANKED
{
    switch (Tile)
    {
        case 0xBF:
        Mario_Hit();
        break;
    }
}