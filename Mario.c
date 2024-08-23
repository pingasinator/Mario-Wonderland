#include "include\Mathf.h"
#include "include\Mario.h"
#include "include\Camera.h"
#include "include\GameSystem.h"

#include "Sprites\Mario.h"

#include <gb\gb.h>
#include <stdlib.h>

Vector2 position = {.x=0,.y=0};
Vector2 velocity = {.x=0,.y=0};

Collision hitbox = {.pixeloffset={.x=-8,.y=-18},.pixelsize={.x=14,.y=24}};

int Transformation = 0;

int maxSpeed;

int orientation = 0;

int Started = 0;
char onGround = 0;

int animState = 0;

void Start_Mario(void)
{
    set_sprite_data(0,1,null);
    set_sprite_data(1,6,Small_Idle);
    set_sprite_data(7,4,Small_Move_0);
    set_sprite_data(11,4,Small_Move_1);
    set_sprite_data(15,4,Small_Move_2);
    set_sprite_data(19,6,Small_Jump);
    set_sprite_data(25,1,Small_Fall);
    set_sprite_data(26,5,Small_Slide);
}

void Update_Mario(void)
{
    if(Started == 0)
    {
        Start_Mario();
    }
    orientation = GetButtonDown(J_LEFT) ? 1 : GetButtonDown(J_RIGHT) ? 0 : orientation;
    
    maxSpeed = GetButtonDown(J_B) ? 7 : 5;
    
    velocity.x += GetButtonDown(J_RIGHT) ? 2 : GetButtonDown(J_LEFT) == 1 ? -2 : 0;

    velocity.x -= Sign(velocity.x);
    velocity.y += 1;
    velocity.x = Clamp(velocity.x,TileMapCollisionSide(GetMarioCollision(),&velocity,2) == 1 ? 0 : -maxSpeed,TileMapCollisionSide(GetMarioCollision(),&velocity,3) == 1 ? 0 : maxSpeed);
    velocity.y = Clamp(velocity.y,TileMapCollisionSide(GetMarioCollision(),&velocity,1) == 1 ? 0 : -7,TileMapCollisionSide(GetMarioCollision(),&velocity,0) == 1 ? 0 : 5);
    
    Vector2 dir = {.x=0,.y=1};
    onGround = Raycast(position,dir,velocity,8);

    if(onGround == 0)
    {
        if(velocity.y >= 1)
        {
            Mario_Fall();
        }else
        {
            Mario_Jump();
        }

    }else
    {
        if(abs(velocity.x) >= 1)
        {
            if((velocity.x < 0 && orientation == 0) || (velocity.x > 0 && orientation == 1))
            {
                Mario_Slide();
            }else
            {
                Mario_Move();
            }
        }else
        {
            Mario_Idle();
        }

        velocity.y = GetButtonDown(J_A) ? -10 : velocity.y;
    }

    position.x += velocity.x;
    position.y += velocity.y;

    Vector2 camera;
    camera = GetCamera();
    MoveCamera(position.x - (camera.x + 88),position.y - (camera.y + 80));
    DisplayMario();

}

void Mario_Idle(void)
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

void Mario_Move(void)
{
    switch(animState)
    {
        case 0:
        set_sprite_tile(0,0);
        set_sprite_tile(1,0);
        set_sprite_tile(2,1);
        set_sprite_tile(3,2);
        set_sprite_tile(4,0);
        set_sprite_tile(5,7);
        set_sprite_tile(6,8);
        set_sprite_tile(7,0);
        set_sprite_tile(8,9);
        set_sprite_tile(9,10);
        break;

        case 2:
        set_sprite_tile(0,0);
        set_sprite_tile(1,0);
        set_sprite_tile(2,1);
        set_sprite_tile(3,2);
        set_sprite_tile(4,0);
        set_sprite_tile(5,11);
        set_sprite_tile(6,12);
        set_sprite_tile(7,0);
        set_sprite_tile(8,13);
        set_sprite_tile(9,14);
        break;

        case 4:
        set_sprite_tile(0,0);
        set_sprite_tile(1,0);
        set_sprite_tile(2,1);
        set_sprite_tile(3,2);
        set_sprite_tile(4,0);
        set_sprite_tile(5,15);
        set_sprite_tile(6,16);
        set_sprite_tile(7,0);
        set_sprite_tile(8,17);
        set_sprite_tile(9,18);
        break;
    }


    animState++;
    animState = animState >= 6 ? 0 : animState;
}

void Mario_Fall(void)
{
    animState = 0;

    set_sprite_tile(0,0);
    set_sprite_tile(1,0);
    set_sprite_tile(2,19);
    set_sprite_tile(3,2);
    set_sprite_tile(4,0);
    set_sprite_tile(5,21);
    set_sprite_tile(6,25);
    set_sprite_tile(7,0);
    set_sprite_tile(8,23);
    set_sprite_tile(9,24);
}

void Mario_Jump(void)
{
    animState = 0;
    set_sprite_tile(0,0);
    set_sprite_tile(1,0);
    set_sprite_tile(2,19);
    set_sprite_tile(3,20);
    set_sprite_tile(4,0);
    set_sprite_tile(5,21);
    set_sprite_tile(6,22);
    set_sprite_tile(7,0);
    set_sprite_tile(8,23);
    set_sprite_tile(9,24);
}

void Mario_Slide(void)
{
    animState = 0;
    set_sprite_tile(0,0);
    set_sprite_tile(1,0);
    set_sprite_tile(2,1);
    set_sprite_tile(3,2);
    set_sprite_tile(4,0);
    set_sprite_tile(5,26);
    set_sprite_tile(6,27);
    set_sprite_tile(7,30);
    set_sprite_tile(8,28);
    set_sprite_tile(9,29);
}

void DisplayMario(void)
{
    Vector2 cam ;
    cam = GetCamera();
    switch (orientation)
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

void Set_Mario_Position(int x,int y)
{
    position.x = x;
    position.y = y;
}

Vector2 Get_Mario_Velocity(void)
{
    return velocity;
}

Vector2 *Get_Mario_Velocity_ptr(void)
{
    return &velocity;
}
void Set_Mario_Velocity(int x,int y)
{
    velocity.x = x;
    velocity.y = y;
}

Collision GetMarioCollision(void)
{
    hitbox.position = position;
    return hitbox;
}