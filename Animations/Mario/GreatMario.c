#include "..\..\include\Animations\Mario\GreatMario.h"

#pragma bank 11

void Anim_Mario_Great_Idle(void) BANKED
{
    set_sprite_tile(0,0X34);
    set_sprite_tile(1,0X35);
    set_sprite_tile(2,0X36);
    set_sprite_tile(3,0X37);
    set_sprite_tile(4,0);
    set_sprite_tile(5,0X38);
    set_sprite_tile(6,0X39);
    set_sprite_tile(7,0);
    set_sprite_tile(8,0X3A);
    set_sprite_tile(9,0X3B);
}

void Anim_Mario_Great_Fall(void) BANKED
{
    set_sprite_tile(0,0x34);
    set_sprite_tile(1,0x35);
    set_sprite_tile(2,0x36);
    set_sprite_tile(3,0x37);
    set_sprite_tile(4,0);
    set_sprite_tile(5,0x4E);
    set_sprite_tile(6,0x39);
    set_sprite_tile(7,0);
    set_sprite_tile(8,0x4B);
    set_sprite_tile(9,0x4C);
}

void Anim_Mario_Great_Move(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        set_sprite_tile(0,0x34);
        set_sprite_tile(1,0x35);
        set_sprite_tile(2,0x36);
        set_sprite_tile(3,0x37);
        set_sprite_tile(4,0);
        set_sprite_tile(5,0x38);
        set_sprite_tile(6,0x39);
        set_sprite_tile(7,0);
        set_sprite_tile(8,0x3C);
        set_sprite_tile(9,0x3D);
        break;

        case 2:
        set_sprite_tile(0,0x34);
        set_sprite_tile(1,0x35);
        set_sprite_tile(2,0x36);
        set_sprite_tile(3,0x37);
        set_sprite_tile(4,0);
        set_sprite_tile(5,0x3E);
        set_sprite_tile(6,0x3F);
        set_sprite_tile(7,0);
        set_sprite_tile(8,0x40);
        set_sprite_tile(9,0x41);
        break;

        case 4:
        set_sprite_tile(0,0x34);
        set_sprite_tile(1,0x35);
        set_sprite_tile(2,0x36);
        set_sprite_tile(3,0x37);
        set_sprite_tile(4,0);
        set_sprite_tile(5,0x42);
        set_sprite_tile(6,0x43);
        set_sprite_tile(7,0);
        set_sprite_tile(8,0x44);
        set_sprite_tile(9,0x45);
        break;
    }
}

void Anim_Mario_Great_Jump(void) BANKED
{
    set_sprite_tile(0,0x34);
    set_sprite_tile(1,0x46);
    set_sprite_tile(2,0x47);
    set_sprite_tile(3,0x48);
    set_sprite_tile(4,0x4D);
    set_sprite_tile(5,0x49);
    set_sprite_tile(6,0x4A);
    set_sprite_tile(7,0);
    set_sprite_tile(8,0x4B);
    set_sprite_tile(9,0x4C);
}

void Anim_Mario_Great_Slide(void) BANKED
{
    set_sprite_tile(0,0x4F);
    set_sprite_tile(1,0x50);
    set_sprite_tile(2,0x51);
    set_sprite_tile(3,0x52);
    set_sprite_tile(4,0);
    set_sprite_tile(5,0x53);
    set_sprite_tile(6,0x54);
    set_sprite_tile(7,0x1E);
    set_sprite_tile(8,0x55);
    set_sprite_tile(9,0x56);
}
