#include <gb\gb.h>
#include "..\..\include\Camera.h"
#include "..\..\include\collision.h"
#include "..\..\include\Animations\Mario\Mario.h"
#include "..\..\include\Animations\Mario\SmallMario.h"
#include "..\..\include\Animations\Mario\GreatMario.h"
#include "..\..\include\Animations\Mario\FireMario.h"

#pragma bank 10

void Anim_Mario_Idle(int Transformation) BANKED
{
    switch(Transformation)
    {
        case 0:
        Anim_Mario_Small_Idle();
        break;

        case 1:
        Anim_Mario_Great_Idle();
        break;

        case 2:
        Anim_Mario_Fire_Idle();
        break;
    }
}

void Anim_Mario_Fall(int Transformation) BANKED
{
    switch (Transformation)
    {
        case 0:
        Anim_Mario_Small_Fall();
        break;
    
        case 1:
        Anim_Mario_Great_Fall();
        break;

        case 2:
        Anim_Mario_Fire_Fall();
        break;
    }
}

void Anim_Mario_Jump(int Transformation) BANKED
{
    switch (Transformation)
    {
        case 0:
        Anim_Mario_Small_Jump();
        break;
    
        case 1:
        Anim_Mario_Great_Jump();
        break;

        case 2:
        Anim_Mario_Fire_Jump();
        break;
    }
}

void Anim_Mario_Move(int Transformation,int animstate) BANKED
{
    switch(Transformation)
    {
        case 0:
        Anim_Mario_Small_Move(animstate);
        break;

        case 1:
        Anim_Mario_Great_Move(animstate);
        break;

        case 2: 
        Anim_Mario_Fire_Move(animstate);
        break;
    }
}

void Anim_Mario_Slide(int Transformation) BANKED
{
    switch(Transformation)
    {
        case 0:
        Anim_Mario_Small_Slide();
        break;

        case 1:
        Anim_Mario_Great_Slide();
        break;

        case 2:
        Anim_Mario_Fire_Slide();
        break;
    }
}

void Anim_Mario_Death(Collision hitbox) BANKED
{
    Vector2 camera;
    camera = GetCamera();

    set_sprite_tile(0,0x00);
    set_sprite_tile(1,0x00);
    set_sprite_tile(2,0x26);
    set_sprite_tile(3,0x26);
    set_sprite_tile(4,0x00);
    set_sprite_tile(5,0x27);
    set_sprite_tile(6,0x27);
    set_sprite_tile(7,0x00);
    set_sprite_tile(8,0x28);
    set_sprite_tile(9,0x28);

    set_sprite_prop(3,S_FLIPX);
    set_sprite_prop(6,S_FLIPX);
    set_sprite_prop(9,S_FLIPX);

    move_sprite(0,-(camera.x - hitbox.position.x),-(camera.y - hitbox.position.y) - 8);
    move_sprite(1,-(camera.x - hitbox.position.x)+8,-(camera.y - hitbox.position.y) - 8);
    move_sprite(2,-(camera.x - hitbox.position.x),-(camera.y - hitbox.position.y));
    move_sprite(3,-(camera.x - hitbox.position.x)+8,-(camera.y - hitbox.position.y));
    move_sprite(4,-(camera.x - hitbox.position.x)-8,-(camera.y - hitbox.position.y) + 8);
    move_sprite(5,-(camera.x - hitbox.position.x),-(camera.y - hitbox.position.y) + 8);
    move_sprite(6,-(camera.x - hitbox.position.x)+8,-(camera.y - hitbox.position.y) + 8);
    move_sprite(7,-(camera.x - hitbox.position.x)-8,-(camera.y - hitbox.position.y) + 16);
    move_sprite(8,-(camera.x - hitbox.position.x),-(camera.y - hitbox.position.y) + 16);
    move_sprite(9,-(camera.x - hitbox.position.x)+8,-(camera.y - hitbox.position.y) + 16);
}
