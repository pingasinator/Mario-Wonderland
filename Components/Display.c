#include <gb\gb.h>
#include "..\include\Sprite.h"
#include "..\include\collision.h"
#include "..\include\Enemies.h"

#include "..\include\Animations\Mario\Mario.h"
#include "..\include\Animations\Enemies.h"

#pragma bank 4

extern Vector2 Camera;

extern Enemy *AllEnemies;

extern Collision Mario_Hitbox;
extern char Mario_dir;
extern char Mario_Transformation;
extern char Mario_Animator_State;

void DisplayMario(void)BANKED
{
    
    for(int i = 0; i < 10; i++)
    {
        set_sprite_prop(i,S_FLIPX * (Mario_dir < 0));
    }

    move_sprite(0,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y) - 16);
    move_sprite(1,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir > 0),-(Camera.y - Mario_Hitbox.position.y) - 16);
    move_sprite(2,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y) - 8);
    move_sprite(3,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir > 0),-(Camera.y - Mario_Hitbox.position.y) - 8);
    move_sprite(4,-(Camera.x - Mario_Hitbox.position.x) - 8 + 24 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y));
    move_sprite(5,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y));
    move_sprite(6,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir > 0),-(Camera.y - Mario_Hitbox.position.y));
    move_sprite(7,-(Camera.x - Mario_Hitbox.position.x) - 8 + 24 * ( Mario_Transformation == 3 &&  Mario_Animator_State == Animator_Mario_State_Slide ? Mario_dir > 0 : Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y) + 8);
    move_sprite(8,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y) + 8);
    move_sprite(9,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir > 0),-(Camera.y - Mario_Hitbox.position.y) + 8);
}

void Display_Goomba(int SelectedEnemy) BANKED
{
    if(AllEnemies[SelectedEnemy].Sprite_tile != 0)
    {
        set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile,((AllEnemies[SelectedEnemy].Knockback == 1) * S_FLIPY) + S_PALETTE);
        set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+1,((AllEnemies[SelectedEnemy].Knockback == 1) * S_FLIPY) + S_PALETTE);
        set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+2,((AllEnemies[SelectedEnemy].Knockback == 1) * S_FLIPY) + S_PALETTE);
        set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+3,((AllEnemies[SelectedEnemy].Knockback == 1) * S_FLIPY) + S_PALETTE);
        move_sprite(AllEnemies[SelectedEnemy].Sprite_tile,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y));
        move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+1,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x)+8,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y));
        move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+2,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 8);
        move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+3,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x)+8,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 8);
    }
}

void Display_Koopa(int SelectedEnemy) BANKED
{
    if(AllEnemies[SelectedEnemy].Sprite_tile != 0)
    {
        switch (AllEnemies[SelectedEnemy].State)
        {
            case Animator_Enemy_Koopa_State_Move:
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile,((AllEnemies[SelectedEnemy].dir.x > 0) * S_FLIPX));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+1,((AllEnemies[SelectedEnemy].dir.x > 0) * S_FLIPX));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+2,((AllEnemies[SelectedEnemy].dir.x > 0) * S_FLIPX));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+3,((AllEnemies[SelectedEnemy].dir.x > 0) * S_FLIPX));
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+4,((AllEnemies[SelectedEnemy].dir.x > 0) * S_FLIPX));
                switch (AllEnemies[SelectedEnemy].animState)
                {
                    case 2:
                    case 3:
                    case 6:
                    case 7:
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 11 * AllEnemies[SelectedEnemy].dir.x,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) - 7);
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+1,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 11 * AllEnemies[SelectedEnemy].dir.x,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 1);
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+2,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 3 * AllEnemies[SelectedEnemy].dir.x,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 1);
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+3,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x)+ 8  * AllEnemies[SelectedEnemy].dir.x,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 9);
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+4,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 9);
                    break;
            
                    default:
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 11 * AllEnemies[SelectedEnemy].dir.x,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) - 8);
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+1,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 11 * AllEnemies[SelectedEnemy].dir.x,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y));
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+2,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 3 * AllEnemies[SelectedEnemy].dir.x,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y));
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+3,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x)+ 8  * AllEnemies[SelectedEnemy].dir.x,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 8);
                    move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+4,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 8);    
                    break;
                }
            break;
    
            case Animator_Enemy_Koopa_State_Shell_Idle:
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile,0);
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+1,S_FLIPX);
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+2,0);
            set_sprite_prop(AllEnemies[SelectedEnemy].Sprite_tile+3,S_FLIPX);
            move_sprite(AllEnemies[SelectedEnemy].Sprite_tile,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y));
            move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+1,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 8,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y));
            move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+2,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 8);
            move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+3,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x)+ 8,-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 8);
            break;
    
            case  Animator_Enemy_Koopa_State_Shell_Move:

                move_sprite(AllEnemies[SelectedEnemy].Sprite_tile,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 8 * (AllEnemies[SelectedEnemy].dir.x < 0),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y));
                move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+1,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 8 * (AllEnemies[SelectedEnemy].dir.x > 0),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y));
                move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+2,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 8 * (AllEnemies[SelectedEnemy].dir.x < 0),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 8);
                move_sprite(AllEnemies[SelectedEnemy].Sprite_tile+3,-(Camera.x - AllEnemies[SelectedEnemy].Hitbox.position.x) + 8  * (AllEnemies[SelectedEnemy].dir.x > 0),-(Camera.y - AllEnemies[SelectedEnemy].Hitbox.position.y) + 8);
            break;
        }
    }
}