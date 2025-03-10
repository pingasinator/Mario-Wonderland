#include "..\..\include\Animations\Mario\SmallMario.h"

#pragma bank 12

extern int EndofLevel;

void Anim_Mario_Small_Idle(void) BANKED
{
    set_sprite_tile(0,0x00);
    set_sprite_tile(1,0x00);
    set_sprite_tile(2,0x02);
    set_sprite_tile(3,0x03);
    set_sprite_tile(4,0x00);
    set_sprite_tile(5,0x10);
    set_sprite_tile(6,0x11);
    set_sprite_tile(7,0x00);
    set_sprite_tile(8,0x20);
    set_sprite_tile(9,0x21);
}

void Anim_Mario_Small_Slide(void) BANKED
{
    set_sprite_tile(0,0x00);
    set_sprite_tile(1,0x00);
    set_sprite_tile(2,0x0C);
    set_sprite_tile(3,0x0D);
    set_sprite_tile(4,0x00);
    set_sprite_tile(5,0x1C);
    set_sprite_tile(6,0x1D);
    set_sprite_tile(7,0x72);
    set_sprite_tile(8,0x2C);
    set_sprite_tile(9,0x2D);
}

void Anim_Mario_Small_Fall(void) BANKED
{
    set_sprite_tile(0,0x00);
    set_sprite_tile(1,0x00);
    set_sprite_tile(2,0x0A);
    set_sprite_tile(3,0x0B);
    set_sprite_tile(4,0x00);
    set_sprite_tile(5,0x1A);
    set_sprite_tile(6,0x1B);
    set_sprite_tile(7,0x00);
    set_sprite_tile(8,0x2A);
    set_sprite_tile(9,0x2B);
}

void Anim_Mario_Small_Move(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x02);
        set_sprite_tile(3,0x03);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x12);
        set_sprite_tile(6,0x13);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x22);
        set_sprite_tile(9,0x23);
        break;

        case 2:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x02);
        set_sprite_tile(3,0x03);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x14);
        set_sprite_tile(6,0x15);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x24);
        set_sprite_tile(9,0x25);
        break;

        case 4:
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x06);
        set_sprite_tile(3,0x07);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x16);
        set_sprite_tile(6,0x17);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x26);
        set_sprite_tile(9,0x27);
        break;
    }
}

void Anim_Mario_Small_Jump(void) BANKED
{
    set_sprite_tile(0,0x00);
    set_sprite_tile(1,0x00);
    set_sprite_tile(2,0x08);
    set_sprite_tile(3,0x09);
    set_sprite_tile(4,0x00);
    set_sprite_tile(5,0x18);
    set_sprite_tile(6,0x19);
    set_sprite_tile(7,0x00);
    set_sprite_tile(8,0x28);
    set_sprite_tile(9,0x29);
}

void Anim_Mario_Small_Win(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        set_sprite_prop(0,0);
        set_sprite_prop(1,0);
        set_sprite_prop(2,0);
        set_sprite_prop(3,0);
        set_sprite_prop(4,0);
        set_sprite_prop(5,0);
        set_sprite_prop(6,0);
        set_sprite_prop(7,0);
        set_sprite_prop(8,0);
        set_sprite_prop(9,0);
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x02);
        set_sprite_tile(3,0x03);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x10);
        set_sprite_tile(6,0x11);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x20);
        set_sprite_tile(9,0x21);
        break;

        case 3:
        set_sprite_prop(0,0);
        set_sprite_prop(1,0);
        set_sprite_prop(2,0);
        set_sprite_prop(3,0);
        set_sprite_prop(4,0);
        set_sprite_prop(5,0);
        set_sprite_prop(6,0);
        set_sprite_prop(7,0);
        set_sprite_prop(8,0);
        set_sprite_prop(9,0);
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x3C);
        set_sprite_tile(3,0x3D);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x4C);
        set_sprite_tile(6,0x4D);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x5C);
        set_sprite_tile(9,0x5D);
        break;

        case 6:
        set_sprite_prop(0,S_FLIPX);
        set_sprite_prop(1,S_FLIPX);
        set_sprite_prop(2,S_FLIPX);
        set_sprite_prop(3,S_FLIPX);
        set_sprite_prop(4,S_FLIPX);
        set_sprite_prop(5,S_FLIPX);
        set_sprite_prop(6,S_FLIPX);
        set_sprite_prop(7,S_FLIPX);
        set_sprite_prop(8,S_FLIPX);
        set_sprite_prop(9,S_FLIPX);
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x03);
        set_sprite_tile(3,0x02);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x11);
        set_sprite_tile(6,0x10);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x21);
        set_sprite_tile(9,0x20);
        break;

        case 9:
        set_sprite_prop(0,0);
        set_sprite_prop(1,0);
        set_sprite_prop(2,0);
        set_sprite_prop(3,0);
        set_sprite_prop(4,0);
        set_sprite_prop(5,0);
        set_sprite_prop(6,0);
        set_sprite_prop(7,0);
        set_sprite_prop(8,0);
        set_sprite_prop(9,0);
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x3C);
        set_sprite_tile(3,0x3D);
        set_sprite_tile(4,0x6B);
        set_sprite_tile(5,0x6C);
        set_sprite_tile(6,0x6D);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x7C);
        set_sprite_tile(9,0x7D);
        break;

        case 60:
        EndofLevel = 1;
        break;
    }
}