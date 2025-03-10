#include "..\..\include\Animations\Mario\WorldMario.h"
#include "..\..\include\Sprite.h"
#include "..\..\include\World.h"

#pragma bank 12

extern Vector2 World_Mario_Position;
extern Vector2 World_Mario_Dir;

void Anim_Mario_World_Idle(void)BANKED
{
    set_sprite_prop(0,0);
    set_sprite_prop(1,0);
    set_sprite_prop(2,0);
    set_sprite_prop(3,0);
    set_sprite_tile(0,0x00);
    set_sprite_tile(1,0x01);
    set_sprite_tile(2,0x10);
    set_sprite_tile(3,0x11);
    move_sprite(0,World_Mario_Position.x + 4,World_Mario_Position.y + 8);
    move_sprite(1,World_Mario_Position.x + 12,World_Mario_Position.y + 8);
    move_sprite(2,World_Mario_Position.x + 4,World_Mario_Position.y + 16);
    move_sprite(3,World_Mario_Position.x + 12,World_Mario_Position.y + 16);

}

void Anim_Mario_World_Down(int animstate) BANKED
{
    set_sprite_prop(0,0);
    set_sprite_prop(1,0);
    set_sprite_prop(2,0);
    set_sprite_prop(3,0);
    switch (animstate)
    {
        case 0:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x01);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        break;
        
        case 3:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        break;

        case 6:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x01);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        break;

        case 12:
        set_sprite_tile(0,0x04);
        set_sprite_tile(1,0x05);
        set_sprite_tile(2,0x14);
        set_sprite_tile(3,0x15);
        break;
    }

    move_sprite(0,World_Mario_Position.x + 4,World_Mario_Position.y + 8);
    move_sprite(1,World_Mario_Position.x + 12,World_Mario_Position.y + 8);
    move_sprite(2,World_Mario_Position.x + 4,World_Mario_Position.y + 16);
    move_sprite(3,World_Mario_Position.x + 12,World_Mario_Position.y + 16);
}

void Anim_Mario_World_Move(int animstate) BANKED
{
    if(World_Mario_Dir.x == 0 && World_Mario_Dir.y == 0)
    {
        Anim_Mario_World_Idle();
    }else
    {
        if(Abs(World_Mario_Dir.x) > Abs(World_Mario_Dir.y))
        {
            if(World_Mario_Dir.x > 0)
            {
                Anim_Mario_World_Right(animstate);
            }else
            {
                Anim_Mario_World_Left(animstate);
            }
    
        }else
        {
            if(World_Mario_Dir.y > 0)
            {
                Anim_Mario_World_Down(animstate);
            }else
            {
                Anim_Mario_World_Up(animstate);
            }
        }

    }

}

void Anim_Mario_World_Left(int animstate) BANKED
{
    set_sprite_prop(0,0);
    set_sprite_prop(1,0);
    set_sprite_prop(2,0);
    set_sprite_prop(3,0);

    switch (animstate)
    {
        case 0:
        set_sprite_tile(0,0x08);
        set_sprite_tile(1,0x09);
        set_sprite_tile(2,0x18);
        set_sprite_tile(3,0x19);
        break;
        
        case 3:
        set_sprite_tile(0,0x0A);
        set_sprite_tile(1,0x0B);
        set_sprite_tile(2,0x1A);
        set_sprite_tile(3,0x1B);
        break;

        case 6:
        set_sprite_tile(0,0x0C);
        set_sprite_tile(1,0x0D);
        set_sprite_tile(2,0x1C);
        set_sprite_tile(3,0x1D);
        break;

        case 12:
        set_sprite_tile(0,0x0E);
        set_sprite_tile(1,0x0F);
        set_sprite_tile(2,0x1E);
        set_sprite_tile(3,0x1F);
        break;
    }

    move_sprite(0,World_Mario_Position.x + 4,World_Mario_Position.y + 8);
    move_sprite(1,World_Mario_Position.x + 12,World_Mario_Position.y + 8);
    move_sprite(2,World_Mario_Position.x + 4,World_Mario_Position.y + 16);
    move_sprite(3,World_Mario_Position.x + 12,World_Mario_Position.y + 16);
}

void Anim_Mario_World_Right(int animstate) BANKED
{
    set_sprite_prop(0,S_FLIPX);
    set_sprite_prop(1,S_FLIPX);
    set_sprite_prop(2,S_FLIPX);
    set_sprite_prop(3,S_FLIPX);

    switch (animstate)
    {
        case 0:
        set_sprite_tile(0,0x08);
        set_sprite_tile(1,0x09);
        set_sprite_tile(2,0x18);
        set_sprite_tile(3,0x19);
        break;
        
        case 3:
        set_sprite_tile(0,0x0A);
        set_sprite_tile(1,0x0B);
        set_sprite_tile(2,0x1A);
        set_sprite_tile(3,0x1B);
        break;

        case 6:
        set_sprite_tile(0,0x0C);
        set_sprite_tile(1,0x0D);
        set_sprite_tile(2,0x1C);
        set_sprite_tile(3,0x1D);
        break;

        case 12:
        set_sprite_tile(0,0x0E);
        set_sprite_tile(1,0x0F);
        set_sprite_tile(2,0x1E);
        set_sprite_tile(3,0x1F);
        break;
    }

    move_sprite(0,World_Mario_Position.x + 12,World_Mario_Position.y + 8);
    move_sprite(1,World_Mario_Position.x + 4,World_Mario_Position.y + 8);
    move_sprite(2,World_Mario_Position.x + 12,World_Mario_Position.y + 16);
    move_sprite(3,World_Mario_Position.x + 4,World_Mario_Position.y + 16);

}

void Anim_Mario_World_Up(int animstate) BANKED
{
    set_sprite_prop(0,0);
    set_sprite_prop(1,0);
    set_sprite_prop(2,0);
    set_sprite_prop(3,0);
    switch (animstate)
    {
        case 0:
        set_sprite_tile(0,0x20);
        set_sprite_tile(1,0x21);
        set_sprite_tile(2,0x30);
        set_sprite_tile(3,0x31);
        break;
        
        case 3:
        set_sprite_tile(0,0x22);
        set_sprite_tile(1,0x23);
        set_sprite_tile(2,0x32);
        set_sprite_tile(3,0x33);
        break;

        case 6:
        set_sprite_tile(0,0x20);
        set_sprite_tile(1,0x21);
        set_sprite_tile(2,0x30);
        set_sprite_tile(3,0x31);
        break;

        case 12:
        set_sprite_tile(0,0x24);
        set_sprite_tile(1,0x25);
        set_sprite_tile(2,0x34);
        set_sprite_tile(3,0x35);
        break;
    }

    move_sprite(0,World_Mario_Position.x + 4,World_Mario_Position.y + 8);
    move_sprite(1,World_Mario_Position.x + 12,World_Mario_Position.y + 8);
    move_sprite(2,World_Mario_Position.x + 4,World_Mario_Position.y + 16);
    move_sprite(3,World_Mario_Position.x + 12,World_Mario_Position.y + 16);
}

void Anim_Mario_World_EnterLevel(void) BANKED
{
    set_sprite_prop(0,0);
    set_sprite_prop(1,0);
    set_sprite_prop(2,0);
    set_sprite_prop(3,0);
    set_sprite_tile(0,0x06);
    set_sprite_tile(1,0x07);
    set_sprite_tile(2,0x16);
    set_sprite_tile(3,0x17);
    move_sprite(0,World_Mario_Position.x + 4,World_Mario_Position.y + 8);
    move_sprite(1,World_Mario_Position.x + 12,World_Mario_Position.y + 8);
    move_sprite(2,World_Mario_Position.x + 4,World_Mario_Position.y + 16);
    move_sprite(3,World_Mario_Position.x + 12,World_Mario_Position.y + 16);

}