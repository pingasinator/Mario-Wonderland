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
extern char Time;
extern char Lifes;

extern Level currentLevel;

extern unsigned char allInputsDown[];
extern unsigned char allInputsPressed[];

#pragma bank 26

Vector2 Mario_Velocity = {.x=0,.y=0};

Collision Mario_Hitbox = {.position={.x=0,.y=0},.pixeloffset={.x=0,.y=-10},.pixelsize={.x=7,.y=10}};

char Mario_State = 0;
char Mario_dead = 0;

char deathJumpdelay = 30;
char DeathTime = 45;

char WalkDelay;
char decreaseDelay;
char decreaseJump;

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
    Mario_dead = 0;
    deathJumpdelay = 30;
    DeathTime = 45;
    death_init = 0;
    Mario_RecoveryTime = 0;
    Mario_onGround = 0;
    Mario_animState = 0;
}

void Update_Mario(void)BANKED
{
    
    if(!Mario_dead)
    {
        Mario_dir = allInputsPressed[2] ? -1 : allInputsPressed[1] ? 1 : Mario_dir;
    
        Mario_maxSpeed = allInputsPressed[6] ? Time * 6 : Time * 4;
        Mario_RecoveryTime -= Mario_RecoveryTime > 0 ? 1 : 0;
    
        if(allInputsDown[2] || allInputsDown[1])
        {
            WalkDelay = 2;
            decreaseDelay = 3;
        }else if(allInputsPressed[2] || allInputsPressed[1])
        {
            WalkDelay -= Time;
            if(WalkDelay <= 0)
            {
                Mario_Velocity.x += allInputsPressed[1] ? Time * 2 : allInputsPressed[2] ? Time * -2 : 0;
                WalkDelay = 2;
            }
        }else
        {
            decreaseDelay -= Time;
            if(decreaseDelay <= 0)
            {
                Mario_Velocity.x -= Sign(Mario_Velocity.x);
                decreaseDelay = 3;
            }

        }
        
            decreaseJump -= Time;
            if(decreaseJump <= 0)
            {
                Mario_Velocity.y++;
                decreaseJump=2;
            }

        if(allInputsDown[6] && Mario_State == 2)
        {
            Make_FireBall(Mario_dir,Mario_Hitbox.position.x + Mario_dir * 8,Mario_Hitbox.position.y);
        }

        if(Mario_Star)
        {
            Anim_Mario_Star();
        }

        Vector2 Raydir = {.x=0,.y=1};
        Vector2 v = {.x= Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + Mario_Hitbox.pixelsize.x,.y=Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y + Mario_Hitbox.pixelsize.y};
        Vector2 w = {.x= Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x - Mario_Hitbox.pixelsize.x,.y=Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y + Mario_Hitbox.pixelsize.y};
        Mario_onGround = (Raycast(v,Raydir,2) || Raycast(w,Raydir,2));

        if(!Mario_onGround)
        {
            Mario_Velocity.y += (!allInputsPressed[5] && Mario_Velocity.y < 0) * 2;
            

            if(Mario_Velocity.y >= 1)
            {
                Anim_Mario_Fall(Mario_State);
            }else
            {
                Anim_Mario_Jump(Mario_State);
            }

        }else
        {
             
            if(abs(Mario_Velocity.x) >= 1)
            {
                if((Mario_Velocity.x < 0 && Mario_dir == 1) || (Mario_Velocity.x > 0 && Mario_dir == -1))
                {
                    Anim_Mario_Slide(Mario_State);
                    Mario_animState = 0;
                }else
                {
                    Anim_Mario_Move(Mario_State,Mario_animState);
                    Mario_animState += Time;
                    Mario_animState = Mario_animState >= 6 ? 0 : Mario_animState;
                }
            }else
            {
                Anim_Mario_Idle(Mario_State);
            }

            Mario_Velocity.y = allInputsDown[5] ? -7 : Mario_Velocity.y;
        }

        Get_TileObject();
    
        Mario_Velocity.y = Clamp(Mario_Velocity.y,-10,8);
        Mario_Velocity.x = Clamp(Mario_Velocity.x,-Mario_maxSpeed,Mario_maxSpeed);

        Mario_Hitbox.position.x += Mario_Velocity.x;
        Mario_Hitbox.position.y += Mario_Velocity.y;

        Mario_Hitbox.position.x = Clamp(Mario_Hitbox.position.x,0,currentLevel.Length*16);

        TilemapCollisionPhysics(&Mario_Hitbox,&Mario_Velocity);

        MoveCamera( Mario_Hitbox.position.x > Camera.x + 96 ? Mario_Hitbox.position.x - (Camera.x + 96) : Mario_Hitbox.position.x < Camera.x + 80 ? Mario_Hitbox.position.x - (Camera.x + 80) : 0,
        Mario_Hitbox.position.y < Camera.y + 56 ? Mario_Hitbox.position.y - (Camera.y + 56) : Mario_Hitbox.position.y > Camera.y + 88 ? Mario_Hitbox.position.y - (Camera.y + 88) : 0);


        
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
            Mario_Velocity.y = Clamp(Mario_Velocity.y,-10,8);
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
    
    for(int i = -1; i <= 1; i++)
    {
        unsigned char c = Get_Tile((Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x),(Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y - Mario_Hitbox.pixelsize.y * 2));
        switch (c)
        {
            case 0x04:
            Use_Coin((Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x),(Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y - Mario_Hitbox.pixelsize.y * 2));
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
                Q_Block(c,Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x,Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y - Mario_Hitbox.pixelsize.y * 2);
            }
            break;
        }  

        unsigned char c_Down = Get_Tile((Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x),(Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y + Mario_Hitbox.pixelsize.y));
        switch (c_Down)
        {
            case 0x04:
            Use_Coin((Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + i * Mario_Hitbox.pixelsize.x),(Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y + Mario_Hitbox.pixelsize.y));
            break;

            case 0x02:
            case 0x03:

            break;

            case 0x05:
            case 0x06:
            Mario_Set_Death();
            break;
        }  
    }
    
   
}

void DisplayMario(void)BANKED
{
    
    for(int i = 0; i < 10; i++)
    {
        set_sprite_prop(i,S_FLIPX * (Mario_dir < 0));
    }


    move_sprite(0,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y) - 16);
    move_sprite(1,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir > 0),-(Camera.y - Mario_Hitbox.position.y) - 16);
    move_sprite(2,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y) - 8);
    move_sprite(3,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir > 0),-(Camera.y - Mario_Hitbox.position.y) - 8);
    move_sprite(4,-(Camera.x - Mario_Hitbox.position.x) - 8 + 24 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y));
    move_sprite(5,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y));
    move_sprite(6,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir > 0),-(Camera.y - Mario_Hitbox.position.y));
    move_sprite(7,-(Camera.x - Mario_Hitbox.position.x) - 8 + 24 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y) + 8);
    move_sprite(8,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir < 0),-(Camera.y - Mario_Hitbox.position.y) + 8);
    move_sprite(9,-(Camera.x - Mario_Hitbox.position.x) + 8 * (Mario_dir > 0),-(Camera.y - Mario_Hitbox.position.y) + 8);
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
    return Mario_dead;
}

int Set_Transformation(int i)BANKED
{
    Mario_Hitbox.pixeloffset.y = -14;
    Mario_Hitbox.pixelsize.y = 14;
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
            Mario_Hitbox.pixeloffset.y = -10;
            Mario_Hitbox.pixelsize.y = 10;
            break;
    
            default:
            Mario_State = 1;
            break;
        }
    }
}

void Mario_Set_Death(void)BANKED
{
    Mario_dead = 1;
    Mario_State = 1;
    Time = 0;
    Lifes -= 1;
    Anim_Mario_Death(Mario_Hitbox,Mario_dir);
}

Collision GetMarioCollision(void)BANKED
{
    return Mario_Hitbox;
}