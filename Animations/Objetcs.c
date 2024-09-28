#include "..\include\Animations\Objects.h"
#include "..\include\Sprite.h"
#include "..\include\Camera.h"

void Anim_Object_Coin(Object *o)
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

            move_sprite(o->Sprite,-(GetCamera().x - o->position.x) + 8,-(GetCamera().y - o->position.y) + 16);
            move_sprite(o->Sprite + 1,-(GetCamera().x - o->position.x) + 16,-(GetCamera().y - o->position.y) + 16);
            move_sprite(o->Sprite + 2,-(GetCamera().x - o->position.x) + 8,-(GetCamera().y - o->position.y) + 24);
            move_sprite(o->Sprite + 3,-(GetCamera().x - o->position.x) + 16,-(GetCamera().y - o->position.y) + 24);
        }

        break;

        case 2:
        if(o->Sprite != 0)
        {
            set_sprite_tile(o->Sprite,0x98);
            set_sprite_tile(o->Sprite+1,0x98);
            set_sprite_prop(o->Sprite + 1,S_FLIPY);
            move_sprite(o->Sprite,-(GetCamera().x - o->position.x) + 12,-(GetCamera().y - o->position.y) + 16);
            move_sprite(o->Sprite + 1,-(GetCamera().x - o->position.x) + 12,-(GetCamera().y - o->position.y) + 24);
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

            move_sprite(o->Sprite,-(GetCamera().x - o->position.x) + 12,-(GetCamera().y - o->position.y) + 16);
            move_sprite(o->Sprite + 1,-(GetCamera().x - o->position.x) + 12,-(GetCamera().y - o->position.y) + 24);
            move_sprite(o->Sprite + 2,0,0);
            move_sprite(o->Sprite + 3,0,0);
        }
        break;
    }
}