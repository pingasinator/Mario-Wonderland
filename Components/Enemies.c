#include "..\include\Enemies.h"
#include "..\include\Camera.h"
#include "..\include\Mario.h"
#include "..\include\Sprite.h"
#include "..\include\GameSystem.h"
#include "..\include\Level.h"

#include "..\include\Animations\Enemies.h"

#include <stdio.h>
#include <stdlib.h>
#include <gb\gb.h>
#include <asm\sm83\string.h>


Enemy *AllEnemies = NULL;
int Length = 0;

void Set_All_Enemies(int Level)
{
    if(AllEnemies != NULL)
    {
        free(AllEnemies);
    }
    Length = GetLevel(Level).EnemiesCount;
    AllEnemies = malloc(Length * sizeof(Enemy));
    memcpy(AllEnemies,GetLevel(Level).Enemies,Length * sizeof(Enemy));
}

Enemy *Get_Enemies(void)
{
    return AllEnemies;
}

void Update_Enemy(void)
{
    Vector2 cam;
    cam = GetCamera();

    for(int i= 0; i < Length;i++)
    {
        if(!AllEnemies[i].Destroyed &&! Mario_isDead())
        {
            switch(AllEnemies[i].type)
            {
                case 0:
                Update_Goomba(&AllEnemies[i]);
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
        e->Hitbox.pixeloffset.x = -8;
        e->Hitbox.pixeloffset.y = -16;
        e->Hitbox.pixelsize.x = 16;
        e->Hitbox.pixelsize.y = 14;
        e->Hitbox.position = e->position;
        e->deathDelay = 10;
        e->Sprite_tile = 0;
        e->Sprite_size = 4;
        e->dir.x = 1;
        e->dead = 0;
        e->start = 1;
    }

    if(e->position.x > camera.x - 8 * 2 && e->position.x < camera.x + 22 * 8 && e->position.y > camera.y - 8 && e->position.y < camera.y + 20 * 8)
    {

        e->position = e->Hitbox.position;

        if(!e->dead)
        {
            
            e->velocity.y += Get_Time();
            e->velocity.x = e->dir.x * Get_Time();

            Anim_Goomba_Move(e);

            e->animState += Get_Time();
            e->animState = e->animState >= 10 ? 0 : e->animState;

            if(OnCollision(e->Hitbox,GetMarioCollision()) &&! Mario_isDead())  
            {
                if( Get_Mario_Velocity().y > 0 && Get_Mario_Position().y < e->position.y)
                {
                    Anim_Goomba_Death(e);
                    Set_Mario_Velocity(Get_Mario_Velocity().x,-10);
                    e->dead = 1;
                }else
                {
                    Mario_Hit();
                }
            }
        }

    e->velocity.y = Clamp(e->velocity.y,-2,2);

    e->Hitbox.position.x += e->velocity.x;
    e->Hitbox.position.y += e->velocity.y;

    TilemapCollisionPhysicsSide(&e->Hitbox,&e->velocity,0);
    e->dir.x = TileMapCollisionSide(&e->Hitbox,e->dir.x > 0 ? 3 : 2) ? e->dir.x - 2 * Sign(e->dir.x) : e->dir.x;
        if(e->dead)
        {
            e->velocity.x = 0;
            e->deathDelay--;
            Anim_Goomba_Death(e);
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