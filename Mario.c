#include "include\Mathf.h"
#include "include\Mario.h"
#include "include\Camera.h"

#include "Sprites\Mario.h"

#include <gb\gb.h>
#include <stdlib.h>

Vector2 position = {.x=0,.y=0};
Vector2 velocity = {.x=0,.y=0};

Collision hitbox = {.size={.x=2,.y=3},.offset={.x=-1,.y=-2},.pixeloffset={.x=6,.y=6},.pixelsize={.x=5,.y=6}};

int Transformation = 0;

int dir = 0;

int Started = 0;
char onGround = 0;

void Start_Mario(void)
{
    set_sprite_data(0,1,null);
    set_sprite_data(1,6,Small_Idle);
}

void Update_Mario(void)
{
    if(Started == 0)
    {
        Start_Mario();
    }
    dir = joypad() == J_LEFT ? 1 : joypad() == J_RIGHT ? 0 : dir;
    
    switch(joypad())
    {
        case J_RIGHT:
        case J_RIGHT+J_B:
        case J_RIGHT+J_A:
        velocity.x += 2;
        break;

        case J_LEFT:
        case J_LEFT+J_B:
        case J_LEFT+J_A:
        velocity.x -= 2;
        break;
    }

    Idle();



    velocity.x -= Sign(velocity.x);
    velocity.y += 1;
    velocity.x = Clamp(velocity.x,TileMapCollisionSide(GetMarioCollision(),&velocity,2) == 1 ? 0 : -5,TileMapCollisionSide(GetMarioCollision(),&velocity,3) == 1 ? 0 : 5);
    velocity.y = Clamp(velocity.y,TileMapCollisionSide(GetMarioCollision(),&velocity,1) == 1 ? 0 : -5,TileMapCollisionSide(GetMarioCollision(),&velocity,0) == 1 ? 0 : 5);

    Vector2 dir = {.x=0,.y=1};
    if(Raycast(position,dir,velocity,2,8) == 1)
    {
        switch(joypad())
        {
            case J_A:
            case J_A + J_B:
            case J_A + J_RIGHT:
            case J_A + J_LEFT:
            case J_A + J_DOWN:
            case J_A + J_UP:
            velocity.y = -10;
            break;

        }
    }

    position.x += velocity.x;
    position.y += velocity.y;

    Vector2 camera;
    camera = GetCamera();
    MoveCamera(position.x - (camera.x + 88),position.y - (camera.y + 80));
    DisplayMario();

}

void Idle(void)
{
    switch(Transformation)
    {
        case 0:
        set_sprite_tile(0,0);
        set_sprite_tile(1,0);
        set_sprite_tile(2,1);
        set_sprite_tile(3,2);
        set_sprite_tile(4,0);
        set_sprite_tile(5,3);
        set_sprite_tile(6,4);
        set_sprite_tile(7,0);
        set_sprite_tile(8,5);
        set_sprite_tile(9,6);
        break;

        case 1:
        set_sprite_tile(0,0);
        set_sprite_tile(1,0);
        set_sprite_tile(2,1);
        set_sprite_tile(3,2);
        set_sprite_tile(4,0);
        set_sprite_tile(5,3);
        set_sprite_tile(6,4);
        set_sprite_tile(7,0);
        set_sprite_tile(8,5);
        set_sprite_tile(9,6);
        break;
    }
}

void DisplayMario(void)
{
    Vector2 cam ;
    cam = GetCamera();
    switch (dir)
    {
        case 0:
        for(int i = 0; i < 10; i++)
        {
            set_sprite_prop(i,0);
        }
        move_sprite(0,-(cam.x - position.x),-(cam.y - position.y) - 8);
        move_sprite(1,-(cam.x - position.x)+8,-(cam.y - position.y) - 8);
        move_sprite(2,-(cam.x - position.x),-(cam.y - position.y));
        move_sprite(3,-(cam.x - position.x)+8,-(cam.y - position.y));
        move_sprite(4,-(cam.x - position.x)-8,-(cam.y - position.y) + 8);
        move_sprite(5,-(cam.x - position.x),-(cam.y - position.y) + 8);
        move_sprite(6,-(cam.x - position.x)+8,-(cam.y - position.y) + 8);
        move_sprite(7,-(cam.x - position.x)-8,-(cam.y - position.y) + 16);
        move_sprite(8,-(cam.x - position.x),-(cam.y - position.y) + 16);
        move_sprite(9,-(cam.x - position.x)+8,-(cam.y - position.y) + 16);
        break;
    
        case 1:
        for(int i = 0; i < 10; i++)
        {
            set_sprite_prop(i,S_FLIPX);
        }
        move_sprite(0,-(cam.x - position.x)+8,-(cam.y - position.y) - 8);
        move_sprite(1,-(cam.x - position.x),-(cam.y - position.y) - 8);
        move_sprite(2,-(cam.x - position.x)+8,-(cam.y - position.y));
        move_sprite(3,-(cam.x - position.x),-(cam.y - position.y));
        move_sprite(4,-(cam.x - position.x)+16,-(cam.y - position.y) + 8);
        move_sprite(5,-(cam.x - position.x)+8,-(cam.y - position.y) + 8);
        move_sprite(6,-(cam.x - position.x),-(cam.y - position.y) + 8);
        move_sprite(7,-(cam.x - position.x)+16,-(cam.y - position.y) + 16);
        move_sprite(8,-(cam.x - position.x)+8,-(cam.y - position.y) + 16);
        move_sprite(9,-(cam.x - position.x),-(cam.y - position.y) + 16);
        break;
    }
}


Collision GetMarioCollision(void)
{
    hitbox.position = position;
    return hitbox;
}