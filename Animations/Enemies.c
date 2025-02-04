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
        move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x)+8,-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x)+8,-(Camera.y - e->Hitbox.position.y) + 8);
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
        move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x)+8,-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x)+8,-(Camera.y - e->Hitbox.position.y) + 8);
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
        move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x)+8,-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x)+8,-(Camera.y - e->Hitbox.position.y) + 8);
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }
}

void Anim_Koopa_Move(Enemy *e) BANKED
{
    if(e->Sprite_tile != 0)
    {
        move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x) + 11 * e->dir.x,-(Camera.y - e->Hitbox.position.y) - 8);
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) + 11 * e->dir.x,-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x) + 3 * e->dir.x,-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x)+ 8  * e->dir.x,-(Camera.y - e->Hitbox.position.y) + 8);
        move_sprite(e->Sprite_tile+4,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y) + 8);
        switch(e->animState)
        {
            case 0:
            set_sprite_tile(e->Sprite_tile,0xAE);
            set_sprite_tile(e->Sprite_tile+1,0xAF);
            set_sprite_tile(e->Sprite_tile+2,0xB0);
            set_sprite_tile(e->Sprite_tile+3,0xB1);
            set_sprite_tile(e->Sprite_tile+4,0xB2);
            break;

            case 2:
            case 3:
            set_sprite_tile(e->Sprite_tile,0xAE);
            set_sprite_tile(e->Sprite_tile+1,0xAF);
            set_sprite_tile(e->Sprite_tile+2,0xB0);
            set_sprite_tile(e->Sprite_tile+3,0xB3);
            set_sprite_tile(e->Sprite_tile+4,0xB2);
            move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x) + 11 * e->dir.x,-(Camera.y - e->Hitbox.position.y) - 7);
            move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) + 11 * e->dir.x,-(Camera.y - e->Hitbox.position.y) + 1);
            move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x) + 3 * e->dir.x,-(Camera.y - e->Hitbox.position.y) + 1);
            move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x)+ 8  * e->dir.x,-(Camera.y - e->Hitbox.position.y) + 9);
            move_sprite(e->Sprite_tile+4,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y) + 9);
            break;

            case 4:
            set_sprite_tile(e->Sprite_tile,0xAE);
            set_sprite_tile(e->Sprite_tile+1,0xAF);
            set_sprite_tile(e->Sprite_tile+2,0xB0);
            set_sprite_tile(e->Sprite_tile+3,0xB1);
            set_sprite_tile(e->Sprite_tile+4,0xB2);
            break;

            case 6:
            case 7:
            set_sprite_tile(e->Sprite_tile,0xB4);
            set_sprite_tile(e->Sprite_tile+1,0xB5);
            set_sprite_tile(e->Sprite_tile+2,0xB0);
            set_sprite_tile(e->Sprite_tile+3,0xB1);
            set_sprite_tile(e->Sprite_tile+4,0xB6);
            move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x) + 11 * e->dir.x,-(Camera.y - e->Hitbox.position.y) - 7);
            move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) + 11 * e->dir.x,-(Camera.y - e->Hitbox.position.y) + 1);
            move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x) + 3 * e->dir.x,-(Camera.y - e->Hitbox.position.y) + 1);
            move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x)+ 8  * e->dir.x,-(Camera.y - e->Hitbox.position.y) + 9);
            move_sprite(e->Sprite_tile+4,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y) + 9);
            break;
        }

        set_sprite_prop(e->Sprite_tile,S_FLIPX * (e->dir.x > 0));
        set_sprite_prop(e->Sprite_tile+1,S_FLIPX * (e->dir.x > 0));
        set_sprite_prop(e->Sprite_tile+2,S_FLIPX * (e->dir.x > 0));
        set_sprite_prop(e->Sprite_tile+3,S_FLIPX * (e->dir.x > 0));
        set_sprite_prop(e->Sprite_tile+4,S_FLIPX * (e->dir.x > 0) );
    }else
    {
        e->Sprite_tile = Add_Sprite(5);
    }

    e->animState += Time;
    e->animState = e->animState >= 8 ? 0 : e->animState;
}

void Anim_Koopa_Shell_Idle(Enemy *e) BANKED
{
    if(e->Sprite_tile != 0)
    {

        set_sprite_tile(e->Sprite_tile,0xB7);
        set_sprite_tile(e->Sprite_tile+1,0xB7);
        set_sprite_tile(e->Sprite_tile+2,0xB8);
        set_sprite_tile(e->Sprite_tile+3,0xB8);

        set_sprite_prop(e->Sprite_tile,0);
        set_sprite_prop(e->Sprite_tile+1,S_FLIPX);
        set_sprite_prop(e->Sprite_tile+2,0);
        set_sprite_prop(e->Sprite_tile+3,S_FLIPX);

        move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) + 8,-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x)+ 8,-(Camera.y - e->Hitbox.position.y) + 8);
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }
}

void Anim_Koopa_Shell_Move(Enemy *e) BANKED
{
    if(e->Sprite_tile != 0)
    {
        switch (e->animState)
        {
            case 0:
            case 1:
            set_sprite_tile(e->Sprite_tile,0xB9);
            set_sprite_tile(e->Sprite_tile+1,0xBA);
            set_sprite_tile(e->Sprite_tile+2,0xBB);
            set_sprite_tile(e->Sprite_tile+3,0xBC);
            set_sprite_prop(e->Sprite_tile,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+1,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+2,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+3,S_FLIPX * (e->dir.x < 0));
            break;

            case 2:
            case 3:
            case 6:
            case 7:
            set_sprite_tile(e->Sprite_tile,0xBD);
            set_sprite_tile(e->Sprite_tile+1,0xBD);
            set_sprite_tile(e->Sprite_tile+2,0xBE);
            set_sprite_tile(e->Sprite_tile+3,0xBE);
            set_sprite_prop(e->Sprite_tile,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+1,S_FLIPX * (e->dir.x > 0));
            set_sprite_prop(e->Sprite_tile+2,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+3,S_FLIPX * (e->dir.x > 0));
            break;

            case 4:
            case 5:
            set_sprite_tile(e->Sprite_tile,0xBA);
            set_sprite_tile(e->Sprite_tile+1,0xB9);
            set_sprite_tile(e->Sprite_tile+2,0xBC);
            set_sprite_tile(e->Sprite_tile+3,0xBB);
            set_sprite_prop(e->Sprite_tile,S_FLIPX * (e->dir.x > 0));
            set_sprite_prop(e->Sprite_tile+1,S_FLIPX * (e->dir.x > 0));
            set_sprite_prop(e->Sprite_tile+2,S_FLIPX * (e->dir.x > 0));
            set_sprite_prop(e->Sprite_tile+3,S_FLIPX * (e->dir.x > 0));
            break;
        }


        move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x < 0),-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x < 0),-(Camera.y - e->Hitbox.position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x) + 8  * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y) + 8);
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }

    e->animState++;
    e->animState = e->animState >= 6 ? 0 : e->animState;
}

void Anim_Koopa_Knockback(Enemy *e) BANKED
{
    if(e->Sprite_tile != 0)
    {
        if(e->Sprite_size >= 5)
        {
            e->Sprite_tile = Remove_Sprite(e->Sprite_tile,5);
            e->Sprite_tile = Add_Sprite(4);
        }
        set_sprite_tile(e->Sprite_tile,0xB7);
        set_sprite_tile(e->Sprite_tile+1,0xB7);
        set_sprite_tile(e->Sprite_tile+2,0xB8);
        set_sprite_tile(e->Sprite_tile+3,0xB8);
        set_sprite_prop(e->Sprite_tile,S_FLIPY + S_FLIPX * (e->dir.x < 0));
        set_sprite_prop(e->Sprite_tile+1,S_FLIPY + S_FLIPX * (e->dir.x > 0));
        set_sprite_prop(e->Sprite_tile+2,S_FLIPY + S_FLIPX * (e->dir.x < 0));
        set_sprite_prop(e->Sprite_tile+3,S_FLIPY + S_FLIPX * (e->dir.x > 0));
        move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x < 0),-(Camera.y - e->Hitbox.position.y) + 8);
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y) + 8);
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x < 0),-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x) + 8  * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y));
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }
}