#include "include\Camera.h"
#include "include\Level.h"
#include <gb\gb.h>

Vector2 Camera = {.x=0,.y=0};

Vector2 GetCamera(void)
{
    return Camera;
}

void MoveCamera(int x,int y)
{
    Camera.x += x;
    Camera.y += y;

    Screen *level = GetCurrentLevel();
    Screen s;

    for(int i = 0; i < 2;i++)
    {
        if(level[i].position.x == (Camera.x + 8) / 8 / 32 && level[i].position.y == (Camera.y + 8) / 8 / 32)
        {
            s = level[i];
            break;
        }
    }

    Camera.x = s.MinBounds.x == 1 && Camera.x < s.position.x * 8 * 32? s.position.x * 8 *32 : Camera.x + 20 * 8 > (s.position.x + 1) * 8 * 32 && s.MaxBounds.x == 1 ? (s.position.x + 1) * 8 * 32 - 20 * 8 : Camera.x;
    Camera.y = s.MinBounds.y == 1 && Camera.y < s.position.y * 8 * 32? s.position.y * 8 *32 : Camera.y + 18 * 8 > (s.position.y + 1) * 8 * 32 && s.MaxBounds.y == 1 ? (s.position.y + 1) * 8 * 32 - 18 * 8 : Camera.y;
    move_bkg(Camera.x,Camera.y);
}