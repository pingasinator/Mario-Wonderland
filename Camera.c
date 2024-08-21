#include "include\Camera.h"
#include "include\Level.h"
#include "include\Sprite.h"
#include <gb\gb.h>

Vector2 Camera = {.x=0,.y=0};

Vector2 GetCamera(void)
{
    return Camera;
}

void Update_Camera(void)
{
    char *Tilemap = Get_Tilemap();
        for(int i = 0;i < 11;i++)
        {
            Set_Sprite_Tile(Tilemap[Camera.x / 16 - 1 + (Camera.y / 16 - 1 + i) * 128],Camera.x / 16 * 2 - 2,Camera.y / 16 * 2 - 2 + i * 2);
            Set_Sprite_Tile(Tilemap[Camera.x / 16 - 1 + i + (Camera.y / 16 - 1) * 128],Camera.x / 16 * 2 - 2 + i * 2,Camera.y / 16 * 2 - 2);
            Set_Sprite_Tile(Tilemap[Camera.x / 16 + 10 + (Camera.y / 16 - 1 + i) * 128],Camera.x / 16 * 2 + 20,Camera.y / 16 * 2 - 2 + i * 2);
            Set_Sprite_Tile(Tilemap[Camera.x / 16 - 1 + i + (Camera.y / 16 + 9) * 128],Camera.x / 16 * 2 - 2 + i * 2,Camera.y / 16 * 2 + 18);
        }
    

    move_bkg(Camera.x,Camera.y);
}

void MoveCamera(int x,int y)
{
    Camera.x += x;
    Camera.y += y;

    Camera.x = Clamp(Camera.x,0,128 * 16 - 10 * 16);
    Camera.y = Clamp(Camera.y,0,32 * 16 - 9 * 16);
    move_bkg(Camera.x,Camera.y);
}