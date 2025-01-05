#include "..\include\Camera.h"
#include "..\include\Level.h"
#include "..\include\Sprite.h"
#include <gb\gb.h>

#pragma bank 15

Vector2 Camera = {.x=16,.y=16*29};
Vector2 oldCamera = {.x=0,.y=0};

char c[] = 
{
    0x6D,0x6E,0x73,0x73,0x00,0x6F,0x6E,0x73,0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x72,0x73,0x73,0x73
};

void Update_HUD(int Lifes,int Coin,int Timer)BANKED
{
    c[2] = 0x73 + Lifes / 10;
    Lifes -= 10 * (Lifes / 10);
    c[3] = 0x73 + Lifes;
    c[7] = 0x73 + Coin / 10;
    Coin -= 10 * (Coin / 10);
    c[8] = 0x73 + Coin;
    c[17] = 0x73 + Timer / 100;
    Timer -= 100 * (Timer / 100);
    c[18] = 0x73 + Timer / 10;
    Timer -= 10 * (Timer / 10);
    c[19] = 0x73 + Timer;
    set_win_tiles(0,0,20,1,c);
    move_win(7,136);
}

void Set_Camera_Position(int x,int y)BANKED
{
    Camera.x = x;
    Camera.y = y;
}

void Update_Camera(void)BANKED
{
    char *Tilemap = Get_Tilemap();
    if(oldCamera.x != Camera.x / 16)
    {
        for(int i = 0;i < 11;i++)
        {
            if(Camera.x / 16 - 1 + (Camera.y / 16 - 1 + i) * 128 > 0 && Camera.x / 16 - 1 + (Camera.y / 16 - 1 + i) * 128 < 4096)
            {
                Set_Sprite_Tile(Tilemap[Camera.x / 16 - 1 + (Camera.y / 16 - 1 + i) * 128],Camera.x / 16 * 2 - 2,Camera.y / 16 * 2 - 2 + i * 2);
            }

            if(Camera.x / 16 + 10 + (Camera.y / 16 - 1 + i) * 128 > 0 && Camera.x / 16 + 10 + (Camera.y / 16 - 1 + i) * 128 < 4096)
            {
                Set_Sprite_Tile(Tilemap[Camera.x / 16 + 10 + (Camera.y / 16 - 1 + i) * 128],Camera.x / 16 * 2 + 20,Camera.y / 16 * 2 - 2 + i * 2);
            }
        }
        oldCamera.x = Camera.x / 16;
    }
        
    if(oldCamera.y != Camera.y / 16)
    {
        for(int i = 0;i < 12;i++)
        {
            if(Camera.x / 16 - 1 + i + (Camera.y / 16 - 1) * 128 > 0 && Camera.x / 16 - 1 + i + (Camera.y / 16 - 1) * 128 < 4096)
            {
                Set_Sprite_Tile(Tilemap[Camera.x / 16 - 1 + i + (Camera.y / 16 - 1) * 128],Camera.x / 16 * 2 - 2 + i * 2,Camera.y / 16 * 2 - 2);
            }

            if(Camera.x / 16 - 1 + i + (Camera.y / 16 + 9) * 128 > 0 && Camera.x / 16 - 1 + i + (Camera.y / 16 + 9) * 128 < 4096)
            {
                Set_Sprite_Tile(Tilemap[Camera.x / 16 - 1 + i + (Camera.y / 16 + 9) * 128],Camera.x / 16 * 2 - 2 + i * 2,Camera.y / 16 * 2 + 18);
            }
            

        }
        oldCamera.y = Camera.y / 16;
    }

    move_bkg(Camera.x,Camera.y);
}

void MoveCamera(int x,int y)BANKED
{

    for(int i = 0; i < Abs(x);i++)
    {
        Camera.x += Sign(x);
        SHOW_BKG;
    }

    for(int i = 0; i < Abs(y);i++)
    {
        Camera.y += Sign(y);
        SHOW_BKG;
    }

    Camera.x = Clamp(Camera.x,0,128 * 16 - 10 * 16);
    Camera.y = Clamp(Camera.y,0,32 * 16 - 9 * 16);
}