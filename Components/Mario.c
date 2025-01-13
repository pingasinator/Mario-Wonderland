#include "..\include\Mathf.h"
#include "..\include\Mario.h"
#include "..\include\Camera.h"
#include "..\include\GameSystem.h"
#include "..\include\Sprite.h"
#include "..\include\Objects.h"
#include "..\include\Animations\Mario\Mario.h"
#include "..\include\Level.h"

#include <gb\gb.h>
#include <stdlib.h>

extern Vector2 Camera;

#pragma bank 26

Vector2 Mario_Velocity = {.x=0,.y=0};

Collision Mario_Hitbox = {.position={.x=0,.y=0},.pixeloffset={.x=-6,.y=-14},.pixelsize={.x=10,.y=20}};

char Mario_State = 0;
char dead = 0;

char deathJumpdelay = 30;
char DeathTime = 45;

char death_init = 0;

char Mario_maxSpeed;

char Mario_Star = 0;

char Mario_RecoveryTime = 0;

char Mario_dir = 1;

char Mario_onGround = 0;

char Mario_animState = 0;

void init_Mario(int x,int y)BANKED
{
    Mario_Hitbox.position.x = x;
    Mario_Hitbox.position.y = y;
    Mario_Velocity.x = 0;
    Mario_Velocity.y = 0;
    Mario_State = 0;
    dead = 0;
    deathJumpdelay = 30;
    DeathTime = 45;
    death_init = 0;
    Mario_RecoveryTime = 0;
    Mario_onGround = 0;
    Mario_animState = 0;
}

void Update_Mario(void)BANKED
{
    
    if(!dead)
    {
        Mario_dir = GetButton(J_LEFT) ? -1 : GetButton(J_RIGHT) ? 1 : Mario_dir;
    
        Mario_maxSpeed = GetButton(J_B) ? Get_Time() * 8 : Get_Time() * 4;
        Mario_RecoveryTime -= Mario_RecoveryTime > 0 ? 1 : 0;
    
        Mario_Velocity.x += GetButton(J_RIGHT) ? Get_Time() * 2 : GetButton(J_LEFT) == 1 ? Get_Time() * -2 : 0;

        Mario_Velocity.x -= Sign(Mario_Velocity.x);
        Mario_Velocity.y += 1;

        if(GetButtonDown(J_B) && Mario_State == 2)
        {
            Make_FireBall(Mario_dir,Mario_Hitbox.position.x + Mario_dir * 8,Mario_Hitbox.position.y);
        }

        if(Mario_Star)
        {
            Anim_Mario_Star();
        }

        Vector2 Raydir = {.x=0,.y=1};
        Vector2 v = {.x= Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + 2,.y=Mario_Hitbox.position.y};
        Vector2 w = {.x= Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + Mario_Hitbox.pixelsize.x - 2,.y=Mario_Hitbox.position.y};
        Mario_onGround = (Raycast(v,Raydir,8) || Raycast(w,Raydir,8));

        if(!Mario_onGround)
        {
            Mario_Velocity.y += !GetButton(J_A) * 2;
            if(Mario_Velocity.y >= 1)
            {
                Anim_Mario_Fall(Mario_State);
            }else
            {
                Anim_Mario_Jump(Mario_State);
            }

        }else
        {
            GetButton(J_A);
            if(abs(Mario_Velocity.x) >= 1)
            {
                if((Mario_Velocity.x < 0 && Mario_dir == 1) || (Mario_Velocity.x > 0 && Mario_dir == -1))
                {
                    Anim_Mario_Slide(Mario_State);
                    Mario_animState = 0;
                }else
                {
                    Anim_Mario_Move(Mario_State,Mario_animState);
                    Mario_animState += Get_Time();
                    Mario_animState = Mario_animState >= 6 ? 0 : Mario_animState;
                }
            }else
            {
                Anim_Mario_Idle(Mario_State);
            }

            Mario_Velocity.y = GetButtonDown(J_A) ? -10 : Mario_Velocity.y;
        }

        Get_TileObject();
    
        Mario_Velocity.y = Clamp(Mario_Velocity.y,-10,5);
        Mario_Velocity.x = Clamp(Mario_Velocity.x,-Mario_maxSpeed,Mario_maxSpeed);

        Mario_Hitbox.position.x += Mario_Velocity.x;
        Mario_Hitbox.position.y += Mario_Velocity.y;

        Mario_Hitbox.position.x = Clamp(Mario_Hitbox.position.x,0,224*16);

        TilemapCollisionPhysics(&Mario_Hitbox,&Mario_Velocity);


        MoveCamera(Mario_Hitbox.position.x - (Camera.x + 88),Mario_Hitbox.position.y - (Camera.y + 80));
        DisplayMario();

    }else
    {
        deathJumpdelay--;

        if(deathJumpdelay <= 0)
        {
            DeathTime--;
            Mario_Velocity.y = !death_init ? -10 : Mario_Velocity.y;
            death_init = 1;
            Mario_Hitbox.position.y += Mario_Velocity.y; 
            Mario_Velocity.y++;
            Mario_Velocity.y = Clamp(Mario_Velocity.y,-10,5);
            if(DeathTime <= 0)
            {
                Set_Level_End();
            }

        }
        delay(30);
        Anim_Mario_Death(Mario_Hitbox,Mario_dir);
    }

}

void Get_TileObject(void)BANKED
{
    
    for(int i = 0; i <= 1; i++)
    {
        unsigned char c = Get_Tile((Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x),(Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y - 5));
        switch (c)
        {
            case 0x01:
            Use_Coin((Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x),(Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y - 5));
            break;

            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x85:
            case 0x86:
            case 0x87:
            case 0x88:
            if(Mario_Velocity.y < 0)
            {
                Q_Block(c,Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x,Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y - 5);
            }
            break;
        }  

        unsigned char c_Down = Get_Tile((Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x),(Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y + Mario_Hitbox.pixelsize.y));
        switch (c_Down)
        {
            case 0x01:
            Use_Coin((Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x),(Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y + Mario_Hitbox.pixelsize.y));
            break;

            case 0x02:
            case 0x03:

            break;

            case 0x04:
            case 0x05:
            Mario_Set_Death();
            break;
        }  
    }
    
   
}

void DisplayMario(void)BANKED
{
    switch (Mario_dir)
    {
        case 1:
        for(int i = 0; i < 10; i++)
        {
            set_sprite_prop(i,0);
        }
        move_sprite(0,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y) - 8);
        move_sprite(1,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y) - 8);
        move_sprite(2,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y));
        move_sprite(3,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y));
        move_sprite(4,-(Camera.x - Mario_Hitbox.position.x)-8,-(Camera.y - Mario_Hitbox.position.y) + 8);
        move_sprite(5,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y) + 8);
        move_sprite(6,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y) + 8);
        move_sprite(7,-(Camera.x - Mario_Hitbox.position.x)-8,-(Camera.y - Mario_Hitbox.position.y) + 16);
        move_sprite(8,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y) + 16);
        move_sprite(9,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y) + 16);
        break;
    
        case -1:
        for(int i = 0; i < 10; i++)
        {
            set_sprite_prop(i,S_FLIPX);
        }
        move_sprite(0,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y) - 8);
        move_sprite(1,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y) - 8);
        move_sprite(2,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y));
        move_sprite(3,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y));
        move_sprite(4,-(Camera.x - Mario_Hitbox.position.x)+16,-(Camera.y - Mario_Hitbox.position.y) + 8);
        move_sprite(5,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y) + 8);
        move_sprite(6,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y) + 8);
        move_sprite(7,-(Camera.x - Mario_Hitbox.position.x)+16,-(Camera.y - Mario_Hitbox.position.y) + 16);
        move_sprite(8,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y) + 16);
        move_sprite(9,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y) + 16);
        break;
    }
}

void Set_Mario_Position(int x,int y)BANKED
{
    Mario_Hitbox.position.x = x;
    Mario_Hitbox.position.y = y;
}


void Set_Mario_Velocity(int x,int y)BANKED
{
    Mario_Velocity.x = x;
    Mario_Velocity.y = y;
}

int Mario_isDead(void)BANKED
{
    return dead;
}

int Set_Transformation(int i)BANKED
{
    if(i == 1)
    {
        Mario_State = Mario_State < i ? i : Mario_State;
    }else
    {
        Mario_State = i;
    }

    return Mario_State;
}

void Mario_Hit(void)BANKED
{
    if(Mario_RecoveryTime <= 0)
    {
        Mario_RecoveryTime = 30;
        switch (Mario_State)
        {
            case 0:
            Mario_Set_Death();
            break;

            case 1:
            Mario_State = 0;
            break;
    
            default:
            Mario_State = 1;
            break;
        }
    }
}

void Mario_Set_Death(void)BANKED
{
    dead = 1;
    Mario_State = 1;
    Set_Time(0);
    Add_Life(-1);
    Anim_Mario_Death(Mario_Hitbox,Mario_dir);
}

Collision GetMarioCollision(void)BANKED
{
    return Mario_Hitbox;
}