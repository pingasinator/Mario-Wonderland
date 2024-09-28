#include "..\include\Camera.h"
#include "..\include\Level.h"
#include "..\include\Sprite.h"
#include <gb\gb.h>

Vector2 Camera = {.x=0,.y=0};
Vector2 oldCamera = {.x=0,.y=0};

char c[] = 
{
    0x6F,0x70,0x75,0x75,0,0x71,0x70,0x75,0x75,0,0,0,0,0,0,0x00,0x74,0x75,0x75,0x75
};

void Update_HUD(int Lifes,int Coin,int Timer)
{
    c[2] = 0x75 + Lifes / 10;
    Lifes -= 10 * (Lifes / 10);
    c[3] = 0x75 + Lifes;
    c[7] = 0x75 + Coin / 10;
    Coin -= 10 * (Coin / 10);
    c[8] = 0x75 + Coin;
    c[17] = 0x75 + Timer / 100;
    Timer -= 100 * (Timer / 100);
    c[18] = 0x75 + Timer / 10;
    Timer -= 10 * (Timer / 10);
    c[19] = 0x75 + Timer;
    set_win_tiles(0,0,20,1,c);
    move_win(7,136);
}

Vector2 GetCamera(void)
{
    return Camera;
}

void Update_Camera(void)
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

void MoveCamera(int x,int y)
{
    Camera.x += x;
    Camera.y += y;

    Camera.x = Clamp(Camera.x,0,128 * 16 - 10 * 16);
    Camera.y = Clamp(Camera.y,0,32 * 16 - 9 * 16);
}