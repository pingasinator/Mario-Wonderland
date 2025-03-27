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
        switch(AllEnemies[i].type)
        {
            case 0:
            AllEnemies[i].Hitbox.pixeloffset.x = 0;
            AllEnemies[i].Hitbox.pixeloffset.y = -8;
            AllEnemies[i].Hitbox.pixelsize.x = 8;
            AllEnemies[i].Hitbox.pixelsize.y = 7;
            AllEnemies[i].Hitbox.position = AllEnemies[i].Hitbox.position;
            AllEnemies[i].deathDelay = 10;
            AllEnemies[i].Sprite_tile = 0;
            AllEnemies[i].Sprite_size = 4;
            AllEnemies[i].dir.x = -1;
            AllEnemies[i].dead = 0;
            AllEnemies[i].Knockback = 0;
            break;

            case 1:
            AllEnemies[i].Hitbox.pixeloffset.x = 0;
            AllEnemies[i].Hitbox.pixeloffset.y = -8;
            AllEnemies[i].Hitbox.pixelsize.x = 8;
            AllEnemies[i].Hitbox.pixelsize.y = 7;
            AllEnemies[i].Hitbox.position = AllEnemies[i].Hitbox.position;
            AllEnemies[i].deathDelay = 10;
            AllEnemies[i].Sprite_tile = 0;
            AllEnemies[i].Sprite_size = 5;
            AllEnemies[i].dir.x = 1;
            AllEnemies[i].dead = 0;
            AllEnemies[i].Knockback = 0;
            break;
        }
    }
}

void Update_Enemy(void)BANKED
{

    for(int i= 0; i < Enemies_Number;i++)
    {
        if((AllEnemies[i].SpawnPoint.x > Camera.x + 22 * 8 && AllEnemies[i].SpawnPoint.x < Camera.x + 26 * 8 )  || (AllEnemies[i].SpawnPoint.x < Camera.x && AllEnemies[i].SpawnPoint.x > Camera.x - 8 * 4) &&! AllEnemies[i].dead)
        {
            AllEnemies[i].Enabled = 1;
        } 
        if(AllEnemies[i].Enabled &&! Mario_dead &&! Mario_Win)
        {
            switch(AllEnemies[i].type)
            {
                case 0:
                Update_Goomba(i);
                break;

                case 1:
                Update_Koopa(i);
                break;
            }
        }
    }
}

void Update_Goomba(int i)BANKED
{
        if(!AllEnemies[i].Knockback)
        {
            if(!AllEnemies[i].dead)
            {
            
                AllEnemies[i].velocity.y += Time;
                AllEnemies[i].velocity.x = AllEnemies[i].dir.x * Time;

                Anim_Goomba_Move(&AllEnemies[i]);

                AllEnemies[i].dir.x = Get_Tile(AllEnemies[i].Hitbox.position.x + AllEnemies[i].Hitbox.pixeloffset.x + AllEnemies[i].dir.x * (AllEnemies[i].Hitbox.pixelsize.x + 1),AllEnemies[i].Hitbox.position.y + AllEnemies[i].Hitbox.pixeloffset.y) >= 0x80 ? AllEnemies[i].dir.x - 2 * Sign(AllEnemies[i].dir.x) : AllEnemies[i].dir.x;

                if(!Mario_dead && !Mario_Win && OnCollision(AllEnemies[i].Hitbox,Mario_Hitbox))  
                {
                    if(Mario_Star)
                    {
                        Enemy_KnockBack(&AllEnemies[i],Mario_dir);
                    }else if( Mario_Velocity.y > 0 && Mario_Hitbox.position.y < AllEnemies[i].Hitbox.position.y)
                    {
                        Anim_Goomba_Death(&AllEnemies[i]);
                        Mario_Velocity.y = -8;
                        AllEnemies[i].dead = 1;
                    }else
                    {
                        Mario_Hit();
                    }
                }
            }

            AllEnemies[i].velocity.y = AllEnemies[i].Knockback ? AllEnemies[i].velocity.y : Clamp(AllEnemies[i].velocity.y,-2,2);

            AllEnemies[i].Hitbox.position.x += AllEnemies[i].velocity.x;
            AllEnemies[i].Hitbox.position.y += AllEnemies[i].velocity.y;

            TilemapCollisionPhysicsSide(&AllEnemies[i].Hitbox,&AllEnemies[i].velocity,0);

            if(AllEnemies[i].dead)
            {
                AllEnemies[i].velocity.x = 0;
                AllEnemies[i].deathDelay--;
                Anim_Goomba_Death(&AllEnemies[i]);
                if(AllEnemies[i].deathDelay <= 0)
                {
                    AllEnemies[i].Enabled = 0;
                    AllEnemies[i].deathDelay = 0;
                    AllEnemies[i].Sprite_tile = Remove_Sprite(AllEnemies[i].Sprite_tile,AllEnemies[i].Sprite_size);
                }
            }
        }else
        {
            AllEnemies[i].velocity.x = AllEnemies[i].dir.x * 2;
            AllEnemies[i].velocity.y++;
            AllEnemies[i].velocity.y = Clamp(AllEnemies[i].velocity.y,-8,8);
            AllEnemies[i].Hitbox.position.x += AllEnemies[i].velocity.x;
            AllEnemies[i].Hitbox.position.y += AllEnemies[i].velocity.y;
            Anim_Goomba_Knockback(&AllEnemies[i]);
        }

    if(AllEnemies[i].Hitbox.position.x < Camera.x - 8 * 4 || AllEnemies[i].Hitbox.position.x > Camera.x + 26 * 8 || AllEnemies[i].Hitbox.position.y < Camera.y - 8 || AllEnemies[i].Hitbox.position.y > Camera.y + 20 * 8)
    {
        AllEnemies[i].Enabled = 0;
        AllEnemies[i].Hitbox.position = AllEnemies[i].SpawnPoint;
        if(AllEnemies[i].Sprite_tile != 0)
        {
            AllEnemies[i].Sprite_tile = Remove_Sprite(AllEnemies[i].Sprite_tile,AllEnemies[i].Sprite_size);
        }
    }
}

void Update_Koopa(int i)BANKED
{

    if(!AllEnemies[i].Knockback)
    {
        switch(AllEnemies[i].State)
        {
            case 0:
                AllEnemies[i].velocity.y += Time;
                AllEnemies[i].velocity.x = AllEnemies[i].dir.x * Time;

                Vector2 Raypoint = {.x=AllEnemies[i].Hitbox.position.x + AllEnemies[i].Hitbox.pixeloffset.x + AllEnemies[i].dir.x * (AllEnemies[i].Hitbox.pixelsize.x + 2),.y=AllEnemies[i].Hitbox.position.y + AllEnemies[i].Hitbox.pixeloffset.y  + 7};
                Vector2 Raydir = {.x=0,.y=-1};

                Anim_Koopa_Move(&AllEnemies[i]);

                AllEnemies[i].dir.x = Raycast(Raypoint,Raydir,14) ? AllEnemies[i].dir.x - 2 * Sign(AllEnemies[i].dir.x) : AllEnemies[i].dir.x;

                if(OnCollision(AllEnemies[i].Hitbox,Mario_Hitbox) &&! Mario_dead &&! Mario_Win)  
                {
                    if(Mario_Star)
                    {
                        Enemy_KnockBack(&AllEnemies[i],Mario_dir);
                    }else if( Mario_Velocity.y > 0 && Mario_Hitbox.position.y < AllEnemies[i].Hitbox.position.y)
                    {
                        Mario_Velocity.y = -10;
                        AllEnemies[i].State = 1;
                        AllEnemies[i].Sprite_tile = Remove_Sprite(AllEnemies[i].Sprite_tile,5);
                        AllEnemies[i].Sprite_tile = Add_Sprite(4);
                        AllEnemies[i].velocity.x = 0;
                    }else
                    {
                        Mario_Hit();
                    }
                }

                AllEnemies[i].velocity.y = AllEnemies[i].Knockback ? AllEnemies[i].velocity.y : Clamp(AllEnemies[i].velocity.y,-2,2);
            break;

            case 1:
            AllEnemies[i].animState += Time;
            AllEnemies[i].velocity.x = Clamp(AllEnemies[i].velocity.x,0,0);
            Anim_Koopa_Shell_Idle(&AllEnemies[i]);
            if(OnCollisionSide(AllEnemies[i].Hitbox,Mario_Hitbox,2))
            {
                AllEnemies[i].dir.x = 1;
                AllEnemies[i].State = 2;
                AllEnemies[i].animState = 0;
            }else if(OnCollisionSide(AllEnemies[i].Hitbox,Mario_Hitbox,3))
            {
                AllEnemies[i].dir.x = -1;
                AllEnemies[i].State = 2;
                AllEnemies[i].animState = 0;
            }

            if(OnCollisionSide(AllEnemies[i].Hitbox,Mario_Hitbox,1) && Mario_Velocity.y > 0)
            {
                Mario_Velocity.y = -10;
            }

            if(AllEnemies[i].animState >= 60)
            {   
                AllEnemies[i].State = 0;
                AllEnemies[i].animState = 0;
                AllEnemies[i].Sprite_tile = Remove_Sprite(AllEnemies[i].Sprite_tile,4);
            }
                
            break;

            case 2:
            Anim_Koopa_Shell_Move(&AllEnemies[i]);
            Vector2 Raypoint_Shell = {.x=AllEnemies[i].Hitbox.position.x + AllEnemies[i].Hitbox.pixeloffset.x + AllEnemies[i].dir.x * (AllEnemies[i].Hitbox.pixelsize.x + 8),.y=AllEnemies[i].Hitbox.position.y + AllEnemies[i].Hitbox.pixeloffset.y  + 7};
            Vector2 Raydir_Shell = {.x=0,.y=-1};
            AllEnemies[i].dir.x = Raycast(Raypoint_Shell,Raydir_Shell,14) ? AllEnemies[i].dir.x * -1 : AllEnemies[i].dir.x;
            AllEnemies[i].velocity.x = AllEnemies[i].dir.x * 7;
            AllEnemies[i].velocity.y++;
            AllEnemies[i].velocity.y = Clamp(AllEnemies[i].velocity.y,-4,4);
            if(OnCollisionSide(AllEnemies[i].Hitbox,Mario_Hitbox,1) && Mario_Velocity.y > 0)
            {
                AllEnemies[i].velocity.x = 0;
                AllEnemies[i].State = 1;
                Mario_Velocity.y = -10;
            }else if((OnCollisionSide(AllEnemies[i].Hitbox,Mario_Hitbox,2) && AllEnemies[i].dir.x < 0) || (OnCollisionSide(AllEnemies[i].Hitbox,Mario_Hitbox,3) && AllEnemies[i].dir.x > 0))
            {
                Mario_Hit();
            }
            for(int j = 0; j < Enemies_Number;j++)
            {

                if(&AllEnemies[j] != &AllEnemies[i] &&  (OnCollision(AllEnemies[i].Hitbox,AllEnemies[j].Hitbox) && AllEnemies[j].Enabled &&! AllEnemies[j].Knockback))
                {
                    Enemy_KnockBack(&AllEnemies[j],AllEnemies[i].dir.x);
                }
            }
            break;
        }
                

        AllEnemies[i].Hitbox.position.x += AllEnemies[i].velocity.x;
        AllEnemies[i].Hitbox.position.y += AllEnemies[i].velocity.y;

        TilemapCollisionPhysicsSide(&AllEnemies[i].Hitbox,&AllEnemies[i].velocity,0);

    }else
    {
        AllEnemies[i].velocity.x = AllEnemies[i].dir.x * 2;
        AllEnemies[i].velocity.y++;
        AllEnemies[i].velocity.y = Clamp(AllEnemies[i].velocity.y,-8,8);
        AllEnemies[i].Hitbox.position.x += AllEnemies[i].velocity.x;
        AllEnemies[i].Hitbox.position.y += AllEnemies[i].velocity.y;
        Anim_Koopa_Knockback(&AllEnemies[i]);
    }

    if(AllEnemies[i].Hitbox.position.x < Camera.x - 8 * 4 || AllEnemies[i].Hitbox.position.x > Camera.x + 26 * 8 || AllEnemies[i].Hitbox.position.y < Camera.y - 8 || AllEnemies[i].Hitbox.position.y > Camera.y + 20 * 8)
    {
        AllEnemies[i].Enabled = 0;
        AllEnemies[i].State = 0;
        AllEnemies[i].Hitbox.position = AllEnemies[i].SpawnPoint;
        if(AllEnemies[i].Sprite_tile != 0)
        {
            AllEnemies[i].Sprite_tile = Remove_Sprite(AllEnemies[i].Sprite_tile,AllEnemies[i].Sprite_size);
        }
    }
}

void Update_HamBro(int i)BANKED
{
    
}

void Enemy_KnockBack(Enemy *e,int dir)BANKED
{
    e->dead = 1;
    e->Knockback = 1;
    e->dir.x = dir;
    e->velocity.y = -8;
}