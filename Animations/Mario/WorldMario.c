#include "..\..\include\Animations\Mario\WorldMario.h"
#include "..\..\include\Sprite.h"
#include "..\..\include\World.h"

#pragma bank 12

extern Vector2 World_Mario_Position;

void Anim_Mario_World_Down(int animstate) BANKED
{
    switch (animstate)
    {
        case 0:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x01);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        break;
        
        case 5:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        break;

        case 10:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x01);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        break;

        case 15:
        set_sprite_tile(0,0x04);
        set_sprite_tile(1,0x05);
        set_sprite_tile(2,0x14);
        set_sprite_tile(3,0x15);
        break;
    }
}

void Anim_Mario_World_Forward(int animstate) BANKED
{
    switch (animstate)
    {
        case 0:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x01);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        break;
        
        case 5:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        break;

        case 10:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x01);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        break;

        case 15:
        set_sprite_tile(0,0x04);
        set_sprite_tile(1,0x05);
        set_sprite_tile(2,0x14);
        set_sprite_tile(3,0x15);
        break;
    }
}

void Anim_Mario_World_EnterLevel(void) BANKED
{
    set_sprite_tile(0,0x06);
    set_sprite_tile(1,0x07);
    set_sprite_tile(2,0x16);
    set_sprite_tile(3,0x17);
}