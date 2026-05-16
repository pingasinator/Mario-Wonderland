#include "../include/Tile.h"
#include "../include/Objects.h"
#include "../include/Mario.h"
#include "../include/Sprite.h"
#include "../include/GameSystem.h"
#include "../include/Level.h"

#include <gb/gb.h>

#pragma bank 2

extern unsigned char allInputsPressed[];
extern unsigned char current_Palette_Index;
extern unsigned char Mario_State;
extern char Coins;
extern char Lifes;

extern Vector2 Mario_pipeDir;
extern Collision Mario_Hitbox;

extern Scene CurrentScene;
extern unsigned char Tilemap[];
extern unsigned char **Current_Background_Palette;
extern unsigned char **Current_Ground_Palette;

void Tile_Mario_Interact(unsigned char Tile,int X,int Y,Vector2 velocity,int sideX,int sideY) BANKED
{
    if(Tile >= 0x81 && Tile <= 0x95)
    {
        if(velocity.y < 0 && sideY == -1)
        {
            Q_Block(Tile,X,Y);
        }
    }else if( Tile < 0x0E || (Tile >= 0x98 && Tile <= 0xB3))
    {
        switch(Tile)
        {
            case 0x04:
            Tile_Use_Coin(X,Y);
            break;

            case 0x05:
            Object_Create_HiddenCoin(X,Y);
            break;

            case 0xAD:
            case 0xA5:
            unsigned char c = Get_Tile(X - 9,Y);
            c = sideX < 0 ? 0 : c;
                if(allInputsPressed[Joy_Button_DOWN] && sideY == 1 && Mario_State != Mario_State_EnterPipe && c == Tile - 1)
                {
                    Mario_Hitbox.position.x = (X / 16) * 16;
                    Level_Set_Scene(Tile == 0xA5 ? 1 : 0);
                    Mario_pipeDir.x = 0;
                    Mario_pipeDir.y = 1;
                    Mario_State = Mario_State_EnterPipe;
                }
            break;

            case 0xA7:
            case 0xAF:
            unsigned char c_Up = Get_Tile(X - 9,Y);
            c_Up = sideX < 0 ? 0 : c_Up;
                if(allInputsPressed[Joy_Button_UP] && sideY == -1 && Mario_State != Mario_State_EnterPipe && c_Up == Tile - 1)
                {
                    Mario_Hitbox.position.x = (X / 16) * 16;
                    Level_Set_Scene(Tile == 0xA7 ? 1 : 0);
                    Mario_pipeDir.x = 0;
                    Mario_pipeDir.y = 1;
                    Mario_State = Mario_State_EnterPipe;
                }
            break;

            case 0xA9:
            case 0xB1:
                if (allInputsPressed[Joy_Button_RIGHT] && sideY == 0 && sideX == 1 && Mario_State != Mario_State_EnterPipe)
                {
                    Level_Set_Scene(Tile == 0xA9 ? 1 : 0);
                    Mario_Hitbox.position.y -= 8;
                    Mario_pipeDir.x = 1;
                    Mario_pipeDir.y = 0;
                    Mario_State = Mario_State_EnterPipe;
                }
            
            break;
        }
    }else
    {
        switch(current_Palette_Index)
        {
            case 0:
            Tile_Overworld_Mario_Interact(Tile);
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

void Tile_Overworld_Mario_Interact(unsigned char Tile) BANKED
{
    switch (Tile)
    {
        case 0xBF:
        Mario_Hit();
        break;
    }
}