#include "../include/Animations/Objects.h"
#include "../include/Sprite.h"
#include "../include/Camera.h"

extern Vector2 Camera;

extern unsigned char S_Obj_EndStar_0[];
extern unsigned char S_Obj_EndStar_1[];
extern unsigned char S_Obj_EndStar_2[];

#pragma bank 9

void Anim_Object_Coin(Object *o) BANKED
{
    if(o->Sprite != 0)
    {
        switch ((o->animstate))
        {
            case 0:
            set_sprite_tile(o->Sprite,0x9E);
            set_sprite_tile(o->Sprite+1,0x9F);
            set_sprite_tile(o->Sprite+2,0xA0);
            set_sprite_tile(o->Sprite+3,0xA1);
            set_sprite_prop(o->Sprite + 1,0);

            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y));
            move_sprite(o->Sprite + 2,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
            move_sprite(o->Sprite + 3,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y) + 8);
            break;

            case 2:
            set_sprite_tile(o->Sprite,0xA2);
            set_sprite_tile(o->Sprite+1,0xA2);
            set_sprite_prop(o->Sprite + 1,S_FLIPY);
            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) + 4,-(Camera.y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 4,-(Camera.y - o->hitbox.position.y) + 8);
            hide_sprite(o->Sprite + 2);
            hide_sprite(o->Sprite + 3);
        
            break;
    
            case 4:
                set_sprite_tile(o->Sprite,0xA3);
                set_sprite_tile(o->Sprite+1,0xA3);
                set_sprite_prop(o->Sprite + 1,S_FLIPY);
                move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) + 4,-(Camera.y - o->hitbox.position.y));
                move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 4,-(Camera.y - o->hitbox.position.y) + 8);
                hide_sprite(o->Sprite + 2);
                hide_sprite(o->Sprite + 3);
            break;
        }
    }else
    {
        o->Sprite = Add_Sprite(4);
    }

    o->animstate += 2;
    o->animstate = o->animstate >= 6 ? 0 : o->animstate;
}

void Anim_Object_Block(Object *o) BANKED
{
    if(o->Sprite != 0)
    {
        set_sprite_tile(o->Sprite,0x9A);
        set_sprite_tile(o->Sprite + 1,0x9B);
        set_sprite_tile(o->Sprite + 2,0x9C);
        set_sprite_tile(o->Sprite + 3,0x9D);
        move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y) + 16);
        move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 16,-(Camera.y - o->hitbox.position.y) + 16);
        move_sprite(o->Sprite + 2,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y) + 24);
        move_sprite(o->Sprite + 3,-(Camera.x - o->hitbox.position.x) + 16,-(Camera.y - o->hitbox.position.y) + 24);
    }else
    {
        o->Sprite = Add_Sprite(4);
    }
}

void Anim_Object_Brick(Object *o) BANKED
{
    if(o->Sprite != 0)
    {
        set_sprite_tile(o->Sprite,0xA4);
        set_sprite_tile(o->Sprite + 1,0xA5);
        set_sprite_tile(o->Sprite + 2,0xA6);
        set_sprite_tile(o->Sprite + 3,0xA7);
        move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y) + 16);
        move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 16,-(Camera.y - o->hitbox.position.y) + 16);
        move_sprite(o->Sprite + 2,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y) + 24);
        move_sprite(o->Sprite + 3,-(Camera.x - o->hitbox.position.x) + 16,-(Camera.y - o->hitbox.position.y) + 24);

    }else
    {
        o->Sprite = Add_Sprite(4);
    }
}

void Anim_Object_Fireball(Object *o) BANKED
{
    if(o->Sprite != 0)
    {   
        switch (o->animstate)
        {
            case 0:
            set_sprite_tile(o->Sprite,0x96);
            set_sprite_tile(o->Sprite + 1,0x97);
            set_sprite_prop(o->Sprite,0);
            set_sprite_prop(o->Sprite+ 1,0);
            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) - 8,-(Camera.y - o->hitbox.position.y) + 8);
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
            break;
    
            case 1:
            set_sprite_tile(o->Sprite,0x99);
            set_sprite_tile(o->Sprite + 1,0x98);
            set_sprite_prop(o->Sprite,S_FLIPY + S_FLIPX);
            set_sprite_prop(o->Sprite+ 1,S_FLIPY + S_FLIPX);
            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
            break;

            case 2:
            set_sprite_tile(o->Sprite,0x97);
            set_sprite_tile(o->Sprite + 1,0x96);
            set_sprite_prop(o->Sprite,S_FLIPX + S_FLIPY);
            set_sprite_prop(o->Sprite + 1,S_FLIPX + S_FLIPY);
            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y) + 8);
            break;

            case 3:
            set_sprite_tile(o->Sprite,0x99);
            set_sprite_tile(o->Sprite + 1,0x98);
            set_sprite_prop(o->Sprite,0);
            set_sprite_prop(o->Sprite + 1,0);
            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 16);
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
            break;
        }
    }else
    {
        o->Sprite = Add_Sprite(2);
    }

    o->animstate++;
    o->animstate = o->animstate >= 4 ? 0 : o->animstate;
}

void Anim_Object_EndBlock(EndLevelObject *o) BANKED
{
    if(o->Sprite != 0)
    {
        switch (o->animstate)
        {
            case 0:
            set_sprite_data(0xA8,2,S_Obj_EndStar_0);
            break;
    
            case 4:
            set_sprite_data(0xA8,2,S_Obj_EndStar_1);
            break;

            case 8:
            set_sprite_data(0xA8,2,S_Obj_EndStar_2);
            break;

            case 12:
            set_sprite_data(0xA8,2,S_Obj_EndStar_1);
            break;
        }

        set_sprite_tile(o->Sprite,0xA8);
        set_sprite_tile(o->Sprite+1,0xA8);
        set_sprite_prop(o->Sprite+1,S_FLIPX);
        set_sprite_tile(o->Sprite+2,0xA9);
        set_sprite_prop(o->Sprite+3,S_FLIPX);
        set_sprite_tile(o->Sprite+3,0xA9);
        move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) - 8,-(Camera.y - o->hitbox.position.y));
        move_sprite(o->Sprite+1,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y));
        move_sprite(o->Sprite+2,-(Camera.x - o->hitbox.position.x) - 8,-(Camera.y - o->hitbox.position.y) + 8);
        move_sprite(o->Sprite+3,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
    }else
    {
        o->Sprite = Add_Sprite(4);
    }

    o->animstate += o->state == 0 ? 1 : 4;
    o->animstate = o->animstate >= 16 ? 0 : o->animstate;
}