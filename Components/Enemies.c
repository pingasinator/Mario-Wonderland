#include "..\include\Enemies.h"
#include "..\include\Camera.h"
#include "..\include\Mario.h"
#include "..\include\Sprite.h"
#include "..\include\Physic.h"

#include "..\include\Animations\Enemies.h"

#include <gb\gb.h>

void Update_Enemy(Enemy *e)
{
    Vector2 cam;
    cam = GetCamera();

    for(int i= 0; i < 3;i++)
    {
        if(!e[i].Destroyed)
        {
            switch(e->type)
            {
                case 0:
                Update_Goomba(&e[i]);
                break;
            }
        }
    }
}

void Update_Goomba(Enemy *e)
{

    Vector2 camera;
    camera  = GetCamera();
    if(e->start != 1)
    {
        e->Hitbox.pixeloffset.x = -6;
        e->Hitbox.pixeloffset.y = -16;
        e->Hitbox.pixelsize.x = 8;
        e->Hitbox.pixelsize.y = 14;
        e->Hitbox.position = e->position;
        e->deathDelay = 10;
        e->Sprite_tile = 0;
        e->Sprite_size = 4;
        e->dir.x = 1;
        e->dead = 0;
        e->start = 1;
    }   

    if(e->position.x > camera.x - 8 * 2 && e->position.x < camera.x + 22 * 8 && e->deathDelay > 0)
    {
        if(e->Sprite_tile == 0)
        {
            e->Sprite_tile = Add_Sprite(e->Sprite_size);
        }
        e->Hitbox.position = e->position;

        if(!e->dead)
        {
            e->velocity.y++;
            e->velocity.x = e->dir.x;

            Anim_Goomba_Move(e);

            e->animState++;
            e->animState = e->animState >= 10 ? 0 : e->animState;

            if(OnCollisionSide(e->Hitbox,GetMarioCollision(),&e->velocity,Get_Mario_Velocity_ptr(),1) && Get_Mario_Velocity().y > 0)
            {
                Anim_Goomba_Death(e);
                Set_Mario_Velocity(Get_Mario_Velocity().x,-10);
                e->dead = 1;

            }
        }


    Vector2 Rpos = {.x=e->position.x + Sign(e->dir.x) * 12,.y=e->position.y-1};
    Vector2 Rdir = {.x=0,.y=-1};

    e->dir.x = Raycast(Rpos,Rdir,8) ? e->dir.x - 2 * Sign(e->dir.x) : e->dir.x;
    e->velocity.y = Clamp(e->velocity.y,-2,2);
    ApplyPhysicsOnSide(&e->Hitbox,&e->velocity,0);

    e->position.x += e->velocity.x;
    e->position.y += e->velocity.y;
    if(e->Sprite_tile != 0)
    {
        move_sprite(e->Sprite_tile,-(camera.x - e->position.x),-(camera.y - e->position.y));
        move_sprite(e->Sprite_tile+1,-(camera.x - e->position.x)+8,-(camera.y - e->position.y));
        move_sprite(e->Sprite_tile+2,-(camera.x - e->position.x),-(camera.y - e->position.y) + 8);
        move_sprite(e->Sprite_tile+3,-(camera.x - e->position.x)+8,-(camera.y - e->position.y) + 8);
    }


        if(e->dead)
        {
            e->velocity.x = 0;
            e->deathDelay--;
            if(e->deathDelay <= 0)
            {
                e->deathDelay = 0;
                e->Sprite_tile = Remove_Sprite(e->Sprite_tile,e->Sprite_size);
                e->Destroyed = 1;
            }
        }
    }else
    {
        if(e->Sprite_tile != 0)
        {
            e->Sprite_tile = Remove_Sprite(e->Sprite_tile,e->Sprite_size);
        }

    }
    
}