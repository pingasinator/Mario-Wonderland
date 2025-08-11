#include <gb\gb.h>
#include "..\include\Sprite.h"
#include "..\include\collision.h"
#include "..\include\Enemies.h"
#include "..\include\Objects.h"

#include "..\include\Animations\Mario\Mario.h"
#include "..\include\Mario.h"
#include "..\include\Animations\Enemies.h"

#pragma bank 4

extern Vector2 Camera;

extern Enemy *AllEnemies;

extern Collision Mario_Hitbox;
extern char Mario_dir;
extern char Mario_Transformation;
extern char Mario_Animator_State;
extern unsigned char Mario_State;
extern int animstate_Star;

void DisplayMario(void)BANKED
{
    
    for(int i = 0; i < 10; i++)
    {
        set_sprite_prop(i,S_FLIPX * (Mario_dir < 0) + ((animstate_Star >= 5) * S_PALETTE) + ((Mario_State == Mario_State_EnterPipe) * S_PRIORITY));
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

void Display_Item(Object *o) BANKED
{
    if(o->Sprite != 0)
    {
        switch(o->type)
        {
            case Object_Type_Item_Mushroom:
            set_sprite_tile(o->Sprite,0x80);
            set_sprite_tile(o->Sprite + 1,0x81);
            set_sprite_tile(o->Sprite + 2,0x82);
            set_sprite_tile(o->Sprite + 3,0x83);
            break;
    
            case Object_Type_Item_FireFlower:
            set_sprite_tile(o->Sprite,0x84);
            set_sprite_tile(o->Sprite + 1,0x84);
            set_sprite_tile(o->Sprite + 2,0x85);
            set_sprite_tile(o->Sprite + 3,0x85);
            set_sprite_prop(o->Sprite + 1,S_FLIPX);
            set_sprite_prop(o->Sprite + 3,S_FLIPX);
            break;

            case Object_Type_Item_RacoonLeaf:
            set_sprite_tile(o->Sprite,0x86);
            set_sprite_tile(o->Sprite + 1,0x87);
            set_sprite_tile(o->Sprite + 2,0x88);
            set_sprite_tile(o->Sprite + 3,0x89);
            break;

            case Object_Type_Item_Tinyshroom:
            set_sprite_tile(o->Sprite,0x8C);
            set_sprite_tile(o->Sprite + 1,0x8D);
            set_sprite_tile(o->Sprite + 2,0x8E);
            set_sprite_tile(o->Sprite + 3,0x8F);
            break;

            case Object_Type_Item_1UP:
            set_sprite_tile(o->Sprite,0x94);
            set_sprite_tile(o->Sprite + 1,0x95);
            set_sprite_tile(o->Sprite + 2,0x82);
            set_sprite_tile(o->Sprite + 3,0x83);
            break;

            case Object_Type_Item_Koopashell:
            set_sprite_tile(o->Sprite,0x90);
            set_sprite_tile(o->Sprite + 1,0x91);
            set_sprite_tile(o->Sprite + 2,0x92);
            set_sprite_tile(o->Sprite + 3,0x93);
            break;

            case Object_type_Item_Star:
            set_sprite_tile(o->Sprite,0x8A);
            set_sprite_tile(o->Sprite + 1,0x8A);
            set_sprite_tile(o->Sprite + 2,0x8B);
            set_sprite_tile(o->Sprite + 3,0x8B);
            set_sprite_prop(o->Sprite + 1,S_FLIPX);
            set_sprite_prop(o->Sprite + 3,S_FLIPX);
            break;
        }

        move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y));
        move_sprite(o->Sprite+1,-(Camera.x - o->hitbox.position.x)+8,-(Camera.y - o->hitbox.position.y));
        move_sprite(o->Sprite+2,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
        move_sprite(o->Sprite+3,-(Camera.x - o->hitbox.position.x)+8,-(Camera.y - o->hitbox.position.y) + 8);

    }else
    {
        if(o->enabled)
        {
            o->Sprite = Add_Sprite(4);
        }
    }
}

void Display_Koopa(Enemy *e) BANKED
{
    if(e->Sprite_tile != 0)
    {
        switch (e->State)
        {
            case Animator_Enemy_Koopa_State_Move:
            set_sprite_prop(e->Sprite_tile,((e->dir.x > 0) * S_FLIPX));
            set_sprite_prop(e->Sprite_tile+1,((e->dir.x > 0) * S_FLIPX));
            set_sprite_prop(e->Sprite_tile+2,((e->dir.x > 0) * S_FLIPX));
            set_sprite_prop(e->Sprite_tile+3,((e->dir.x > 0) * S_FLIPX));
            set_sprite_prop(e->Sprite_tile+4,((e->dir.x > 0) * S_FLIPX));
                switch (e->animState)
                {
                    case 2:
                    case 3:
                    case 6:
                    case 7:
                    move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x) - 3 + 14 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y) - 7);
                    move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) - 3 + 14 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y) + 1);
                    move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x) + 5 - 2 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y) + 1);
                    move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y) + 9);
                    move_sprite(e->Sprite_tile+4,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x < 0),-(Camera.y - e->Hitbox.position.y) + 9);
                    break;
            
                    default:
                    move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x) - 3 + 14 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y) - 8);
                    move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) - 3 + 14  * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y));
                    move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x) + 5 - 2 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y));
                    move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y) + 8);
                    move_sprite(e->Sprite_tile+4,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x < 0),-(Camera.y - e->Hitbox.position.y) + 8);    
                    break;
                }
            break;
    
            case Animator_Enemy_Koopa_State_Shell_Idle:
            set_sprite_prop(e->Sprite_tile,0);
            set_sprite_prop(e->Sprite_tile+1,S_FLIPX);
            set_sprite_prop(e->Sprite_tile+2,0);
            set_sprite_prop(e->Sprite_tile+3,S_FLIPX);
            move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y));
            move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) + 8,-(Camera.y - e->Hitbox.position.y));
            move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x),-(Camera.y - e->Hitbox.position.y) + 8);
            move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x)+ 8,-(Camera.y - e->Hitbox.position.y) + 8);
            break;
    
            case  Animator_Enemy_Koopa_State_Shell_Move:
            move_sprite(e->Sprite_tile,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x < 0),-(Camera.y - e->Hitbox.position.y));
            move_sprite(e->Sprite_tile+1,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y));
            move_sprite(e->Sprite_tile+2,-(Camera.x - e->Hitbox.position.x) + 8 * (e->dir.x < 0),-(Camera.y - e->Hitbox.position.y) + 8);
            move_sprite(e->Sprite_tile+3,-(Camera.x - e->Hitbox.position.x) + 8  * (e->dir.x > 0),-(Camera.y - e->Hitbox.position.y) + 8);
            break;
        }
    }
}