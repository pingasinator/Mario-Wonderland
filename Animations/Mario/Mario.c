#include <gb\gb.h>
#include "..\..\include\Animations\Mario.h"
#include "..\..\include\Animations\Mario\SmallMario.h"
#include "..\..\include\Animations\Mario\GreatMario.h"
#include "..\..\include\Animations\Mario\FireMario.h"

#pragma bank 10

void Anim_Mario_Idle(int Transformation) BANKED
{
    switch(Transformation)
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
    }
}

void Anim_Mario_Fall(int Transformation) BANKED
{
    switch (Transformation)
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
    }
}

void Anim_Mario_Jump(int Transformation) BANKED
{
    switch (Transformation)
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
    }
}

void Anim_Mario_Move(int Transformation,int animstate) BANKED
{
    switch(Transformation)
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
    }
}

void Anim_Mario_Slide(int Transformation) BANKED
{
    switch(Transformation)
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
    }
}

