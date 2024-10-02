#include "..\..\include\Animations\Mario\SmallMario.h"

#pragma bank 13

void Anim_Mario_Small_Idle(void) BANKED
{
    set_sprite_tile(0,0x00);
    set_sprite_tile(1,0x00);
    set_sprite_tile(2,0x00);
    set_sprite_tile(3,0x00);
    set_sprite_tile(4,0x00);
    set_sprite_tile(5,0x01);
    set_sprite_tile(6,0x02);
    set_sprite_tile(7,0x00);
    set_sprite_tile(8,0x03);
    set_sprite_tile(9,0x04);
}

void Anim_Mario_Small_Slide(void) BANKED
{
    set_sprite_tile(0,0);
    set_sprite_tile(1,0);
    set_sprite_tile(2,0x01);
    set_sprite_tile(3,0x02);
    set_sprite_tile(4,0);
    set_sprite_tile(5,0x1A);
    set_sprite_tile(6,0x1B);
    set_sprite_tile(7,0x1E);
    set_sprite_tile(8,0x1C);
    set_sprite_tile(9,0x1D);
}

void Anim_Mario_Small_Fall(void) BANKED
{
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

void Anim_Mario_Small_Move(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x00);
        set_sprite_tile(3,0x00);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x05);
        set_sprite_tile(6,0x06);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x07);
        set_sprite_tile(9,0x08);
        break;

        case 2:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x00);
        set_sprite_tile(3,0x00);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x01);
        set_sprite_tile(6,0x02);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x03);
        set_sprite_tile(9,0x04);
        break;

        case 4:
        set_sprite_tile(0,0);
        set_sprite_tile(1,0);
        set_sprite_tile(2,0);
        set_sprite_tile(3,0);
        set_sprite_tile(4,0);
        set_sprite_tile(5,0x05);
        set_sprite_tile(6,0x06);
        set_sprite_tile(7,0);
        set_sprite_tile(8,0x07);
        set_sprite_tile(9,0x08);
        break;
    }
}

void Anim_Mario_Small_Jump(void) BANKED
{
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