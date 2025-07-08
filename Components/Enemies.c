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

#pragma bank 11

extern Vector2 Camera;
extern char Time;

extern Vector2 Mario_Velocity;
extern Collision Mario_Hitbox;
extern char Mario_Star;
extern char Mario_dir;
extern char Mario_dead;
extern char Mario_Win;

Enemy *AllEnemies = NULL;
int Enemies_Number = 0;
const Enemy Goomba={.type=Enemy_Type_Goomba,.Sprite_tile=0,.Sprite_size=4,.dir.x=-1,.dead=0,.Knockback=0,.deathDelay=10,.Hitbox={.pixelsize={.x=8,.y=8},.pixeloffset={.x=0,.y=-8}}};
const Enemy Koopa={.type=Enemy_Type_Koopa,.Sprite_tile=0,.Sprite_size=5,.dir.x=-1,.dead=0,.Knockback=0,.deathDelay=10,.Hitbox={.pixelsize={.x=8,.y=8},.pixeloffset={.x=0,.y=-8}}};

void Set_All_Enemies(int Level)NONBANKED
{
    if(AllEnemies != NULL)
    {
        free(AllEnemies);
    }
    Enemies_Number = GetLevel(Level).EnemiesCount;
    AllEnemies = malloc(Enemies_Number * sizeof(Enemy));
    memcpy(AllEnemies,GetLevel(Level).Enemies,Enemies_Number * sizeof(Enemy));

    for(int i = 0; i < Enemies_Number;i++)
    {
        Vector2 TempPosition;
        TempPosition.x = AllEnemies[i].SpawnPoint.x;
        TempPosition.y = AllEnemies[i].SpawnPoint.y;
        switch(AllEnemies[i].type)
        {
            case Enemy_Type_Goomba:
            AllEnemies[i]=Goomba;
            AllEnemies[i].SpawnPoint=TempPosition;
            break;
             
            case Enemy_Type_Koopa:
            AllEnemies[i]=Koopa;
            AllEnemies[i].SpawnPoint=TempPosition;
            break;
        }
    }
}

void Update_Enemy(void)BANKED
{
    for(int i = 0; i < Enemies_Number;i++)
    {
        if((AllEnemies[i].SpawnPoint.x > Camera.x + 22 * 8 && AllEnemies[i].SpawnPoint.x < Camera.x + 26 * 8 )  || (AllEnemies[i].SpawnPoint.x < Camera.x && AllEnemies[i].SpawnPoint.x > Camera.x - 8 * 4) &&! AllEnemies[i].dead)
        {
            AllEnemies[i].Enabled = 1;
        }
        
        if(AllEnemies[i].Enabled &&! Mario_dead &&! Mario_Win)
        {
            switch(AllEnemies[i].type)
            {
                case Enemy_Type_Goomba:
                Update_Goomba(&AllEnemies[i]);
                break;

                case Enemy_Type_Koopa:
                Update_Koopa(&AllEnemies[i]);
                break;
            }
        }
    }
}

void Update_Goomba(Enemy *e)BANKED
{
        if(!e->Knockback)
        {
            if(!e->dead)
            {
                e->velocity.y += Time;
                e->velocity.x = e->dir.x * Time;
                e->AnimatorState = Animator_Enemy_Goomba_State_Move;
                e->dir.x = Get_Tile(e->Hitbox.position.x + e->Hitbox.pixeloffset.x + e->dir.x * (e->Hitbox.pixelsize.x + 1),e->Hitbox.position.y + e->Hitbox.pixeloffset.y) >= 0x80 ? e->dir.x - 2 * Sign(e->dir.x) : e->dir.x;

                if(!Mario_dead && !Mario_Win && OnCollision(e->Hitbox,Mario_Hitbox))  
                {
                    if(Mario_Star)
                    {
                        Enemy_KnockBack(e,Mario_dir);
                    }else if( Mario_Velocity.y > 0 && Mario_Hitbox.position.y < e->Hitbox.position.y)
                    {
                        e->AnimatorState = Animator_Enemy_Goomba_State_Death;
                        Mario_Velocity.y = -8;
                        e->dead = 1;
                    }else
                    {
                        Mario_Hit();
                    }
                }
            }else
            {
                e->velocity.x = 0;
                e->deathDelay--;
                e->AnimatorState = Animator_Enemy_Goomba_State_Death;
                if(e->deathDelay <= 0)
                {
                    e->Enabled = 0;
                    e->deathDelay = 0;
                    e->Sprite_tile = Remove_Sprite(e->Sprite_tile,e->Sprite_size);
                }
            }

            e->velocity.y = e->Knockback ? e->velocity.y : Clamp(e->velocity.y,-2,2);
            e->Hitbox.position.x += e->velocity.x;
            e->Hitbox.position.y += e->velocity.y;
            TilemapCollisionPhysicsSide(&e->Hitbox,&e->velocity,0);
            Anim_Goomba_Update(e);
        }else
        {
            e->velocity.x = e->dir.x * 2;
            e->velocity.y++;
            e->velocity.y = Clamp(e->velocity.y,-8,8);
            e->Hitbox.position.x += e->velocity.x;
            e->Hitbox.position.y += e->velocity.y;
            e->AnimatorState = Animator_Enemy_Goomba_State_Knockback;
            Anim_Goomba_Update(e);
        }

    if(e->Hitbox.position.x < Camera.x - 8 * 4 || e->Hitbox.position.x > Camera.x + 26 * 8 || e->Hitbox.position.y < Camera.y - 8 || e->Hitbox.position.y > Camera.y + 20 * 8)
    {
        e->Enabled = 0;
        e->Hitbox.position = e->SpawnPoint;
        e->Sprite_tile = Remove_Sprite(e->Sprite_tile,e->Sprite_size);
    }
}

void Update_Koopa(Enemy *e)BANKED
{
    if(!e->Knockback)
    {
        switch(e->State)
        {
            case 0:
                e->velocity.y += Time;
                e->velocity.x = e->dir.x * Time;
                e->Hitbox.pixeloffset.x = Abs(AllEnemies->Hitbox.pixeloffset.x) * e->dir.x;

                Vector2 Raypoint = {.x=e->Hitbox.position.x + e->Hitbox.pixeloffset.x + e->dir.x * (e->Hitbox.pixelsize.x + 2),.y=e->Hitbox.position.y + e->Hitbox.pixeloffset.y  + 7};
                Vector2 Raydir = {.x=0,.y=-1};

                e->AnimatorState = Animator_Enemy_Koopa_State_Move;

                e->dir.x = Raycast(Raypoint,Raydir,14) ? e->dir.x - 2 * Sign(e->dir.x) : e->dir.x;

                if(OnCollision(e->Hitbox,Mario_Hitbox) &&! Mario_dead &&! Mario_Win)  
                {
                    if(Mario_Star)
                    {
                        Enemy_KnockBack(e,Mario_dir);
                    }else if( Mario_Velocity.y > 0 && Mario_Hitbox.position.y < e->Hitbox.position.y)
                    {
                        Mario_Velocity.y = -8;
                        e->State = 1;
                        e->Sprite_tile = Remove_Sprite(e->Sprite_tile,5);
                        e->Sprite_tile = Add_Sprite(4);
                        e->velocity.x = 0;
                    }else
                    {
                        Mario_Hit();
                    }
                }

                e->velocity.y = e->Knockback ? e->velocity.y : Clamp(e->velocity.y,-2,2);
            break;

            case 1:
            e->animState += Time;
            e->velocity.x = Clamp(e->velocity.x,0,0);
            e->AnimatorState = Animator_Enemy_Koopa_State_Shell_Idle;
            if(OnCollisionSide(e->Hitbox,Mario_Hitbox,2))
            {
                e->dir.x = 1;
                e->State = 2;
                e->animState = 0;
            }else if(OnCollisionSide(e->Hitbox,Mario_Hitbox,3))
            {
                e->dir.x = -1;
                e->State = 2;
                e->animState = 0;
            }

            if(OnCollisionSide(e->Hitbox,Mario_Hitbox,1) && Mario_Velocity.y > 0)
            {
                Mario_Velocity.y = -8;
            }
                
            break;

            case 2:
            e->AnimatorState = Animator_Enemy_Koopa_State_Shell_Move;
            Vector2 Raypoint_Shell = {.x=e->Hitbox.position.x + e->Hitbox.pixeloffset.x + e->dir.x * (e->Hitbox.pixelsize.x + 8),.y=e->Hitbox.position.y + e->Hitbox.pixeloffset.y  + 7};
            Vector2 Raydir_Shell = {.x=0,.y=-1};
            e->dir.x = Raycast(Raypoint_Shell,Raydir_Shell,14) ? e->dir.x * -1 : e->dir.x;
            e->velocity.x = e->dir.x * 7;
            e->velocity.y++;
            e->velocity.y = Clamp(e->velocity.y,-4,4);
            if(OnCollisionSide(e->Hitbox,Mario_Hitbox,1) && Mario_Velocity.y > 0)
            {
                e->velocity.x = 0;
                e->State = 1;
                Mario_Velocity.y = -8;
            }else if((OnCollisionSide(e->Hitbox,Mario_Hitbox,2) && e->dir.x < 0) || (OnCollisionSide(e->Hitbox,Mario_Hitbox,3) && e->dir.x > 0))
            {
                Mario_Hit();
            }
            for(int j = 0; j < Enemies_Number;j++)
            {

                if(&AllEnemies[j] != e &&  (OnCollision(e->Hitbox,AllEnemies[j].Hitbox) && AllEnemies[j].Enabled &&! AllEnemies[j].Knockback))
                {
                    Enemy_KnockBack(&AllEnemies[j],e->dir.x);
                }
            }
            break;
        }
                

        e->Hitbox.position.x += e->velocity.x;
        e->Hitbox.position.y += e->velocity.y;

        TilemapCollisionPhysicsSide(&e->Hitbox,&e->velocity,0);

    }else
    {
        e->velocity.x = e->dir.x * 2;
        e->velocity.y++;
        e->velocity.y = Clamp(e->velocity.y,-8,8);
        e->Hitbox.position.x += e->velocity.x;
        e->Hitbox.position.y += e->velocity.y;
        e->AnimatorState = Animator_Enemy_Koopa_State_Knockback;
    }

    Anim_Koopa_Update(e);

    if(e->Hitbox.position.x < Camera.x - 8 * 4 || e->Hitbox.position.x > Camera.x + 26 * 8 || e->Hitbox.position.y < Camera.y - 8 || e->Hitbox.position.y > Camera.y + 20 * 8)
    {
        e->Enabled = 0;
        e->State = 0;
        e->Hitbox.position = e->SpawnPoint;
        if(e->Sprite_tile != 0)
        {
            e->Sprite_tile = Remove_Sprite(e->Sprite_tile,e->Sprite_size);
        }
    }
}

void Update_HamBro(Enemy *e)BANKED
{
    
}

void Enemy_KnockBack(Enemy *e,int dir)BANKED
{
    e->dead = 1;
    e->Knockback = 1;
    e->dir.x = dir;
    e->velocity.y = -8;
}