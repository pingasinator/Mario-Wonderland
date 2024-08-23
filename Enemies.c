#include "include\Enemies.h"
#include "include\Camera.h"
#include "Sprites\Goomba.h"
#include "include\Mario.h"
#include <gb\gb.h>

void init_enemies_sprite(void)
{
    set_sprite_data(128,4,Goomba_Idle);
    set_sprite_data(132,4,Goomba_Move);
    set_sprite_data(136,2,Goomba_Death);
}

void Update_Enemy(Enemy *e)
{
    Vector2 cam;
    cam = GetCamera();

    for(int i= 0; i < 3;i++)
    {
        switch(e->type)
        {
            case 0:
            Update_Goomba(&e[i]);
            break;
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
        e->dir.x = 1;
        e->dead = 0;
        e->start = 1;
    }   

    if(e->position.x > camera.x - 8 * 2 && e->position.x < camera.x + 22 * 8 && e->deathDelay > 0)
    {

        e->Hitbox.position = e->position;

        if(e->dead != 1)
        {
            e->velocity.y++;
            e->velocity.x = e->dir.x;

            switch (e->animState)
            {
                case 0:
                set_sprite_tile(13,128);
                set_sprite_tile(14,129);
                set_sprite_tile(15,130);
                set_sprite_tile(16,131);
                break;
                
                case 5:
                set_sprite_tile(13,132);
                set_sprite_tile(14,133);
                set_sprite_tile(15,134);
                set_sprite_tile(16,135);
                break;
            }

                e->animState++;
                e->animState = e->animState >= 10 ? 0 : e->animState;

                if(OnCollisionSide(e->Hitbox,GetMarioCollision(),&e->velocity,Get_Mario_Velocity_ptr(),1) && Get_Mario_Velocity().y > 0)
                {
                    set_sprite_tile(13,0);
                    set_sprite_tile(14,0);
                    set_sprite_tile(15,136);
                    set_sprite_tile(16,137);
                    Set_Mario_Velocity(Get_Mario_Velocity().x,-10);
                    e->dead = 1;
                }else if(OnCollision(e->Hitbox,GetMarioCollision()))
                {
                    
                }
            }else
            {
                e->velocity.x = 0;
                e->deathDelay--;
                if(e->deathDelay <= 0)
                {
                    e->deathDelay = 0;
                    set_sprite_tile(13,0);
                    set_sprite_tile(14,0);
                    set_sprite_tile(15,0);
                    set_sprite_tile(16,0);
                }
            }

    Vector2 Rpos = {.x=e->position.x + Sign(e->dir.x) * 12,.y=e->position.y-1};
    Vector2 Rdir = {.x=0,.y=-1};

    e->dir.x = Raycast(Rpos,Rdir,e->velocity,8) ? e->dir.x - 2 * Sign(e->dir.x) : e->dir.x;
    e->velocity.y = Clamp(e->velocity.y,-2,TileMapCollisionSide(e->Hitbox,&e->velocity,0) ? 0 : 2);

    e->position.x += e->velocity.x;
    e->position.y += e->velocity.y;
    
    move_sprite(13,-(camera.x - e->position.x),-(camera.y - e->position.y));
    move_sprite(14,-(camera.x - e->position.x)+8,-(camera.y - e->position.y));
    move_sprite(15,-(camera.x - e->position.x),-(camera.y - e->position.y) + 8);
    move_sprite(16,-(camera.x - e->position.x)+8,-(camera.y - e->position.y) + 8);
    }
    
}