#include "..\include\Animations\Enemies.h"
#include "..\include\Sprite.h"
#include "..\include\Camera.h"
#include <gb\gb.h>

extern Vector2 Camera;
extern char Time;
extern Enemy *AllEnemies;
#pragma bank 9

void Anim_Goomba_Update(int SelectedEnemy) BANKED
{
    switch(AllEnemies[SelectedEnemy].AnimatorState)
    {
        case Animator_Enemy_Goomba_State_Move:
        Anim_Goomba_Move(SelectedEnemy);
        break;

        case Animator_Enemy_Goomba_State_Knockback:
        Anim_Goomba_Knockback(SelectedEnemy);
        break;

        case Animator_Enemy_Goomba_State_Death:
        Anim_Goomba_Death(SelectedEnemy);
        break;
    }
    Display_Goomba(SelectedEnemy);
}

void Anim_Goomba_Move(int i) BANKED
{

    if(AllEnemies[i].Sprite_tile != 0)
    {
        switch (AllEnemies[i].animState)
        {
            case 0:
            set_sprite_tile(AllEnemies[i].Sprite_tile,0xA6);
            set_sprite_tile(AllEnemies[i].Sprite_tile+1,0xA7);
            set_sprite_tile(AllEnemies[i].Sprite_tile+2,0xA8);
            set_sprite_tile(AllEnemies[i].Sprite_tile+3,0xA9);
            break;
                
            case 5:
            set_sprite_tile(AllEnemies[i].Sprite_tile,0xAA);
            set_sprite_tile(AllEnemies[i].Sprite_tile+1,0xAB);
            set_sprite_tile(AllEnemies[i].Sprite_tile+2,0xAC);
            set_sprite_tile(AllEnemies[i].Sprite_tile+3,0xAD);
            break;
        }
    }else
    {
        AllEnemies[i].Sprite_tile = Add_Sprite(4);
    }

    AllEnemies[i].animState += Time;
    AllEnemies[i].animState = AllEnemies[i].animState >= 10 ? 0 : AllEnemies[i].animState;
}

void Anim_Goomba_Death(int i) BANKED
{
    if(AllEnemies[i].Sprite_tile != 0)
    {
        set_sprite_tile(AllEnemies[i].Sprite_tile,0x00);
        set_sprite_tile(AllEnemies[i].Sprite_tile+1,0x00);
        set_sprite_tile(AllEnemies[i].Sprite_tile+2,0xAE);
        set_sprite_tile(AllEnemies[i].Sprite_tile+3,0xAF);
    }else
    {
        AllEnemies[i].Sprite_tile = Add_Sprite(4);
    }

}

void Anim_Goomba_Knockback(int i)BANKED
{
    if(AllEnemies[i].Sprite_tile != 0)
    {
        set_sprite_tile(AllEnemies[i].Sprite_tile,0xAC);
        set_sprite_tile(AllEnemies[i].Sprite_tile+1,0xA9);
        set_sprite_tile(AllEnemies[i].Sprite_tile+2,0xAA);
        set_sprite_tile(AllEnemies[i].Sprite_tile+3,0xAB);
    }else
    {
        AllEnemies[i].Sprite_tile = Add_Sprite(4);
    }
}

void Anim_Koopa_Update(int SelectedEnemy) BANKED
{
    switch (AllEnemies[SelectedEnemy].AnimatorState)
    {
        case Animator_Enemy_Koopa_State_Move:
        Anim_Koopa_Move(SelectedEnemy);
        break;
    
        case Animator_Enemy_Koopa_State_Shell_Idle:
        Anim_Koopa_Shell_Idle(SelectedEnemy);
        break;

        case Animator_Enemy_Koopa_State_Shell_Move:
        Anim_Koopa_Shell_Move(SelectedEnemy);
        break;
    }

    Display_Koopa(SelectedEnemy);
}

void Anim_Koopa_Move(int SelectedEnemy) BANKED
{
    if(AllEnemies[SelectedEnemy].Sprite_tile != 0)
    {
        switch(AllEnemies[SelectedEnemy].animState)
        {
            case 0:
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile,0xB0);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+1,0xB1);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+2,0xB2);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+3,0xB3);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+4,0xB4);
            break;

            case 2:
            case 3:
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile,0xB0);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+1,0xB1);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+2,0xB2);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+3,0xB5);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+4,0xB4);
            break;

            case 4:
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile,0xB0);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+1,0xB1);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+2,0xB2);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+3,0xB3);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+4,0xB4);
            break;

            case 6:
            case 7:
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile,0xB6);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+1,0xB7);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+2,0xB2);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+3,0xB3);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+4,0xB8);
            break;
        }
    }else
    {
        AllEnemies[SelectedEnemy].Sprite_tile = Add_Sprite(5);
    }

    AllEnemies[SelectedEnemy].animState += Time;
    AllEnemies[SelectedEnemy].animState = AllEnemies[SelectedEnemy].animState >= 8 ? 0 : AllEnemies[SelectedEnemy].animState;
}

void Anim_Koopa_Shell_Idle(int SelectedEnemy) BANKED
{
    if(AllEnemies[SelectedEnemy].Sprite_tile != 0)
    {
        set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile,0xB9);
        set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+1,0xB9);
        set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+2,0xBA);
        set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+3,0xBA);
    }else
    {
        AllEnemies[SelectedEnemy].Sprite_tile = Add_Sprite(4);
    }

    if(AllEnemies[SelectedEnemy].animState >= 60)
    {   
        AllEnemies[SelectedEnemy].State = 0;
        AllEnemies[SelectedEnemy].animState = 0;
        AllEnemies[SelectedEnemy].Sprite_tile = Remove_Sprite(AllEnemies[SelectedEnemy].Sprite_tile,4);
    }
}

void Anim_Koopa_Shell_Move(int SelectedEnemy) BANKED
{
    if(AllEnemies[SelectedEnemy].Sprite_tile != 0)
    {
        switch (AllEnemies[SelectedEnemy].animState)
        {
            case 0:
            case 1:
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x < 0));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+1,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x < 0));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+2,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x < 0));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+3,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x < 0));
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile,0xBB);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+1,0xBC);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+2,0xBD);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+3,0xBE);
            break;

            case 2:
            case 3:
            case 6:
            case 7:
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x < 0));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+1,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x > 0));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+2,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x < 0));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+3,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x > 0));
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile,0xBF);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+1,0xBF);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+2,0xC0);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+3,0xC0);
            break;

            case 4:
            case 5:
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x > 0));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+1,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x > 0));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+2,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x > 0));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+3,S_FLIPX * (AllEnemies[SelectedEnemy].dir.x > 0));
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile,0xBC);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+1,0xBB);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+2,0xBE);
            set_sprite_tile(AllEnemies[SelectedEnemy].Sprite_tile+3,0xBD);
            break;
        }
    }else
    {
        AllEnemies[SelectedEnemy].Sprite_tile = Add_Sprite(4);
    }

    AllEnemies[SelectedEnemy].animState++;
    AllEnemies[SelectedEnemy].animState = AllEnemies[SelectedEnemy].animState >= 8 ? 0 : AllEnemies[SelectedEnemy].animState;
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