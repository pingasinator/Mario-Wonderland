#include "..\include\Animations\Enemies.h"
#include <gb\gb.h>

#pragma bank 15

void Anim_Goomba_Move(Enemy *e) BANKED
{
    switch (e->animState)
    {
        case 0:
        if(e->Sprite_tile != 0)
        {
            set_sprite_tile(e->Sprite_tile,0xA4);
            set_sprite_tile(e->Sprite_tile+1,0xA5);
            set_sprite_tile(e->Sprite_tile+2,0xA6);
            set_sprite_tile(e->Sprite_tile+3,0xA7);
        }
        break;
                
        case 5:
        if(e->Sprite_tile != 0)
        {
            set_sprite_tile(e->Sprite_tile,0xA8);
            set_sprite_tile(e->Sprite_tile+1,0xA9);
            set_sprite_tile(e->Sprite_tile+2,0xAA);
            set_sprite_tile(e->Sprite_tile+3,0xAB);
        }
        break;
    }
}

void Anim_Goomba_Death(Enemy *e) BANKED
{
    set_sprite_tile(e->Sprite_tile,0x00);
    set_sprite_tile(e->Sprite_tile+1,0x00);
    set_sprite_tile(e->Sprite_tile+2,0xAC);
    set_sprite_tile(e->Sprite_tile+3,0xAD);
}