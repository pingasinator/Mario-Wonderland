#include <gb\gb.h>
#include "..\..\include\Sprite.h"
#include "..\..\include\Camera.h"
#include "..\..\include\collision.h"
#include "..\..\include\Objects.h"
#include "..\..\include\GameSystem.h"
#include "..\..\include\Animations\Mario\Mario.h"
#include "..\..\include\Animations\Mario\SmallMario.h"
#include "..\..\include\Animations\Mario\GreatMario.h"
#include "..\..\include\Animations\Mario\FireMario.h"
#include "..\..\include\Animations\Mario\RacoonMario.h"

extern Vector2 Camera;
extern int Time;
extern unsigned char currentMarioPalette;
extern unsigned char allInputsPressed[];
extern char Mario_isRunning;
extern Collision Mario_Hitbox;
extern unsigned char Mario_Transformation;
extern char Mario_Star;

int animstate_Star;
unsigned char Mario_animState;
unsigned char Mario_Animator_State;

#pragma bank 12

void Anim_Mario_Update(void) NONBANKED
{
    if(currentMarioPalette != Mario_Transformation)
    {
        Set_Mario_Palette(Mario_Transformation);
        SWITCH_ROM(10);
    }

    switch (Mario_Animator_State)
    {
        case Animator_Mario_State_Idle:
        Mario_animState = 0;
        Anim_Mario_Idle();
        break;
    
        case Animator_Mario_State_Move:
        Anim_Mario_Move(Mario_animState);
        Mario_animState += Time * (allInputsPressed[Joy_Button_B] || Mario_isRunning ? 2 : 1);
        Mario_animState = Mario_animState >= 6 ? 0 : Mario_animState;
        break;

        case Animator_Mario_State_Run:
        Anim_Mario_Run(Mario_animState);
        Mario_animState += Time * (allInputsPressed[Joy_Button_B] || Mario_isRunning ? 2 : 1);
        Mario_animState = Mario_animState >= 6 ? 0 : Mario_animState;
        break;

        case Animator_Mario_State_Jump:
        Mario_animState = 0;
        Anim_Mario_Jump();
        break;

        case Animator_Mario_State_Jump_Run:
        Anim_Mario_Jump_Run();
        break;

        case Animator_Mario_State_Fall:
        Mario_animState = 0;
        Anim_Mario_Fall();
        break;

        case Animator_Mario_State_Slide:
        Mario_animState = 0;
        Anim_Mario_Slide();
        break;

        case Animator_Mario_State_Crounch:
        Mario_animState = 0;
        Anim_Mario_Crounch();
        break;

        case Animator_Mario_State_Death:
        Mario_animState = 0;
        Anim_Mario_Death();
        break;

        case Animator_Mario_State_Win:
        Mario_animState++;
        Mario_animState = Clamp(Mario_animState,0,60);
        Anim_Mario_Win(Mario_animState);
        break;

        case Animator_Mario_State_Racoon_Fly:
        Anim_Mario_Racoon_Fly(Mario_animState);
        Mario_animState++;
        Mario_animState = Mario_animState >= 6 ? 0 : Mario_animState;
        break;

        case Animator_Mario_State_Racoon_Glide:
        Anim_Mario_Racoon_Glide(Mario_animState);
        Mario_animState++;
        Mario_animState = Mario_animState >= 6 ? 0 : Mario_animState;
        break;
    }

    Anim_Mario_Star();
    DisplayMario();
}

void Anim_Mario_Idle(void) BANKED
{

    switch(Mario_Transformation)
    {
        case 0:
        Anim_Mario_Small_Idle();
        break;

        case 1:
        Anim_Mario_Great_Idle();
        break;

        case 2:
        Anim_Mario_Fire_Idle();
        break;

        case 3:
        Anim_Mario_Racoon_Idle();
        break;
    }


}

void Anim_Mario_Fall(void) BANKED
{

    switch (Mario_Transformation)
    {
        case 0:
        Anim_Mario_Small_Fall();
        break;
    
        case 1:
        Anim_Mario_Great_Fall();
        break;

        case 2:
        Anim_Mario_Fire_Fall();
        break;

        case 3:
        Anim_Mario_Racoon_Fall();
        break;
    }


}

void Anim_Mario_Jump(void) BANKED
{
    switch (Mario_Transformation)
    {
        case 0:
        Anim_Mario_Small_Jump();
        break;
    
        case 1:
        Anim_Mario_Great_Jump();
        break;

        case 2:
        Anim_Mario_Fire_Jump();
        break;

        case 3:
        Anim_Mario_Racoon_Jump();
        break;
    }
}

void Anim_Mario_Jump_Run(void) BANKED
{
    switch (Mario_Transformation)
    {
        case 0:
        Anim_Mario_Small_Jump_Run();
        break;

        case 1:
        Anim_Mario_Great_Jump_Run();
        break;

        case 2:
        Anim_Mario_Fire_Jump_Run();
        break;

        case 3:
        Anim_Mario_Racoon_Jump_Run();
        break;
    }
}

void Anim_Mario_Move(int animstate) BANKED
{
    switch(Mario_Transformation)
    {
        case 0:
        Anim_Mario_Small_Move(animstate);
        break;

        case 1:
        Anim_Mario_Great_Move(animstate);
        break;

        case 2: 
        Anim_Mario_Fire_Move(animstate);
        break;

        case 3:
        Anim_Mario_Racoon_Move(animstate);
        break;
    }
}

void Anim_Mario_Run(int animstate) BANKED
{
    switch (Mario_Transformation)
    {
        case 0:
        Anim_Mario_Small_Run(animstate);
        break;

        case 1:
        Anim_Mario_Great_Run(animstate);
        break;

        case 2:
        Anim_Mario_Fire_Run(animstate);
        break;

        case 3:
        Anim_Mario_Racoon_Run(animstate);
        break;
    }
}

void Anim_Mario_Slide(void) BANKED
{
    switch(Mario_Transformation)
    {
        case 0:
        Anim_Mario_Small_Slide();
        break;

        case 1:
        Anim_Mario_Great_Slide();
        break;

        case 2:
        Anim_Mario_Fire_Slide();
        break;

        case 3:
        Anim_Mario_Racoon_Slide();
        break;
    }
}

void Anim_Mario_Crounch(void) BANKED
{
    switch (Mario_Transformation)
    {
        case 0:
        Anim_Mario_Small_Crounch();
        break;
    
        case 1:
        Anim_Mario_Great_Crounch();
        break;

        case 2:
        Anim_Mario_Fire_Crounch();
        break;

        case 3:
        Anim_Mario_Racoon_Crounch();
        break;
    }
}

void Anim_Mario_Death(void) NONBANKED
{
    if(currentMarioPalette != 0)
    {
        Set_Mario_Palette(0);
    }

    set_sprite_tile(0,0x00);
    set_sprite_tile(1,0x00);
    set_sprite_tile(2,0x3E);
    set_sprite_tile(3,0x3F);
    set_sprite_tile(4,0x00);
    set_sprite_tile(5,0x4E);
    set_sprite_tile(6,0x4F);
    set_sprite_tile(7,0x00);
    set_sprite_tile(8,0x5E);
    set_sprite_tile(9,0x5F);

    set_sprite_prop(2,0x00);
    set_sprite_prop(3,0x00);
    set_sprite_prop(4,0x00);
    set_sprite_prop(5,0x00);
    set_sprite_prop(6,0x00);
    set_sprite_prop(7,0x00);
    set_sprite_prop(8,0x00);
    set_sprite_prop(9,0x00);


    move_sprite(0,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y) - 16);
    move_sprite(1,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y) - 16);
    move_sprite(2,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y)- 8);
    move_sprite(3,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y)- 8);
    move_sprite(4,-(Camera.x - Mario_Hitbox.position.x)-8,-(Camera.y - Mario_Hitbox.position.y));
    move_sprite(5,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y));
    move_sprite(6,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y));
    move_sprite(7,-(Camera.x - Mario_Hitbox.position.x)-8,-(Camera.y - Mario_Hitbox.position.y) + 8);
    move_sprite(8,-(Camera.x - Mario_Hitbox.position.x),-(Camera.y - Mario_Hitbox.position.y) + 8);
    move_sprite(9,-(Camera.x - Mario_Hitbox.position.x)+8,-(Camera.y - Mario_Hitbox.position.y) + 8);

    SWITCH_ROM(10);
}

void Anim_Mario_Win(int animstate) BANKED
{
    switch (Mario_Transformation)
    {
        case 0:
        Anim_Mario_Small_Win(animstate);
        break;

        case 1:
        Anim_Mario_Great_Win(animstate);
        break;

        case 2:
        Anim_Mario_Fire_Win(animstate);
        break;

        case 3:
        Anim_Mario_Racoon_Win(animstate);
        break;
    }
}

void Anim_Mario_Star(void) BANKED
{
    animstate_Star += Mario_Star * Time;
    animstate_Star = animstate_Star >= 10 ? 0 : animstate_Star;
}