#include "..\include\Mathf.h"
#include "..\include\Mario.h"
#include "..\include\Camera.h"
#include "..\include\GameSystem.h"
#include "..\include\Physic.h" 
#include "..\include\Sprite.h"
#include "..\include\Objects.h"
#include "..\include\Animations\Mario.h"

#include <gb\gb.h>
#include <stdlib.h>

Vector2 velocity = {.x=0,.y=0};

Collision hitbox = {.position={.x=128,.y=128},.pixeloffset={.x=-6,.y=-14},.pixelsize={.x=10,.y=18}};

int Transformation = 0;

int maxSpeed;

int orientation = 0;

char onGround = 0;

int animState = 0;

void Update_Mario(void)
{
    orientation = GetButtonDown(J_LEFT) ? 1 : GetButtonDown(J_RIGHT) ? 0 : orientation;
    
    maxSpeed = GetButtonDown(J_B) ? 7 : 5;
    
    velocity.x += GetButtonDown(J_RIGHT) ? 2 : GetButtonDown(J_LEFT) == 1 ? -2 : 0;

    velocity.x -= Sign(velocity.x);
    velocity.y += 1;

    Vector2 dir = {.x=0,.y=1};
    Vector2 v = {.x= hitbox.position.x + hitbox.pixeloffset.x + 2,.y=hitbox.position.y};
    Vector2 w = {.x= hitbox.position.x + hitbox.pixeloffset.x + hitbox.pixelsize.x - 2,.y=hitbox.position.y};
    onGround = (Raycast(v,dir,5) || Raycast(w,dir,5));

    if(onGround == 0)
    {
        velocity.y += !GetButtonDown(J_A) * 2;
        if(velocity.y >= 1)
        {
            Anim_Mario_Fall();
        }else
        {
            Anim_Mario_Jump();
        }

    }else
    {
        if(abs(velocity.x) >= 1)
        {
            if((velocity.x < 0 && orientation == 0) || (velocity.x > 0 && orientation == 1))
            {
                Anim_Mario_Slide();
                animState = 0;
            }else
            {
                Anim_Mario_Move(animState);
                animState++;
                animState = animState >= 6 ? 0 : animState;
            }
        }else
        {
            Anim_Mario_Idle(Transformation);
        }

        velocity.y = GetButtonDown(J_A) ? -10 : velocity.y;
    }


    ApplyPhysics(&hitbox,&velocity);
    Get_TileObject();
    
    velocity.y = Clamp(velocity.y,-10,5);
    velocity.x = Clamp(velocity.x,-5,5);

    hitbox.position.x += velocity.x;
    hitbox.position.y += velocity.y;

    ApplyPhysics(&hitbox,&velocity);


    Vector2 camera;
    camera = GetCamera();
    MoveCamera(hitbox.position.x - (camera.x + 88),hitbox.position.y - (camera.y + 80));
    DisplayMario();

}

void Get_TileObject(void)
{
    
    for(int i = 0; i <= 1; i++)
    {
        char c = Get_Tile((hitbox.position.x + hitbox.pixeloffset.x + i * hitbox.pixelsize.x),(hitbox.position.y + hitbox.pixeloffset.y - 5));
        switch (c)
        {
            case 1:
            Use_Coin((hitbox.position.x + hitbox.pixeloffset.x + i * hitbox.pixelsize.x),(hitbox.position.y + hitbox.pixeloffset.y - 5));
            break;

            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            if(velocity.y < 0)
            {
                Q_Block(c,hitbox.position.x + hitbox.pixeloffset.x + i * hitbox.pixelsize.x,hitbox.position.y + hitbox.pixeloffset.y - 5);
            }
            break;
        }  
    }
    
   
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
        move_sprite(0,-(cam.x - hitbox.position.x),-(cam.y - hitbox.position.y) - 8);
        move_sprite(1,-(cam.x - hitbox.position.x)+8,-(cam.y - hitbox.position.y) - 8);
        move_sprite(2,-(cam.x - hitbox.position.x),-(cam.y - hitbox.position.y));
        move_sprite(3,-(cam.x - hitbox.position.x)+8,-(cam.y - hitbox.position.y));
        move_sprite(4,-(cam.x - hitbox.position.x)-8,-(cam.y - hitbox.position.y) + 8);
        move_sprite(5,-(cam.x - hitbox.position.x),-(cam.y - hitbox.position.y) + 8);
        move_sprite(6,-(cam.x - hitbox.position.x)+8,-(cam.y - hitbox.position.y) + 8);
        move_sprite(7,-(cam.x - hitbox.position.x)-8,-(cam.y - hitbox.position.y) + 16);
        move_sprite(8,-(cam.x - hitbox.position.x),-(cam.y - hitbox.position.y) + 16);
        move_sprite(9,-(cam.x - hitbox.position.x)+8,-(cam.y - hitbox.position.y) + 16);
        break;
    
        case 1:
        for(int i = 0; i < 10; i++)
        {
            set_sprite_prop(i,S_FLIPX);
        }
        move_sprite(0,-(cam.x - hitbox.position.x)+8,-(cam.y - hitbox.position.y) - 8);
        move_sprite(1,-(cam.x - hitbox.position.x),-(cam.y - hitbox.position.y) - 8);
        move_sprite(2,-(cam.x - hitbox.position.x)+8,-(cam.y - hitbox.position.y));
        move_sprite(3,-(cam.x - hitbox.position.x),-(cam.y - hitbox.position.y));
        move_sprite(4,-(cam.x - hitbox.position.x)+16,-(cam.y - hitbox.position.y) + 8);
        move_sprite(5,-(cam.x - hitbox.position.x)+8,-(cam.y - hitbox.position.y) + 8);
        move_sprite(6,-(cam.x - hitbox.position.x),-(cam.y - hitbox.position.y) + 8);
        move_sprite(7,-(cam.x - hitbox.position.x)+16,-(cam.y - hitbox.position.y) + 16);
        move_sprite(8,-(cam.x - hitbox.position.x)+8,-(cam.y - hitbox.position.y) + 16);
        move_sprite(9,-(cam.x - hitbox.position.x),-(cam.y - hitbox.position.y) + 16);
        break;
    }
}

void Set_Mario_Position(int x,int y)
{
    hitbox.position.x = x;
    hitbox.position.y = y;
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
    return hitbox;
}