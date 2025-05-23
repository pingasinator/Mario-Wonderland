
#include "..\include\Sprite.h"
#include "..\include\Objects.h"
#include "..\include\Camera.h"
#include "..\include\GameSystem.h"
#include "..\include\Mario.h"
#include "..\include\Animations\Objects.h"
#include "..\include\Items.h"
#include "..\include\Enemies.h"
#include "..\include\Level.h"
#include <gb\gb.h>


Object nullObject = {.Sprite=0,.animstate=0,.Used=0,.returnToPoint=0,.type=0,.hitbox={.position={.x=0,.y=0},.pixelsize={.x=0,.y=0},.pixeloffset={.x=0,.y=0}}};
Object AllObjects[10];

extern Vector2 Camera;
extern char Mario_Transformation;
extern Collision Mario_Hitbox;

extern char Coins;
extern char Lifes;

extern Enemy* AllEnemies;
extern int Enemies_Number;

extern Level currentLevel;

int FireballNumber = 0;

#pragma bank 14

void Blocks_Start(void) BANKED
{
    for(int i = 0; i < 10;i++)
    {
        if(AllObjects[i].Sprite != 0)
        {
            AllObjects[i].Sprite = Remove_Sprite(AllObjects[i].Sprite,4);
        }
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
                case Object_Type_Block:
                case Object_Type_BumpedBrick:
                case Object_Type_ObjectBrick:
                case Object_Type_DestroyedBrick:
                Blocks_Update(i);
                break;

                case Object_Type_Coin:
                Coin_Update(i);
                break;

                case 7:
                FireBall_Update(&AllObjects[i]);
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

        switch(AllObjects[i].type)
        {
            case Object_Type_BumpedBrick:
            case Object_Type_ObjectBrick:
            Anim_Object_Brick(&AllObjects[i]);
            break;

            case Object_Type_DestroyedBrick:

            break;

            default:
            Anim_Object_Block(&AllObjects[i]);
            break;
        }


        if(AllObjects[i].hitbox.position.y < AllObjects[i].originalPosition.y - 4)
        {
            AllObjects[i].returnToPoint = 1;

        }
    }

    if(AllObjects[i].returnToPoint && AllObjects[i].hitbox.position.y >= AllObjects[i].originalPosition.y)
    {

        switch (AllObjects[i].type)
        {
            case Object_Type_BumpedBrick:
            Set_Tile(0x85,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
            AllObjects[i].Sprite = Remove_Sprite(AllObjects[i].Sprite,4);
            break;

            case Object_Type_DestroyedBrick:
            Set_Tile(0x00,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
            break;
        
            default:
            Set_Tile(0x8A,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
            AllObjects[i].Sprite = Remove_Sprite(AllObjects[i].Sprite,4);
            break;
        }

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


    if(AllObjects[i].Velocity.y > 0 && AllObjects[i].hitbox.position.y >= AllObjects[i].originalPosition.y)
    {
        Set_Tile(0x8A,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
        Remove_Sprite(AllObjects[i].Sprite,4);
        AllObjects[i] = nullObject;
    }
}

void FireBall_Update(Object *o) BANKED
{
    if(o->hitbox.position.x > Camera.x - 8 * 2 && o->hitbox.position.x < Camera.x + 22 * 8 && o->hitbox.position.y > Camera.y - 8 && o->hitbox.position.y < Camera.y + 19 * 8)
    {
        Vector2 RayGround_point = {.x=o->hitbox.position.x,.y=o->hitbox.position.y+2};
        Vector2 RayGround_Dir = {.x=1,.y=0};
        Vector2 RayWall_point_0 = {.x=o->hitbox.position.x + o->hitbox.pixeloffset.x + o->hitbox.pixelsize.x,.y=o->hitbox.position.y - 8};
        Vector2 RayWall_point_1 = {.x=o->hitbox.position.x,.y=o->hitbox.position.y - 8};
        Vector2 RayWall_Dir = {.x=0,.y=1};
        char onGround = Raycast(RayGround_point,RayGround_Dir,8);
        char onWall = Raycast(RayWall_point_0,RayWall_Dir,6) || Raycast(RayWall_point_1,RayWall_Dir,6);

        o->Velocity.x = o->dir * 7;
        o->Velocity.y++;
        o->Velocity.y = Clamp(o->Velocity.y,-5,5);
        if(onGround)
        {
            o->Velocity.y = -5;
        }

        o->hitbox.pixelsize.x = 8;
        o->hitbox.pixelsize.y = 8;
        o->hitbox.pixeloffset.y = -8;
        o->hitbox.pixeloffset.x = -8;

        o->animstate++;
        o->animstate = o->animstate >= 4 ? 0 : o->animstate;
        Anim_Object_Fireball(o);

        for(int i = 0;i < Enemies_Number;i++)
        {
            if(AllEnemies[i].Enabled && OnCollision(o->hitbox,AllEnemies[i].Hitbox) &&! AllEnemies[i].Knockback)
            {
                Enemy_KnockBack(&AllEnemies[i],o->dir);
                if(o->Sprite != 0)
                {
                    o->Sprite = Remove_Sprite(o->Sprite,2);
                }

                FireballNumber--;
                *o = nullObject;
                break;
            }
        }

        if(onWall)
        {
            if(o->Sprite != 0)
            {
                o->Sprite = Remove_Sprite(o->Sprite,2);
            }

            FireballNumber--;
            *o = nullObject;
        }
        
        o->hitbox.position.x += o->Velocity.x;
        o->hitbox.position.y += o->Velocity.y;

    }else
    {
        o->Sprite = Remove_Sprite(o->Sprite,2);
        FireballNumber--;
        *o = nullObject;
    } 
}

void Use_Coin(int x,int y) BANKED
{
    Set_Tile(0,x,y);
    Coins++;
    if(Coins >= 100)
    {
        Coins = 0;
        Lifes++;
        Lifes = Clamp(Lifes,0,99);
    }
}

void TileObject_Update(unsigned char Tile,int X,int Y,Vector2 Velocity,int side) BANKED
{
    switch(Tile)
    {
        case 0x04:
        Use_Coin(X,Y);
        break;

        case 0x81:
        case 0x82:
        case 0x83:
        case 0x84:
        case 0x85:
        case 0x86:
        case 0x87:
        case 0x88:
        if(Velocity.y < 0 && side == 1)
        {
            Q_Block(Tile,X,Y);
        }
        break;
    }
}

void Make_Coin(int x,int y) BANKED
{
    for(int i = 0;i < 10;i++)
    {
        if(AllObjects[i].Used == 0)
        {
            Coins++;
            if(Coins >= 100)
            {
                Coins = 0;
                Lifes++;
                Lifes = Clamp(Lifes,0,99);
            }
            AllObjects[i].Sprite = Add_Sprite(4);
            AllObjects[i].hitbox.position.x = (x / 16) * 16 + 8;
            AllObjects[i].hitbox.position.y = (y / 16) * 16 + 16;
            AllObjects[i].originalPosition.x = (x / 16) * 16;
            AllObjects[i].originalPosition.y = (y / 16) * 16;
            AllObjects[i].Velocity.y = -10;
            AllObjects[i].Used = 1;
            AllObjects[i].type = Object_Type_Coin;
            break;
        }
    }
}

void Make_FireBall(int dir,int x,int y) BANKED
{
    for(int i = 0;i < 10;i++)
    {
        if(!AllObjects[i].Used && FireballNumber < 2)
        {
            FireballNumber++;
            AllObjects[i].dir = dir;
            AllObjects[i].Sprite = Add_Sprite(2);
            AllObjects[i].type = 7;
            AllObjects[i].Used = 1;
            AllObjects[i].hitbox.position.x = x;
            AllObjects[i].hitbox.position.y = y;
            AllObjects[i].hitbox.pixelsize.y = 8;
            AllObjects[i].hitbox.pixelsize.x = 8;
            if(AllObjects[i].Sprite != 0)
            {
                Anim_Object_Fireball(&AllObjects[i]);
            }
            break;
        }
    }
}

void Q_Block(int Type,int x,int y) BANKED
{

    for(int i = 0; i < 10;i++)
    {
        if(AllObjects[i].Used == 0)
        {
            Set_Tile(0x80,x,y);
            AllObjects[i].Sprite = Add_Sprite(4);
            AllObjects[i].hitbox.position.x = (x / 16) * 16;
            AllObjects[i].hitbox.position.y = (y / 16) * 16;
            AllObjects[i].originalPosition.x = (x / 16) * 16;
            AllObjects[i].originalPosition.y = (y / 16) * 16;
            AllObjects[i].Used = 1;
            AllObjects[i].type = Object_Type_Block;
            Anim_Object_Block(&AllObjects[i]);
            switch (Type)
            {
                case 0x81:
                Make_Coin(AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
                break;
    
                case 0x82:
                Create_Item(1,AllObjects[i].originalPosition.x + 8,AllObjects[i].originalPosition.y + 16);
                break;

                case 0x83:
                if(Mario_Transformation >= 1)
                {
                    Create_Item(2,AllObjects[i].originalPosition.x + 8,AllObjects[i].originalPosition.y + 16);
                }else
                {
                    Create_Item(1,AllObjects[i].originalPosition.x + 8,AllObjects[i].originalPosition.y + 16);
                }
                break;

                case 0x84:
                if(Mario_Transformation >= 1)
                {
                    Create_Item(3,AllObjects[i].originalPosition.x + 8,AllObjects[i].originalPosition.y + 16);
                }else
                {
                    Create_Item(1,AllObjects[i].originalPosition.x + 8,AllObjects[i].originalPosition.y + 16);
                }
                break;

                case 0x85:
                if(Mario_Transformation >= 1)
                {
                    AllObjects[i].type = Object_Type_DestroyedBrick;
                    AllObjects[i].Sprite = Remove_Sprite(AllObjects[i].Sprite,4);
                }else
                {
                    AllObjects[i].type = Object_Type_BumpedBrick;
                    Anim_Object_Brick(&AllObjects[i]);
                }
                break;

                case 0x86:
                AllObjects[i].type = Object_Type_ObjectBrick;
                Make_Coin(AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
                break;

                case 0x87:
                AllObjects[i].type = Object_Type_ObjectBrick;
                Create_Item(4,AllObjects[i].originalPosition.x + 8,AllObjects[i].originalPosition.y + 16);
                break;

                case 0x88:
                AllObjects[i].type = Object_Type_ObjectBrick;
                Create_Item(5,AllObjects[i].originalPosition.x + 8,AllObjects[i].originalPosition.y + 16);
                break;
            }
            break;
        }
    }
}