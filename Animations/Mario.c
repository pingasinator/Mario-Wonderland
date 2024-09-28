#include <gb\gb.h>
#include "..\include\Animations\Mario.h"

#pragma bank 10

void Anim_Mario_Idle(int Transformation) BANKED
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

void Anim_Mario_Fall(void) BANKED
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

void Anim_Mario_Move(int animstate) BANKED
{
    switch(animstate)
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


}

void Anim_Mario_Jump(void) BANKED
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

void Anim_Mario_Slide(void) BANKED
{
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