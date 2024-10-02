
#include "..\include\Sprite.h"
#include "..\include\Objects.h"
#include "..\include\Camera.h"
#include "..\include\GameSystem.h"
#include "..\include\Mario.h"
#include "..\include\Animations\Objects.h"
#include "..\include\Physic.h"
#include "..\include\Items.h"
#include <gb\gb.h>


Object nullObject = {.Sprite=0,.animstate=0,.Used=0,.returnToPoint=0,.type=0,.hitbox={.position={.x=0,.y=0},.pixelsize={.x=0,.y=0},.pixeloffset={.x=0,.y=0}}};
Object AllObjects[10];

#pragma bank 14

void Blocks_Start(void) BANKED
{
    for(int i = 0; i < 10;i++)
    {
        AllObjects[i] = nullObject;
    }
}

void Objects_Update(void) BANKED
{
    for(int i = 0;i < 10;i++)
    {
        if(AllObjects[i].Used != 0)
        {
            switch(AllObjects[i].type)
            {
                case 1:
                case 6:
                Blocks_Update(i);
                break;

                case 2:
                Coin_Update(i);
                break;
            }
        }
    }

}

void Blocks_Update(int i) BANKED
{
    if(AllObjects[i].Used != 0)
    {
        AllObjects[i].hitbox.position.y += AllObjects[i].returnToPoint ? 2 : -2;

        if(AllObjects[i].type != 6)
        {
            Anim_Object_Block(&AllObjects[i]);
        }else
        {
            Anim_Object_Brick(&AllObjects[i]);
        }

        if(AllObjects[i].hitbox.position.y < AllObjects[i].originalPosition.y - 4)
        {
            AllObjects[i].returnToPoint = 1;

        }
    }

    if(AllObjects[i].returnToPoint && AllObjects[i].hitbox.position.y >= AllObjects[i].originalPosition.y)
    {
        if(AllObjects[i].type != 6)
        {
            Set_Tile(7,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
        }else
        {
            Set_Tile(6,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
        }
        AllObjects[i].Sprite = Remove_Sprite(AllObjects[i].Sprite,4);
        AllObjects[i] = nullObject;
    }
}

void Coin_Update(int i) BANKED
{   

    AllObjects[i].Velocity.y++;
    AllObjects[i].Velocity.y = Clamp(AllObjects[i].Velocity.y,-15,4);
    AllObjects[i].hitbox.position.y += AllObjects[i].Velocity.y;


        Anim_Object_Coin(&AllObjects[i]);
        AllObjects[i].animstate += 2;
        AllObjects[i].animstate = AllObjects[i].animstate >= 6 ? 0 : AllObjects[i].animstate;


    if(AllObjects[i].Velocity.y > 0 == 1 && AllObjects[i].hitbox.position.y >= AllObjects[i].originalPosition.y)
    {
        Set_Tile(7,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
        Remove_Sprite(AllObjects[i].Sprite,4);
        AllObjects[i] = nullObject;
    }
}

void Use_Coin(int x,int y) BANKED
{
    Set_Tile(0,x,y);
    Add_Coin(1);
}

void Make_Coin(int x,int y) BANKED
{
    for(int i = 0;i < 10;i++)
    {
        if(AllObjects[i].Used == 0)
        {
            Add_Coin(1);
            AllObjects[i].Sprite = Add_Sprite(4);
            AllObjects[i].hitbox.position.x = (x / 16) * 16 + 8;
            AllObjects[i].hitbox.position.y = (y / 16) * 16 + 16;
            AllObjects[i].originalPosition.x = (x / 16) * 16;
            AllObjects[i].originalPosition.y = (y / 16) * 16;
            AllObjects[i].Velocity.y = -10;
            AllObjects[i].Used = 1;
            AllObjects[i].type = 2;
            break;
        }
    }
}

void Make_FireBall(int x,int y) BANKED
{
    for(int i = 0;i < 10;i++)
    {
        if(!AllObjects[i].Used)
        {

        }
    }
}

void FireBall_Update(Object *o) BANKED
{
    if(o->Sprite != 0)
    {

    }
}

void Q_Block(int Type,int x,int y) BANKED
{

    for(int i = 0; i < 10;i++)
    {
        if(AllObjects[i].Used == 0)
        {
            Set_Tile(17,x,y);
            AllObjects[i].Sprite = Add_Sprite(4);
            AllObjects[i].hitbox.position.x = (x / 16) * 16;
            AllObjects[i].hitbox.position.y = (y / 16) * 16;
            AllObjects[i].originalPosition.x = (x / 16) * 16;
            AllObjects[i].originalPosition.y = (y / 16) * 16;
            AllObjects[i].Used = 1;
            AllObjects[i].type = 1;
            Anim_Object_Block(&AllObjects[i]);
            switch (Type)
            {
                case 2:
                Make_Coin(AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
                break;
    
                case 3:
                Create_Item(1,AllObjects[i].originalPosition.x + 8,AllObjects[i].originalPosition.y + 16);
                break;

                case 4:
                Create_Item(2,AllObjects[i].originalPosition.x + 8,AllObjects[i].originalPosition.y + 16);
                break;

                case 6:
                AllObjects[i].type = 6;
                Anim_Object_Brick(&AllObjects[i]);
                break;
            }
            break;
        }
    }
}