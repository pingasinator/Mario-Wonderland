#include "..\..\include\Animations\Mario\RacoonMario.h"

#pragma bank 12

void Anim_Mario_Racoon_Idle(void) BANKED
{
    set_sprite_tile(0,0x6D);
    set_sprite_tile(1,0x6E);
    set_sprite_tile(2,0x36);
    set_sprite_tile(3,0x37);
    set_sprite_tile(4,0);
    set_sprite_tile(5,0x38);
    set_sprite_tile(6,0x39);
    set_sprite_tile(7,0);
    set_sprite_tile(8,0x3A);
    set_sprite_tile(9,0x3B);
}

void Anim_Mario_Racoon_Move(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        set_sprite_tile(0,0x6D);
        set_sprite_tile(1,0x6E);
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
        set_sprite_tile(0,0x6D);
        set_sprite_tile(1,0x6E);
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