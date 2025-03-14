#include <gb\gb.h>
#include "..\..\include\Sprite.h"
#include "..\..\include\Camera.h"
#include "..\..\include\collision.h"
#include "..\..\include\Animations\Mario\Mario.h"
#include "..\..\include\Animations\Mario\SmallMario.h"
#include "..\..\include\Animations\Mario\GreatMario.h"
#include "..\..\include\Animations\Mario\FireMario.h"
#include "..\..\include\Animations\Mario\RacoonMario.h"

extern Vector2 Camera;
extern int Time;
int animstate_Star;
extern unsigned char currentMarioPalette;

#pragma bank 12

void Anim_Mario_Idle(int Transformation) NONBANKED
{
    if(currentMarioPalette != Transformation)
    {
        Set_Mario_Palette(Transformation);
        SWITCH_ROM(10);
    }

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

        case 3:
        Anim_Mario_Racoon_Idle();
        break;
    }


}

void Anim_Mario_Fall(int Transformation) NONBANKED
{
    if(currentMarioPalette != Transformation)
    {
        Set_Mario_Palette(Transformation);
        SWITCH_ROM(10);
    }

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

        case 3:
        Anim_Mario_Racoon_Fall();
        break;
    }


}

void Anim_Mario_Jump(int Transformation) NONBANKED
{
    if(currentMarioPalette != Transformation)
    {
        Set_Mario_Palette(Transformation);
        SWITCH_ROM(10);
    }

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

        case 3:
        Anim_Mario_Racoon_Jump();
        break;
    }
}

void Anim_Mario_Jump_Run(int Transformation) NONBANKED
{
    if(currentMarioPalette != Transformation)
    {
        Set_Mario_Palette(Transformation);
        SWITCH_ROM(10);
    }

    switch (Transformation)
    {
        case 0:
        Anim_Mario_Small_Jump_Run();
        break;

        case 1:
        Anim_Mario_Great_Jump_Run();
        break;
    }
}

void Anim_Mario_Move(int Transformation,int animstate) NONBANKED
{
    if(currentMarioPalette != Transformation)
    {
        Set_Mario_Palette(Transformation);
        SWITCH_ROM(10);
    }

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

        case 3:
        Anim_Mario_Racoon_Move(animstate);
        break;
    }
}

void Anim_Mario_Run(int Transformation,int animstate) NONBANKED
{
    if(currentMarioPalette != Transformation)
    {
        Set_Mario_Palette(Transformation);
        SWITCH_ROM(10);
    }

    switch (Transformation)
    {
        case 0:
        Anim_Mario_Small_Run(animstate);
        break;

        case 1:
        Anim_Mario_Great_Run(animstate);
        break;
    }
}

void Anim_Mario_Slide(int Transformation) NONBANKED
{
    if(currentMarioPalette != Transformation)
    {
        Set_Mario_Palette(Transformation);
        SWITCH_ROM(10);
    }

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

void Anim_Mario_Death(Collision hitbox) NONBANKED
{
    if(currentMarioPalette != 0)
    {
        Set_Mario_Palette(0);
    }

    set_sprite_tile(0,0x00);
    set_sprite_tile(1,0x00);
    set_sprite_tile(2,0x3E);
    set_sprite_tile(3,0x3F);
    set_sprite_tile(4,0x00);
    set_sprite_tile(5,0x4E);
    set_sprite_tile(6,0x4F);
    set_sprite_tile(7,0x00);
    set_sprite_tile(8,0x5E);
    set_sprite_tile(9,0x5F);

    set_sprite_prop(2,0x00);
    set_sprite_prop(3,0x00);
    set_sprite_prop(4,0x00);
    set_sprite_prop(5,0x00);
    set_sprite_prop(6,0x00);
    set_sprite_prop(7,0x00);
    set_sprite_prop(8,0x00);
    set_sprite_prop(9,0x00);


    move_sprite(0,-(Camera.x - hitbox.position.x),-(Camera.y - hitbox.position.y) - 16);
    move_sprite(1,-(Camera.x - hitbox.position.x)+8,-(Camera.y - hitbox.position.y) - 16);
    move_sprite(2,-(Camera.x - hitbox.position.x),-(Camera.y - hitbox.position.y)- 8);
    move_sprite(3,-(Camera.x - hitbox.position.x)+8,-(Camera.y - hitbox.position.y)- 8);
    move_sprite(4,-(Camera.x - hitbox.position.x)-8,-(Camera.y - hitbox.position.y));
    move_sprite(5,-(Camera.x - hitbox.position.x),-(Camera.y - hitbox.position.y));
    move_sprite(6,-(Camera.x - hitbox.position.x)+8,-(Camera.y - hitbox.position.y));
    move_sprite(7,-(Camera.x - hitbox.position.x)-8,-(Camera.y - hitbox.position.y) + 8);
    move_sprite(8,-(Camera.x - hitbox.position.x),-(Camera.y - hitbox.position.y) + 8);
    move_sprite(9,-(Camera.x - hitbox.position.x)+8,-(Camera.y - hitbox.position.y) + 8);

    SWITCH_ROM(10);
}

void Anim_Mario_Win(int Transformation,int animstate) NONBANKED
{
    
    if(currentMarioPalette != Transformation)
    {
        Set_Mario_Palette(Transformation);
        SWITCH_ROM(10);
    }

    switch (Transformation)
    {
        case 0:
        Anim_Mario_Small_Win(animstate);
        break;

        case 1:
        Anim_Mario_Great_Win(animstate);
        break;

        case 2:
        Anim_Mario_Racoon_Win(animstate);
        break;
    }
}

void Anim_Mario_Star(void) NONBANKED
{


    switch (animstate_Star)
    {
        case 0:
        for(int i = 0; i < 10;i++)
        {
            set_sprite_prop(i,S_PALETTE);
        }
        break;
    
        case 10:
        for(int i = 0; i < 10;i++)
        {
            set_sprite_prop(i,S_PALETTE);
        }
        break;
    }
    animstate_Star += Time;
    animstate_Star = animstate_Star >= 20 ? 0 : animstate_Star;
}