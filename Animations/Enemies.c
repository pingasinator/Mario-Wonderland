#include "../include/Animations/Enemies.h"
#include "../include/Sprite.h"
#include "../include/Camera.h"
#include <gb/gb.h>

extern Vector2 Camera;
extern char Time;
extern Enemy *AllEnemies;
#pragma bank 9

void Anim_Goomba_Update(Enemy *e) BANKED
{
    if(e->Sprite_tile != 0)
    {
        switch(e->AnimatorState)
        {
            case Animator_Enemy_Goomba_State_Move:
            Anim_Goomba_Move(e);
            break;

            case Animator_Enemy_Goomba_State_Knockback:
            Anim_Goomba_Knockback(e);
            break;

            case Animator_Enemy_Goomba_State_Death:
            Anim_Goomba_Death(e);
            break;
        }
        
        move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x)+8,-(Camera.y - e->Hitbox.position.y));
        move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x)+8,-(Camera.y - e->Hitbox.position.y) + 8);

    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }
}

void Anim_Goomba_Move(Enemy *e) BANKED
{
    switch (e->animState)
    {
        case 0:
        set_sprite_prop(e->Sprite_tile,S_PALETTE);
        set_sprite_prop(e->Sprite_tile+1,S_PALETTE);
        set_sprite_prop(e->Sprite_tile+2,S_PALETTE);
        set_sprite_prop(e->Sprite_tile+3,S_PALETTE);
        set_sprite_tile(e->Sprite_tile,0xB0);
        set_sprite_tile(e->Sprite_tile+1,0xB1);
        set_sprite_tile(e->Sprite_tile+2,0xB2);
        set_sprite_tile(e->Sprite_tile+3,0xB3);
        break;
                
        case 5:
        set_sprite_prop(e->Sprite_tile,S_PALETTE);
        set_sprite_prop(e->Sprite_tile+1,S_PALETTE);
        set_sprite_prop(e->Sprite_tile+2,S_PALETTE + S_FLIPX);
        set_sprite_prop(e->Sprite_tile+3,S_PALETTE + S_FLIPX);
        set_sprite_tile(e->Sprite_tile,0xB0);
        set_sprite_tile(e->Sprite_tile+1,0xB1);
        set_sprite_tile(e->Sprite_tile+2,0xB3);
        set_sprite_tile(e->Sprite_tile+3,0xB2);
        break;
    }

    e->animState += Time;
    e->animState = e->animState >= 10 ? 0 : e->animState;
}

void Anim_Goomba_Death(Enemy *e) BANKED
{
    set_sprite_prop(e->Sprite_tile,S_PALETTE);
    set_sprite_prop(e->Sprite_tile+1,S_PALETTE);
    set_sprite_prop(e->Sprite_tile+2,S_PALETTE);
    set_sprite_prop(e->Sprite_tile+3,S_PALETTE + S_FLIPX);
    set_sprite_tile(e->Sprite_tile,0x00);
    set_sprite_tile(e->Sprite_tile+1,0x00);
    set_sprite_tile(e->Sprite_tile+2,0xB4);
    set_sprite_tile(e->Sprite_tile+3,0xB4);
}

void Anim_Goomba_Knockback(Enemy *e)BANKED
{
    set_sprite_prop(e->Sprite_tile,S_PALETTE + S_FLIPY);
    set_sprite_prop(e->Sprite_tile+1,S_PALETTE + S_FLIPY + S_FLIPX);
    set_sprite_prop(e->Sprite_tile+2,S_PALETTE + S_FLIPY + S_FLIPX);
    set_sprite_prop(e->Sprite_tile+3,S_PALETTE + S_FLIPY);
    set_sprite_tile(e->Sprite_tile,0xB2);
    set_sprite_tile(e->Sprite_tile+1,0xB2);
    set_sprite_tile(e->Sprite_tile+2,0xB1);
    set_sprite_tile(e->Sprite_tile+3,0xB1);
}

void Anim_Koopa_Update(Enemy *e) BANKED
{
    switch (e->AnimatorState)
    {
        case Animator_Enemy_Koopa_State_Move:
        Anim_Koopa_Move(e);
        break;
    
        case Animator_Enemy_Koopa_State_Shell_Idle:
        Anim_Koopa_Shell_Idle(e);
        break;

        case Animator_Enemy_Koopa_State_Shell_Move:
        Anim_Koopa_Shell_Move(e);
        break;

        case Animator_Enemy_Koopa_State_Knockback:
        Anim_Koopa_Knockback(e);
        break;
    }

    Display_Koopa(e);
}

void Anim_Koopa_Move(Enemy *e) BANKED
{
    if(e->Sprite_tile != 0)
    {
        switch(e->animState)
        {
            case 0:
            set_sprite_tile(e->Sprite_tile,0xB5);
            set_sprite_tile(e->Sprite_tile+1,0xB6);
            set_sprite_tile(e->Sprite_tile+2,0xB7);
            set_sprite_tile(e->Sprite_tile+3,0xB8);
            set_sprite_tile(e->Sprite_tile+4,0xB9);
            break;

            case 2:
            case 3:
            set_sprite_tile(e->Sprite_tile,0xB5);
            set_sprite_tile(e->Sprite_tile+1,0xB6);
            set_sprite_tile(e->Sprite_tile+2,0xB7);
            set_sprite_tile(e->Sprite_tile+3,0xBA);
            set_sprite_tile(e->Sprite_tile+4,0xB9);
            break;

            case 4:
            set_sprite_tile(e->Sprite_tile,0xB5);
            set_sprite_tile(e->Sprite_tile+1,0xB6);
            set_sprite_tile(e->Sprite_tile+2,0xB7);
            set_sprite_tile(e->Sprite_tile+3,0xB8);
            set_sprite_tile(e->Sprite_tile+4,0xB9);
            break;

            case 6:
            case 7:
            set_sprite_tile(e->Sprite_tile,0xBB);
            set_sprite_tile(e->Sprite_tile+1,0xBC);
            set_sprite_tile(e->Sprite_tile+2,0xB7);
            set_sprite_tile(e->Sprite_tile+3,0xB8);
            set_sprite_tile(e->Sprite_tile+4,0xBD);
            break;
        }
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
        set_sprite_tile(e->Sprite_tile,0xB9);
        set_sprite_tile(e->Sprite_tile+1,0xB9);
        set_sprite_tile(e->Sprite_tile+2,0xBA);
        set_sprite_tile(e->Sprite_tile+3,0xBA);
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }

    if(e->animState >= 60)
    {   
        e->State = 0;
        e->animState = 0;
        e->Sprite_tile = Remove_NonMarioObject_Sprite(e->Sprite_tile,4);
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
            set_sprite_prop(e->Sprite_tile,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+1,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+2,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+3,S_FLIPX * (e->dir.x < 0));
            set_sprite_tile(e->Sprite_tile,0xBB);
            set_sprite_tile(e->Sprite_tile+1,0xBC);
            set_sprite_tile(e->Sprite_tile+2,0xBD);
            set_sprite_tile(e->Sprite_tile+3,0xBE);
            break;

            case 2:
            case 3:
            case 6:
            case 7:
            set_sprite_prop(e->Sprite_tile,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+1,S_FLIPX * (e->dir.x > 0));
            set_sprite_prop(e->Sprite_tile+2,S_FLIPX * (e->dir.x < 0));
            set_sprite_prop(e->Sprite_tile+3,S_FLIPX * (e->dir.x > 0));
            set_sprite_tile(e->Sprite_tile,0xBF);
            set_sprite_tile(e->Sprite_tile+1,0xBF);
            set_sprite_tile(e->Sprite_tile+2,0xC0);
            set_sprite_tile(e->Sprite_tile+3,0xC0);
            break;

            case 4:
            case 5:
            set_sprite_prop(e->Sprite_tile,S_FLIPX * (e->dir.x > 0));
            set_sprite_prop(e->Sprite_tile+1,S_FLIPX * (e->dir.x > 0));
            set_sprite_prop(e->Sprite_tile+2,S_FLIPX * (e->dir.x > 0));
            set_sprite_prop(e->Sprite_tile+3,S_FLIPX * (e->dir.x > 0));
            set_sprite_tile(e->Sprite_tile,0xBC);
            set_sprite_tile(e->Sprite_tile+1,0xBB);
            set_sprite_tile(e->Sprite_tile+2,0xBE);
            set_sprite_tile(e->Sprite_tile+3,0xBD);
            break;
        }
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }

    e->animState++;
    e->animState = e->animState >= 8 ? 0 : e->animState;
}

void Anim_Koopa_Knockback(Enemy *e) BANKED
{
    if(e->Sprite_tile != 0)
    {
        if(e->Sprite_size >= 5)
        {
            e->Sprite_tile = Remove_NonMarioObject_Sprite(e->Sprite_tile,5);
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