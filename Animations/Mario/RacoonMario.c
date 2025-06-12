#include "..\..\include\Animations\Mario\RacoonMario.h"
#include "..\..\include\Animations\Mario\Mario.h"
#include "..\..\include\Collision.h"
#include "..\..\include\Mathf.h"

#pragma bank 12

extern int EndofLevel;
extern char Mario_dir;

extern Collision Mario_Hitbox;
extern Vector2 Camera;

void Anim_Mario_Racoon_Idle(void) BANKED
{
    set_sprite_tile(0,0x0A);
    set_sprite_tile(1,0x0B);
    set_sprite_tile(2,0x10);
    set_sprite_tile(3,0x11);
    set_sprite_tile(4,0x01);
    set_sprite_tile(5,0X20);
    set_sprite_tile(6,0X21);
    set_sprite_tile(7,0x50);
    set_sprite_tile(8,0X30);
    set_sprite_tile(9,0X31);
}

void Anim_Mario_Racoon_Move(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        set_sprite_tile(4,0x43);
        set_sprite_tile(5,0x22);
        set_sprite_tile(6,0x23);
        set_sprite_tile(7,0x40);
        set_sprite_tile(8,0x32);
        set_sprite_tile(9,0x33);
        break;

        case 2:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        set_sprite_tile(4,0x0C);
        set_sprite_tile(5,0x24);
        set_sprite_tile(6,0x25);
        set_sprite_tile(7,0x1C);
        set_sprite_tile(8,0x34);
        set_sprite_tile(9,0x35);
        break;

        case 4:
        set_sprite_tile(0,0x0A);
        set_sprite_tile(1,0x0B);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        set_sprite_tile(4,0x42);
        set_sprite_tile(5,0x26);
        set_sprite_tile(6,0x27);
        set_sprite_tile(7,0x52);
        set_sprite_tile(8,0x36);
        set_sprite_tile(9,0x37);
        break;
    }
}

void Anim_Mario_Racoon_Run(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        set_sprite_tile(4,0x56);
        set_sprite_tile(5,0x67);
        set_sprite_tile(6,0x68);
        set_sprite_tile(7,0x50);
        set_sprite_tile(8,0x76);
        set_sprite_tile(9,0x77);
        break;

        case 2:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        set_sprite_tile(4,0x66);
        set_sprite_tile(5,0x67);
        set_sprite_tile(6,0x58);
        set_sprite_tile(7,0x52);
        set_sprite_tile(8,0x36);
        set_sprite_tile(9,0x78);
        break;

        case 4:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        set_sprite_tile(4,0x53);
        set_sprite_tile(5,0x57);
        set_sprite_tile(6,0x68);
        set_sprite_tile(7,0x46);
        set_sprite_tile(8,0x47);
        set_sprite_tile(9,0x48);
        break;
    }
}

void Anim_Mario_Racoon_Crounch(void) BANKED
{
        set_sprite_tile(0,0x00);
        set_sprite_tile(1,0x00);
        set_sprite_tile(2,0x09);
        set_sprite_tile(3,0x00);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x04);
        set_sprite_tile(6,0x05);
        set_sprite_tile(7,0x19);
        set_sprite_tile(8,0x14);
        set_sprite_tile(9,0x15);
}

void Anim_Mario_Racoon_Jump(void) BANKED
{
    set_sprite_tile(0,0x44);
    set_sprite_tile(1,0x45);
    set_sprite_tile(2,0x54);
    set_sprite_tile(3,0x55);
    set_sprite_tile(4,0x63);
    set_sprite_tile(5,0x64);
    set_sprite_tile(6,0x65);
    set_sprite_tile(7,0x73);
    set_sprite_tile(8,0x74);
    set_sprite_tile(9,0x75);
}

void Anim_Mario_Racoon_Jump_Run(void) BANKED
{
    set_sprite_tile(0,0x02);
    set_sprite_tile(1,0x03);
    set_sprite_tile(2,0x12);
    set_sprite_tile(3,0x13);
    set_sprite_tile(4,0x06);
    set_sprite_tile(5,0x07);
    set_sprite_tile(6,0x08);
    set_sprite_tile(7,0x16);
    set_sprite_tile(8,0x17);
    set_sprite_tile(9,0x18);
}

void Anim_Mario_Racoon_Fly(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        set_sprite_tile(4,0x06);
        set_sprite_tile(5,0x07);
        set_sprite_tile(6,0x08);
        set_sprite_tile(7,0x16);
        set_sprite_tile(8,0x17);
        set_sprite_tile(9,0x18);
        break;

        case 1:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        set_sprite_tile(4,0x0F);
        set_sprite_tile(5,0x07);
        set_sprite_tile(6,0x08);
        set_sprite_tile(7,0x1F);
        set_sprite_tile(8,0x17);
        set_sprite_tile(9,0x18);
        break;

        case 2:
        set_sprite_tile(0,0x02);
        set_sprite_tile(1,0x03);
        set_sprite_tile(2,0x12);
        set_sprite_tile(3,0x13);
        set_sprite_tile(4,0x2F);
        set_sprite_tile(5,0x07);
        set_sprite_tile(6,0x08);
        set_sprite_tile(7,0x3F);
        set_sprite_tile(8,0x17);
        set_sprite_tile(9,0x18);
        break;
    }
}

void Anim_Mario_Racoon_Slide(void) BANKED
{
    set_sprite_tile(0,0x0A);
    set_sprite_tile(1,0x0B);
    set_sprite_tile(2,0x1A);
    set_sprite_tile(3,0x1B);
    set_sprite_tile(4,0x00);
    set_sprite_tile(5,0x2A);
    set_sprite_tile(6,0x2B);
    set_sprite_tile(7,0x79);
    set_sprite_tile(8,0x3A);
    set_sprite_tile(9,0x3B);
}

void Anim_Mario_Racoon_Fall(void) BANKED
{
    set_sprite_tile(0,0x0A);
    set_sprite_tile(1,0x0B);
    set_sprite_tile(2,0x10);
    set_sprite_tile(3,0x11);
    set_sprite_tile(4,0x41);
    set_sprite_tile(5,0x26);
    set_sprite_tile(6,0x27);
    set_sprite_tile(7,0x51);
    set_sprite_tile(8,0x74);
    set_sprite_tile(9,0x37);
}

void Anim_Mario_Racoon_Glide(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        set_sprite_tile(0,0x0A);
        set_sprite_tile(1,0x0B);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        set_sprite_tile(4,0x41);
        set_sprite_tile(5,0x26);
        set_sprite_tile(6,0x27);
        set_sprite_tile(7,0x51);
        set_sprite_tile(8,0x74);
        set_sprite_tile(9,0x37);
        break;

        case 2:
        set_sprite_tile(0,0x0A);
        set_sprite_tile(1,0x0B);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        set_sprite_tile(4,0x42);
        set_sprite_tile(5,0x26);
        set_sprite_tile(6,0x27);
        set_sprite_tile(7,0x52);
        set_sprite_tile(8,0x74);
        set_sprite_tile(9,0x37);
        break;

        case 4:
        set_sprite_tile(0,0x0A);
        set_sprite_tile(1,0x0B);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        set_sprite_tile(4,0x0C);
        set_sprite_tile(5,0x26);
        set_sprite_tile(6,0x27);
        set_sprite_tile(7,0x1C);
        set_sprite_tile(8,0x74);
        set_sprite_tile(9,0x37);
        break;
    }
}

void Anim_Mario_Racoon_Win(int animstate) BANKED
{
    switch(animstate)
    {
        case 0:
        Mario_dir = 1;
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
        set_sprite_tile(0,0x0A);
        set_sprite_tile(1,0x0B);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x20);
        set_sprite_tile(6,0x21);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x30);
        set_sprite_tile(9,0x31);
        break;

        case 3:
        Mario_dir = 1;
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
        set_sprite_tile(0,0x4E);
        set_sprite_tile(1,0x4F);
        set_sprite_tile(2,0x5E);
        set_sprite_tile(3,0x5F);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x6E);
        set_sprite_tile(6,0x6F);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x7E);
        set_sprite_tile(9,0x7F);
        break;

        case 6:
        Mario_dir = -1;
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
        set_sprite_tile(0,0x0A);
        set_sprite_tile(1,0x0B);
        set_sprite_tile(2,0x10);
        set_sprite_tile(3,0x11);
        set_sprite_tile(4,0x00);
        set_sprite_tile(5,0x20);
        set_sprite_tile(6,0x21);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x30);
        set_sprite_tile(9,0x31);
        break;

        case 9:
        Mario_dir = 1;
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
        set_sprite_tile(0,0x4A);
        set_sprite_tile(1,0x4B);
        set_sprite_tile(2,0x5A);
        set_sprite_tile(3,0x5B);
        set_sprite_tile(4,0x69);
        set_sprite_tile(5,0x6A);
        set_sprite_tile(6,0x6B);
        set_sprite_tile(7,0x00);
        set_sprite_tile(8,0x7A);
        set_sprite_tile(9,0x7B);
        break;

        case 60:
        EndofLevel = 1;
        break;
    }
}