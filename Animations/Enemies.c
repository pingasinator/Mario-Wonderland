#include "..\include\Animations\Enemies.h"
#include "..\include\Sprite.h"
#include "..\include\Camera.h"
#include <gb\gb.h>

extern Vector2 Camera;
extern char Time;

#pragma bank 15

void Anim_Goomba_Move(Enemy *e) BANKED
{

    if(e->Sprite_tile != 0)
    {
        switch (e->animState)
        {
            case 0:
                set_sprite_tile(e->Sprite_tile,0xA4);
                set_sprite_tile(e->Sprite_tile+1,0xA5);
                set_sprite_tile(e->Sprite_tile+2,0xA6);
                set_sprite_tile(e->Sprite_tile+3,0xA7);
            break;
                
            case 5:
            set_sprite_tile(e->Sprite_tile,0xA8);
            set_sprite_tile(e->Sprite_tile+1,0xA9);
            set_sprite_tile(e->Sprite_tile+2,0xAA);
            set_sprite_tile(e->Sprite_tile+3,0xAB);
            break;
        }

        set_sprite_prop(e->Sprite_tile,S_PALETTE);
        set_sprite_prop(e->Sprite_tile+1,S_PALETTE);
        set_sprite_prop(e->Sprite_tile+2,S_PALETTE);
        set_sprite_prop(e->Sprite_tile+3,S_PALETTE);
        move_sprite(e->Sprite_tile,-(Camera.x - e->position.x),-(Camera.y - e->position.y));
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->position.x)+8,-(Camera.y - e->position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->position.x),-(Camera.y - e->position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->position.x)+8,-(Camera.y - e->position.y) + 8);
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }

    e->animState += Time;
    e->animState = e->animState >= 10 ? 0 : e->animState;
}

void Anim_Goomba_Death(Enemy *e) BANKED
{
    if(e->Sprite_tile != 0)
    {
        set_sprite_tile(e->Sprite_tile,0x00);
        set_sprite_tile(e->Sprite_tile+1,0x00);
        set_sprite_tile(e->Sprite_tile+2,0xAC);
        set_sprite_tile(e->Sprite_tile+3,0xAD);
        move_sprite(e->Sprite_tile,-(Camera.x - e->position.x),-(Camera.y - e->position.y));
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->position.x)+8,-(Camera.y - e->position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->position.x),-(Camera.y - e->position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->position.x)+8,-(Camera.y - e->position.y) + 8);
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }

}

void Anim_Goomba_Knockback(Enemy *e)BANKED
{
    if(e->Sprite_tile != 0)
    {
        set_sprite_prop(e->Sprite_tile,S_FLIPY + S_PALETTE);
        set_sprite_prop(e->Sprite_tile+1,S_FLIPY + S_PALETTE);
        set_sprite_prop(e->Sprite_tile+2,S_FLIPY + S_PALETTE);
        set_sprite_prop(e->Sprite_tile+3,S_FLIPY + S_PALETTE);
        set_sprite_tile(e->Sprite_tile,0xAA);
        set_sprite_tile(e->Sprite_tile+1,0xA7);
        set_sprite_tile(e->Sprite_tile+2,0xA8);
        set_sprite_tile(e->Sprite_tile+3,0xA9);
        move_sprite(e->Sprite_tile,-(Camera.x - e->position.x),-(Camera.y - e->position.y));
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->position.x)+8,-(Camera.y - e->position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->position.x),-(Camera.y - e->position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->position.x)+8,-(Camera.y - e->position.y) + 8);
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }
}