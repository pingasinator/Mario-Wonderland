#include "..\include\Animations\Objects.h"
#include "..\include\Sprite.h"
#include "..\include\Camera.h"

#pragma bank 18

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

            move_sprite(o->Sprite,-(GetCamera().x - o->hitbox.position.x),-(GetCamera().y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(GetCamera().x - o->hitbox.position.x) + 8,-(GetCamera().y - o->hitbox.position.y));
            move_sprite(o->Sprite + 2,-(GetCamera().x - o->hitbox.position.x),-(GetCamera().y - o->hitbox.position.y) + 8);
            move_sprite(o->Sprite + 3,-(GetCamera().x - o->hitbox.position.x) + 8,-(GetCamera().y - o->hitbox.position.y) + 8);
        }

        break;

        case 2:
        if(o->Sprite != 0)
        {
            set_sprite_tile(o->Sprite,0x98);
            set_sprite_tile(o->Sprite+1,0x98);
            set_sprite_prop(o->Sprite + 1,S_FLIPY);
            move_sprite(o->Sprite,-(GetCamera().x - o->hitbox.position.x) + 4,-(GetCamera().y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(GetCamera().x - o->hitbox.position.x) + 4,-(GetCamera().y - o->hitbox.position.y) + 8);
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

            move_sprite(o->Sprite,-(GetCamera().x - o->hitbox.position.x) + 4,-(GetCamera().y - o->hitbox.position.y));
            move_sprite(o->Sprite + 1,-(GetCamera().x - o->hitbox.position.x) + 4,-(GetCamera().y - o->hitbox.position.y) + 8);
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
        move_sprite(o->Sprite,-(GetCamera().x - o->hitbox.position.x) + 8,-(GetCamera().y - o->hitbox.position.y) + 16);
        move_sprite(o->Sprite + 1,-(GetCamera().x - o->hitbox.position.x) + 16,-(GetCamera().y - o->hitbox.position.y) + 16);
        move_sprite(o->Sprite + 2,-(GetCamera().x - o->hitbox.position.x) + 8,-(GetCamera().y - o->hitbox.position.y) + 24);
        move_sprite(o->Sprite + 3,-(GetCamera().x - o->hitbox.position.x) + 16,-(GetCamera().y - o->hitbox.position.y) + 24);
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
        move_sprite(o->Sprite,-(GetCamera().x - o->hitbox.position.x) + 8,-(GetCamera().y - o->hitbox.position.y) + 16);
        move_sprite(o->Sprite + 1,-(GetCamera().x - o->hitbox.position.x) + 16,-(GetCamera().y - o->hitbox.position.y) + 16);
        move_sprite(o->Sprite + 2,-(GetCamera().x - o->hitbox.position.x) + 8,-(GetCamera().y - o->hitbox.position.y) + 24);
        move_sprite(o->Sprite + 3,-(GetCamera().x - o->hitbox.position.x) + 16,-(GetCamera().y - o->hitbox.position.y) + 24);
    }else
    {
        o->Sprite = Add_Sprite(4);
    }
}

void Anim_Object_Mushroom(Object *o) BANKED
{
    if(o->Sprite != 0)
    {
        set_sprite_tile(o->Sprite,0x80);
        set_sprite_tile(o->Sprite + 1,0x81);
        set_sprite_tile(o->Sprite + 2,0x82);
        set_sprite_tile(o->Sprite + 3,0x83);
        move_sprite(o->Sprite,-(GetCamera().x - o->hitbox.position.x),-(GetCamera().y - o->hitbox.position.y));
        move_sprite(o->Sprite + 1,-(GetCamera().x - o->hitbox.position.x) + 8,-(GetCamera().y - o->hitbox.position.y));
        move_sprite(o->Sprite + 2,-(GetCamera().x - o->hitbox.position.x),-(GetCamera().y - o->hitbox.position.y) + 8);
        move_sprite(o->Sprite + 3,-(GetCamera().x - o->hitbox.position.x) + 8,-(GetCamera().y - o->hitbox.position.y) + 8);
    }else
    {
        o->Sprite = Add_Sprite(4);
    }
}

void Anim_Fireball(int animstate)
{
    
}