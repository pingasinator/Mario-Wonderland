#include "..\include\Animations\Enemies.h"
#include "..\include\Sprite.h"
#include "..\include\Camera.h"
#include <gb\gb.h>

#pragma bank 15

void Anim_Goomba_Move(Enemy *e) BANKED
{
    Vector2 camera;
    camera = GetCamera();
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

        move_sprite(e->Sprite_tile,-(camera.x - e->position.x),-(camera.y - e->position.y));
        move_sprite(e->Sprite_tile+1,-(camera.x - e->position.x)+8,-(camera.y - e->position.y));
        move_sprite(e->Sprite_tile+2,-(camera.x - e->position.x),-(camera.y - e->position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(camera.x - e->position.x)+8,-(camera.y - e->position.y) + 8);
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }
}

void Anim_Goomba_Death(Enemy *e) BANKED
{
    Vector2 camera;
    camera  = GetCamera();
    if(e->Sprite_tile != 0)
    {
        set_sprite_tile(e->Sprite_tile,0x00);
        set_sprite_tile(e->Sprite_tile+1,0x00);
        set_sprite_tile(e->Sprite_tile+2,0xAC);
        set_sprite_tile(e->Sprite_tile+3,0xAD);
        move_sprite(e->Sprite_tile,-(camera.x - e->position.x),-(camera.y - e->position.y));
        move_sprite(e->Sprite_tile+1,-(camera.x - e->position.x)+8,-(camera.y - e->position.y));
        move_sprite(e->Sprite_tile+2,-(camera.x - e->position.x),-(camera.y - e->position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(camera.x - e->position.x)+8,-(camera.y - e->position.y) + 8);
    }else
    {
        e->Sprite_tile = Add_Sprite(4);
    }

}