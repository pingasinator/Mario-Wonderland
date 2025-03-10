#include "..\include\Animations\Objects.h"
#include "..\include\Sprite.h"
#include "..\include\Camera.h"

extern Vector2 Camera;

#pragma bank 12

void Anim_Object_Coin(Object *o) BANKED
{
    if(o->Sprite == 0)
    {
        o->Sprite = Add_Sprite(4);
    }

    switch ((o->animstate))
    {
        case 0:

        if(o->Sprite != 0)
        {
            set_sprite_tile(o->Sprite,0x94);
            set_sprite_tile(o->Sprite+1,0x95);
            set_sprite_tile(o->Sprite+2,0x96);
            set_sprite_tile(o->Sprite+3,0x97);
            set_sprite_prop(o->Sprite + 1,0);

            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y));
            move_sprite(o->Sprite + 2,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
            move_sprite(o->Sprite + 3,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y) + 8);
        }

        break;

        case 2:
        if(o->Sprite != 0)
        {
            set_sprite_tile(o->Sprite,0x98);
            set_sprite_tile(o->Sprite+1,0x98);
            set_sprite_prop(o->Sprite + 1,S_FLIPY);
            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) + 4,-(Camera.y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 4,-(Camera.y - o->hitbox.position.y) + 8);
            move_sprite(o->Sprite + 2,0,0);
            move_sprite(o->Sprite + 3,0,0);
        }
        break;
    
        case 4:
        if(o->Sprite != 0)
        {
            set_sprite_tile(o->Sprite,0x99);
            set_sprite_tile(o->Sprite+1,0x99);
            set_sprite_prop(o->Sprite + 1,S_FLIPY);

            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) + 4,-(Camera.y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 4,-(Camera.y - o->hitbox.position.y) + 8);
            move_sprite(o->Sprite + 2,0,0);
            move_sprite(o->Sprite + 3,0,0);
        }
        break;
    }
}

void Anim_Object_Block(Object *o) BANKED
{
    if(o->Sprite != 0)
    {
        set_sprite_tile(o->Sprite,0x90);
        set_sprite_tile(o->Sprite + 1,0x91);
        set_sprite_tile(o->Sprite + 2,0x92);
        set_sprite_tile(o->Sprite + 3,0x93);
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

void Anim_Object_Fireball(Object *o) BANKED
{

    if(o->Sprite != 0)
    {   
        switch (o->animstate)
        {
            case 0:
            set_sprite_tile(o->Sprite,0x8C);
            set_sprite_tile(o->Sprite + 1,0x8D);
            set_sprite_prop(o->Sprite,0);
            set_sprite_prop(o->Sprite+ 1,0);
            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) - 8,-(Camera.y - o->hitbox.position.y) + 8);
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
            break;
    
            case 1:
            set_sprite_tile(o->Sprite,0x8F);
            set_sprite_tile(o->Sprite + 1,0x8E);
            set_sprite_prop(o->Sprite,S_FLIPY + S_FLIPX);
            set_sprite_prop(o->Sprite+ 1,S_FLIPY + S_FLIPX);
            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
            break;

            case 2:
            set_sprite_tile(o->Sprite,0x8D);
            set_sprite_tile(o->Sprite + 1,0x8C);
            set_sprite_prop(o->Sprite,S_FLIPX + S_FLIPY);
            set_sprite_prop(o->Sprite + 1,S_FLIPX + S_FLIPY);
            move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
            move_sprite(o->Sprite + 1,-(Camera.x - o->hitbox.position.x) + 8,-(Camera.y - o->hitbox.position.y) + 8);
            break;

            case 3:
            set_sprite_tile(o->Sprite,0x8F);
            set_sprite_tile(o->Sprite + 1,0x8E);
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
}

void Anim_Object_EndBlock(EndLevelObject *o) BANKED
{
    if(o->Sprite != 0)
    {
        switch (o->animstate)
        {
            case 0:
            set_sprite_prop(o->Sprite + 1,0);
            set_sprite_prop(o->Sprite + 3,0);
            set_sprite_tile(o->Sprite,0x80);
            set_sprite_tile(o->Sprite+1,0x81);
            set_sprite_tile(o->Sprite+2,0x82);
            set_sprite_tile(o->Sprite+3,0x83);
            break;
    
            case 4:
            set_sprite_prop(o->Sprite + 1,S_FLIPX);
            set_sprite_prop(o->Sprite + 3,S_FLIPX);
            set_sprite_tile(o->Sprite,0x84);
            set_sprite_tile(o->Sprite+1,0x84);
            set_sprite_tile(o->Sprite+2,0x85);
            set_sprite_tile(o->Sprite+3,0x85);
            break;

            case 8:
            set_sprite_prop(o->Sprite + 1,0);
            set_sprite_prop(o->Sprite + 3,0);
            set_sprite_tile(o->Sprite,0x86);
            set_sprite_tile(o->Sprite+1,0x87);
            set_sprite_tile(o->Sprite+2,0x88);
            set_sprite_tile(o->Sprite+3,0x89);
            break;

            case 12:
            set_sprite_prop(o->Sprite + 1,S_FLIPX);
            set_sprite_prop(o->Sprite + 3,S_FLIPX);
            set_sprite_tile(o->Sprite,0x8A);
            set_sprite_tile(o->Sprite+1,0x8A);
            set_sprite_tile(o->Sprite+2,0x8B);
            set_sprite_tile(o->Sprite+3,0x8B);
            break;
        }

        move_sprite(o->Sprite,-(Camera.x - o->hitbox.position.x) - 8,-(Camera.y - o->hitbox.position.y));
        move_sprite(o->Sprite+1,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y));
        move_sprite(o->Sprite+2,-(Camera.x - o->hitbox.position.x) - 8,-(Camera.y - o->hitbox.position.y) + 8);
        move_sprite(o->Sprite+3,-(Camera.x - o->hitbox.position.x),-(Camera.y - o->hitbox.position.y) + 8);
    }else
    {
        o->Sprite = Add_Sprite(4);
    }

    o->animstate++;
    o->animstate = o->animstate >= 16 ? 0 : o->animstate;
}