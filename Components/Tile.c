#include "..\include\Tile.h"
#include "..\include\Objects.h"
#include "..\include\Mario.h"
#include "..\include\Sprite.h"
#include "..\include\GameSystem.h"
#include "..\include\Level.h"

#include <gb\gb.h>

#pragma bank 2

extern unsigned char allInputsPressed[];
extern unsigned char current_Palette_Index;
extern unsigned char Mario_State;
extern char Coins;
extern char Lifes;

extern Scene CurrentScene;
extern unsigned char Tilemap[];
extern unsigned char **Current_Background_Palette;
extern unsigned char **Current_Ground_Palette;

void Tile_Tilmap_display_FullScreen(int x,int y)
{

}



void Tile_Mario_Interact(unsigned char Tile,int X,int Y,Vector2 velocity,int side) BANKED
{
    if(Tile >= 0x81 && Tile <= 0x95)
    {
        if(velocity.y < 0 && side == 1)
        {
            Q_Block(Tile,X,Y);
        }
    }else if( Tile < 0x0E || (Tile >= 0x98 && Tile <= 0xAB))
    {
        switch(Tile)
        {
            case 0x04:
            Tile_Use_Coin(X,Y);
            break;

            case 0x05:
            Object_Create_HiddenCoin(X,Y);
            break;

            case 0xA4:
            case 0xA5:
            
                if(allInputsPressed[Joy_Button_DOWN] && side == 0)
                {
                    Mario_State = Mario_State_EnterPipe;
                    Level_Set_Next_Scene();
                }
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