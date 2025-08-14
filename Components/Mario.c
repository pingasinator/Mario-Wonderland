#include "../include/Mathf.h"
#include "../include/Mario.h"
#include "../include/Camera.h"
#include "../include/GameSystem.h"
#include "../include/Sprite.h"
#include "../include/Objects.h"
#include "../include/Animations/Mario/Mario.h"
#include "../include/Animations/Mario/RacoonMario.h"
#include "../include/Level.h"

#include <gb/gb.h>
#include <stdlib.h>

extern Vector2 Camera;
extern char Time;
extern char Lifes;

extern Level currentLevel;
extern Scene CurrentScene;
extern EndLevelObject currentEndLevelObject;

extern unsigned char allInputsDown[];
extern unsigned char allInputsPressed[];
extern unsigned char Mario_Animator_State;
extern unsigned char Mario_animState;

extern unsigned char SceneTransitionDelay;

#pragma bank 10

Vector2 Mario_Velocity = {.x=0,.y=0};

Collision Mario_Hitbox = {.position={.x=0,.y=0},.pixeloffset={.x=0,.y=-10},.pixelsize={.x=7,.y=10}};

unsigned char Mario_Transformation = 0;

unsigned char Mario_State;
char Mario_runningProg = 0;
char Mario_isRunning = 0;

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

void init_Mario(int x,int y)BANKED
{
    Mario_Hitbox.position.x = x;
    Mario_Hitbox.position.y = y;
    Mario_Velocity.x = 0;
    Mario_Velocity.y = 0;
    Mario_State = Mario_State_Neutral;
    deathJumpdelay = 30;
    DeathTime = 45;
    death_init = 0;
    Mario_RecoveryTime = 0;
    Mario_onGround = 0;
    Mario_animState = 0;
    Mario_runningProg = 0;
    Mario_isRunning = 0;
}

void Update_Mario(void)BANKED
{
    switch (Mario_State)
    {
        case Mario_State_Neutral:

        Mario_dir = allInputsPressed[Joy_Button_LEFT] ? -1 : allInputsPressed[Joy_Button_RIGHT] ? 1 : Mario_dir;
    
        Mario_maxSpeed = Mario_isRunning ? Time * 6 : allInputsPressed[Joy_Button_B] ? Time * 4 : Time * 2;
        Mario_RecoveryTime -= Mario_RecoveryTime > 0 ? Time : 0;
    
        if(allInputsDown[Joy_Button_LEFT] || allInputsDown[Joy_Button_RIGHT])
        {
            WalkDelay = 2;
            decreaseDelay = 3;
        }else if((allInputsPressed[Joy_Button_LEFT] || allInputsPressed[Joy_Button_RIGHT]) &&! (Mario_onGround && allInputsPressed[Joy_Button_DOWN]))
        {
            WalkDelay -= Time;
            if(WalkDelay <= 0)
            {
                Mario_Velocity.x += allInputsPressed[Joy_Button_RIGHT] ? Time * 2 : allInputsPressed[Joy_Button_LEFT] ? Time * -2 : 0;
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

        if(allInputsDown[Joy_Button_B] && Mario_Transformation == 2)
        { 
            Object_Create(Object_Type_Fireball,Mario_Hitbox.position.x + Mario_dir * 8,Mario_Hitbox.position.y,Mario_dir);
        }

        Mario_Update_CheckGround();

        if(!Mario_onGround)
        {
            Mario_Update_AirMovement();

        }else
        {
            Mario_Update_GroundMovement();
        }

        Mario_Update_Speed();
        Mario_Update_Physics();

        MoveCamera( Mario_Hitbox.position.x > Camera.x + 96 ? Mario_Hitbox.position.x - (Camera.x + 96) : Mario_Hitbox.position.x < Camera.x + 80 ? Mario_Hitbox.position.x - (Camera.x + 80) : 0,
        Mario_Hitbox.position.y < Camera.y + 56 ? Mario_Hitbox.position.y - (Camera.y + 56) : Mario_Hitbox.position.y > Camera.y + 88 ? Mario_Hitbox.position.y - (Camera.y + 88) : 0);

        if(Mario_Hitbox.position.y > CurrentScene.Width * 16)
        {
            Mario_State = Mario_State_Dead;
            Mario_Transformation = 0;
            Lifes--;
            Time = 0;
        }

        if(allInputsDown[Joy_Button_START])
        {
            Pause();
        }
        break;

        case Mario_State_Win:
        Mario_isRunning = 0;
        Mario_Update_CheckGround();
        Mario_Update_AirMovement();
        Mario_Update_Physics();
        MoveCamera( Mario_Hitbox.position.x > Camera.x + 96 ? Mario_Hitbox.position.x - (Camera.x + 96) : Mario_Hitbox.position.x < Camera.x + 80 ? Mario_Hitbox.position.x - (Camera.x + 80) : 0,
        Mario_Hitbox.position.y < Camera.y + 56 ? Mario_Hitbox.position.y - (Camera.y + 56) : Mario_Hitbox.position.y > Camera.y + 88 ? Mario_Hitbox.position.y - (Camera.y + 88) : 0);
        if(Mario_onGround)
        {

            if(Mario_Hitbox.position.x <= currentEndLevelObject.hitbox.position.x + 16 * 3)
            {
                Mario_Velocity.x = Sign(Mario_Hitbox.position.x - currentEndLevelObject.hitbox.position.x + 16 * 3) * 3;
                Mario_Update_GroundMovement();
            }else
            {
                Mario_Velocity.x = 0;
                Mario_Animator_State = Animator_Mario_State_Win;
            }
        }
        Mario_Velocity.x = Clamp(Mario_Velocity.x,-2,2);
        break;
    
        case Mario_State_Dead:
        Mario_Update_Death();
        break;

        case Mario_State_EnterPipe:
        Mario_Animator_State=Animator_Mario_State_Idle;
        if(SceneTransitionDelay <= 0)
        {
            Time=1;
            Mario_State=Mario_State_Neutral;
            Level_Set_Next_Scene();
        }else
        {
            Time=0;
            Mario_Hitbox.position.y++;
            SceneTransitionDelay--;
        }
        break;
    }
    Anim_Mario_Update();
}

void Mario_Update_AirMovement(void) BANKED
{
    Mario_Velocity.y += (!allInputsPressed[Joy_Button_A] && Mario_Velocity.y < 0 &&! Mario_State == Mario_State_Win) * 2;
    Mario_Velocity.y += (Mario_State == Mario_State_Win);
    Mario_Velocity.y = Mario_Transformation == 3 && allInputsPressed[Joy_Button_A] &&! Mario_isRunning &&! Mario_State == Mario_State_Win && Mario_Velocity.y > 0 ? 2 : Mario_Transformation == 3 && allInputsPressed[Joy_Button_A] && Mario_isRunning &&! Mario_State == Mario_State_Win ? -4 : Mario_Velocity.y;
    
    if(Mario_Velocity.y > 0)
    {
        Mario_Animator_State = Mario_isRunning ? Animator_Mario_State_Jump_Run : allInputsPressed[Joy_Button_A] && Mario_Transformation == 3 ? Animator_Mario_State_Racoon_Glide : Animator_Mario_State_Fall;
    }else
    {

        Mario_Animator_State = Mario_isRunning && allInputsPressed[Joy_Button_A] && Mario_Transformation == 3 ? Animator_Mario_State_Racoon_Fly : Mario_isRunning &&! Mario_State == Mario_State_Win ? Animator_Mario_State_Jump_Run : Animator_Mario_State_Jump;

    }
}

void Mario_Update_Speed(void) BANKED
{
    if(Mario_onGround)
    {
        if(Abs(Mario_Velocity.x) >= 4 )
        {
            Mario_runningProg += 2;
            if(Mario_runningProg >= 100)
            {
                Mario_isRunning = Mario_onGround || (Mario_isRunning &&! Mario_onGround);

            }else if(Mario_onGround)
            {
                Mario_isRunning = 0;
            }

        }else
        {
            Mario_runningProg-=4;
            Mario_isRunning = Mario_onGround ? 0 : Mario_isRunning;
        }
    }else
    {
        Mario_runningProg -= (allInputsPressed[Joy_Button_A] && Mario_Transformation == 3 && Mario_isRunning);
        Mario_isRunning = Mario_runningProg <= 0 ? 0 : Mario_isRunning;
    }
    

    Mario_runningProg = Clamp(Mario_runningProg,0,100);
}

void Mario_Update_GroundMovement(void) BANKED
{
    if(allInputsPressed[Joy_Button_DOWN])
    {
        Mario_Animator_State = Animator_Mario_State_Crounch;
    }else
    {
        if(abs(Mario_Velocity.x) >= 1)
        {
            if((Mario_Velocity.x < 0 && Mario_dir == 1) || (Mario_Velocity.x > 0 && Mario_dir == -1))
            {
                Mario_Animator_State = Animator_Mario_State_Slide;
            }else
            {
                Mario_Animator_State = Mario_isRunning ? Animator_Mario_State_Run : Animator_Mario_State_Move;
            }
        }else
        {
            Mario_Animator_State = Animator_Mario_State_Idle;
        }
    }


    Mario_Velocity.y = allInputsDown[Joy_Button_A] ? -7 : Mario_Velocity.y;
}

void Mario_Update_Death(void) BANKED
{
    deathJumpdelay--;
    Mario_Animator_State = Animator_Mario_State_Death;
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
}

void Mario_Update_Physics(void) BANKED
{
    
    Mario_Velocity.y = Clamp(Mario_Velocity.y,-10,8);
    Mario_Velocity.x = Clamp(Mario_Velocity.x,-Mario_maxSpeed,Mario_maxSpeed);

    Mario_Hitbox.position.x += Mario_Velocity.x;
    Mario_Hitbox.position.y += Mario_Velocity.y;

    Mario_Hitbox.position.x = Clamp(Mario_Hitbox.position.x,0,CurrentScene.Length*16);

    MarioTilemapCollisionPhysics(&Mario_Hitbox,&Mario_Velocity);
}

void Mario_Update_CheckGround(void) BANKED
{
    Mario_onGround = (Get_Tile(Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x - Mario_Hitbox.pixelsize.x,Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y + Mario_Hitbox.pixelsize.y + 1) >= 0x80 || Get_Tile(Mario_Hitbox.position.x + Mario_Hitbox.pixeloffset.x + Mario_Hitbox.pixelsize.x,Mario_Hitbox.position.y + Mario_Hitbox.pixeloffset.y + Mario_Hitbox.pixelsize.y + 1)  >= 0x80);
}

int Set_Transformation(int i)BANKED
{
    Mario_Hitbox.pixeloffset.y = -14;
    Mario_Hitbox.pixelsize.y = 14;
    if(i == 1)
    {
        Mario_Transformation = Mario_Transformation < i ? i : Mario_Transformation;
    }else
    {
        Mario_Transformation = i;
    }

    return Mario_Transformation;
}

void Mario_Hit(void)BANKED
{
    if(Mario_RecoveryTime <= 0)
    {
        Mario_RecoveryTime = 30;
        switch(Mario_Transformation)
        {
            case 0:
            Mario_Set_Death();
            break;

            case 1:
            Mario_Transformation = 0;
            Mario_Hitbox.pixeloffset.y = -10;
            Mario_Hitbox.pixelsize.y = 10;
            break;
    
            default:
            Mario_Transformation = 1;
            break;
        }
    }
}

void Mario_Set_Death(void)BANKED
{
    Mario_State = Mario_State_Dead;
    Mario_Transformation = 0;
    Time = 0;
    Lifes -= 1;
}