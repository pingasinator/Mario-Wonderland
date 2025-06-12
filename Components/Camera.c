#include "..\include\Camera.h"
#include "..\include\Level.h"
#include "..\include\Sprite.h"
#include <gb\gb.h>

#pragma bank 15

Vector2 Camera = {.x=16,.y=16*29};
Vector2 oldCamera = {.x=0,.y=0};

extern char Mario_runningProg;

extern Level currentLevel;

extern unsigned char Tilemap[];

char c[20] = 
{
    0xF0,0xFF,0xF4,0xF4,0x00,0xF1,0xFF,0xF4,0xF4,0x00,0xF3,0xF3,0xF3,0xF3,0xF3,0x00,0xFE,0xF4,0xF4,0xF4
};

void Update_HUD(int Lifes,int Coin,int Timer)BANKED
{
    c[2] = 0xF4 + Lifes / 10;
    Lifes -= 10 * (Lifes / 10);
    c[3] = 0xF4 + Lifes;
    c[7] = 0xF4 + Coin / 10;
    Coin -= 10 * (Coin / 10);
    c[8] = 0xF4 + Coin;

    c[10] = 0xF3 - (Mario_runningProg >= 20);
    c[11] = 0xF3 - (Mario_runningProg >= 40);
    c[12] = 0xF3 - (Mario_runningProg >= 60);
    c[13] = 0xF3 - (Mario_runningProg >= 80);
    c[14] = 0xF3 - (Mario_runningProg >= 100);

    c[17] = 0xF4 + Timer / 100;
    Timer -= 100 * (Timer / 100);
    c[18] = 0xF4 + Timer / 10;
    Timer -= 10 * (Timer / 10);
    c[19] = 0xF4 + Timer;
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

}

void MoveCamera(int x,int y)BANKED
{
    ENABLE_RAM;
    SWITCH_RAM(2);

    oldCamera.x = Camera.x;
    oldCamera.y = Camera.y;

    Camera.x += x;
    Camera.y += y;

    Camera.x = Clamp(Camera.x,0,currentLevel.Length * 16 - 10 * 16);
    Camera.y = Clamp(Camera.y,0,currentLevel.Width * 16 - 9 * 16);

    if(Camera.x / 16 < oldCamera.x / 16 || Camera.x / 16 > oldCamera.x / 16)
    {
        if(x > 0)
        {
            for(int i = 0;i < 11;i++)
            {
                if(Camera.x / 16 + 11 + (Camera.y / 16 - 1 + i) * currentLevel.Length > 0 && Camera.x / 16 + 11 + (Camera.y / 16 - 1 + i) * currentLevel.Length < 6144)
                {
                    Display_Tile(Tilemap[Camera.x / 16 + 11 + (Camera.y / 16 - 1 + i) * currentLevel.Length],Camera.x / 16 * 2 + 22,Camera.y / 16 * 2 - 2 + i * 2);
                }
            }
        }else
        {
            for(int i = 0;i < 11;i++)
            {
                if(Camera.x / 16 - 1 + (Camera.y / 16 - 1 + i) * currentLevel.Length > 0 && Camera.x / 16 - 1 + (Camera.y / 16 - 1 + i) * currentLevel.Length < 6144)
                {
                    Display_Tile(Tilemap[Camera.x / 16 - 1 + (Camera.y / 16 - 1 + i) * currentLevel.Length],Camera.x / 16 * 2 - 2,Camera.y / 16 * 2 - 2 + i * 2);
                }
            }
        }
    }

    if(Camera.y / 16 < oldCamera.y / 16 || Camera.y / 16 > oldCamera.y / 16)
    {
        if(y > 0)
        {
            for(int i = 0;i < 13;i++)
            {
                if(Camera.x / 16 - 1 + i + (Camera.y / 16 + 9) * currentLevel.Length > 0 && Camera.x / 16 - 1 + i + (Camera.y / 16 + 9) * currentLevel.Length < 6144)
                {
                    Display_Tile(Tilemap[Camera.x / 16 - 1 + i + (Camera.y / 16 + 9) * currentLevel.Length],Camera.x / 16 * 2 - 2 + i * 2,Camera.y / 16 * 2 + 18);
                }
            }
        }else
        {
            for(int i = 0;i < 13;i++)
            {
                if(Camera.x / 16 - 1 + i + (Camera.y / 16 - 1) * currentLevel.Length > 0 && Camera.x / 16 - 1 + i + (Camera.y / 16 - 1) * currentLevel.Length < 6144)
                {
                    Display_Tile(Tilemap[Camera.x / 16 - 1 + i + (Camera.y / 16 - 1) * currentLevel.Length],Camera.x / 16 * 2 - 2 + i * 2,Camera.y / 16 * 2 - 2);
                }
            }
        }
    }
    vsync();
    move_bkg(Camera.x,Camera.y);

}