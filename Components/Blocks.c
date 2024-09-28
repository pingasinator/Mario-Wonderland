
#include "..\include\Sprite.h"
#include "..\include\Objects.h"
#include "..\include\Camera.h"
#include "..\include\GameSystem.h"
#include "..\include\Animations\Objects.h"
#include <gb\gb.h>

Object nullObject = {.position={.x=0,.y=0},.Sprite=0,.Used=0,.returnToPoint=0,.type=0};
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
                Blocks_Update(i);
                break;

                case 2:
                Coin_Update(i);
                break;

                case 3:
                Brick_Update(i);
                break;
            }
        }
    }

}

void Blocks_Update(int i) BANKED
{
    if(AllObjects[i].Used != 0)
    {
        AllObjects[i].position.y += AllObjects[i].returnToPoint ? 4 : -4;
        if(AllObjects[i].Sprite != 0)
        {
            set_sprite_tile(AllObjects[i].Sprite,0x94);
            set_sprite_tile(AllObjects[i].Sprite + 1,0x95);
            set_sprite_tile(AllObjects[i].Sprite + 2,0x96);
            set_sprite_tile(AllObjects[i].Sprite + 3,0x97);
        }

        if(AllObjects[i].position.y < AllObjects[i].originalPosition.y - 4)
        {
            AllObjects[i].returnToPoint = 1;
            Set_Tile(7,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
            Remove_Sprite(AllObjects[i].Sprite,4);
            AllObjects[i] = nullObject;
        }

        if(AllObjects[i].Sprite != 0)
        {
            move_sprite(AllObjects[i].Sprite,-(GetCamera().x - AllObjects[i].position.x) + 8,-(GetCamera().y - AllObjects[i].position.y) + 16);
            move_sprite(AllObjects[i].Sprite + 1,-(GetCamera().x - AllObjects[i].position.x) + 16,-(GetCamera().y - AllObjects[i].position.y) + 16);
            move_sprite(AllObjects[i].Sprite + 2,-(GetCamera().x - AllObjects[i].position.x) + 8,-(GetCamera().y - AllObjects[i].position.y) + 24);
            move_sprite(AllObjects[i].Sprite + 3,-(GetCamera().x - AllObjects[i].position.x) + 16,-(GetCamera().y - AllObjects[i].position.y) + 24);
        }
    }
}

void Coin_Update(int i) BANKED
{   
        AllObjects[i].position.y += AllObjects[i].returnToPoint ? 4 : -4;
        if(AllObjects[i].position.y < AllObjects[i].originalPosition.y - 32)
        {
            AllObjects[i].returnToPoint = 1;
        }

        Anim_Object_Coin(&AllObjects[i]);
        AllObjects[i].animstate++;
        AllObjects[i].animstate = AllObjects[i].animstate >= 6 ? 0 : AllObjects[i].animstate;


    if(AllObjects[i].returnToPoint == 1 && AllObjects[i].position.y >= AllObjects[i].originalPosition.y)
    {
        Set_Tile(7,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
        Remove_Sprite(AllObjects[i].Sprite,4);
        AllObjects[i] = nullObject;
    }
}

void Brick_Update(int i) BANKED
{
    if(AllObjects[i].Used != 0)
    {
        AllObjects[i].position.y += AllObjects[i].returnToPoint ? 4 : -4;
        if(AllObjects[i].Sprite != 0)
        {
            set_sprite_tile(AllObjects[i].Sprite,0x9A);
            set_sprite_tile(AllObjects[i].Sprite + 1,0x9B);
            set_sprite_tile(AllObjects[i].Sprite + 2,0x9C);
            set_sprite_tile(AllObjects[i].Sprite + 3,0x9D);
        }

        if(AllObjects[i].position.y < AllObjects[i].originalPosition.y - 4)
        {
            AllObjects[i].returnToPoint = 1;
            Set_Tile(6,AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
            Remove_Sprite(AllObjects[i].Sprite,4);
            AllObjects[i] = nullObject;
        }

        if(AllObjects[i].Sprite != 0)
        {
            move_sprite(AllObjects[i].Sprite,-(GetCamera().x - AllObjects[i].position.x) + 8,-(GetCamera().y - AllObjects[i].position.y) + 16);
            move_sprite(AllObjects[i].Sprite + 1,-(GetCamera().x - AllObjects[i].position.x) + 16,-(GetCamera().y - AllObjects[i].position.y) + 16);
            move_sprite(AllObjects[i].Sprite + 2,-(GetCamera().x - AllObjects[i].position.x) + 8,-(GetCamera().y - AllObjects[i].position.y) + 24);
            move_sprite(AllObjects[i].Sprite + 3,-(GetCamera().x - AllObjects[i].position.x) + 16,-(GetCamera().y - AllObjects[i].position.y) + 24);
        }
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
            AllObjects[i].position.x = (x / 16) * 16;
            AllObjects[i].position.y = (y / 16) * 16;
            AllObjects[i].originalPosition.x = (x / 16) * 16;
            AllObjects[i].originalPosition.y = (y / 16) * 16;
            AllObjects[i].Used = 1;
            AllObjects[i].type = 2;
            break;
        }
    }
}

void Make_Mushroom(int x,int y) BANKED
{
    
}

void Q_Block(int Type,int x,int y) BANKED
{

    for(int i = 0; i < 10;i++)
    {
        if(AllObjects[i].Used == 0)
        {
            Set_Tile(17,x,y);
            AllObjects[i].Sprite = Add_Sprite(4);
            AllObjects[i].position.x = (x / 16) * 16;
            AllObjects[i].position.y = (y / 16) * 16;
            AllObjects[i].originalPosition.x = (x / 16) * 16;
            AllObjects[i].originalPosition.y = (y / 16) * 16;
            AllObjects[i].Used = 1;
            AllObjects[i].type = 1;
            set_sprite_tile(AllObjects[i].Sprite,0x90);
            set_sprite_tile(AllObjects[i].Sprite + 1,0x91);
            set_sprite_tile(AllObjects[i].Sprite + 2,0x92);
            set_sprite_tile(AllObjects[i].Sprite + 3,0x93);
            move_sprite(AllObjects[i].Sprite,-(GetCamera().x - AllObjects[i].position.x) + 8,-(GetCamera().y - AllObjects[i].position.y) + 16);
            move_sprite(AllObjects[i].Sprite + 1,-(GetCamera().x - AllObjects[i].position.x) + 16,-(GetCamera().y - AllObjects[i].position.y) + 16);
            move_sprite(AllObjects[i].Sprite + 2,-(GetCamera().x - AllObjects[i].position.x) + 8,-(GetCamera().y - AllObjects[i].position.y) + 24);
            move_sprite(AllObjects[i].Sprite + 3,-(GetCamera().x - AllObjects[i].position.x) + 16,-(GetCamera().y - AllObjects[i].position.y) + 24);
                switch (Type)
                {
                    case 2:
                    Make_Coin(AllObjects[i].originalPosition.x,AllObjects[i].originalPosition.y);
                    break;
    
                    case 3:
                    
                    break;
                }
            break;
        }
    }
}

void Brick(int x,int y) BANKED
{
    for(int i = 0; i < 10;i++)
    {
        if(AllObjects[i].Used == 0)
        {
            Set_Tile(17,x,y);
            AllObjects[i].Sprite = Add_Sprite(4);
            AllObjects[i].position.x = (x / 16) * 16;
            AllObjects[i].position.y = (y / 16) * 16;
            AllObjects[i].originalPosition.x = (x / 16) * 16;
            AllObjects[i].originalPosition.y = (y / 16) * 16;
            AllObjects[i].Used = 1;
            AllObjects[i].type = 3;
            set_sprite_tile(AllObjects[i].Sprite,0x9A);
            set_sprite_tile(AllObjects[i].Sprite + 1,0x9B);
            set_sprite_tile(AllObjects[i].Sprite + 2,0x9C);
            set_sprite_tile(AllObjects[i].Sprite + 3,0x9D);
            move_sprite(AllObjects[i].Sprite,-(GetCamera().x - AllObjects[i].position.x) + 8,-(GetCamera().y - AllObjects[i].position.y) + 16);
            move_sprite(AllObjects[i].Sprite + 1,-(GetCamera().x - AllObjects[i].position.x) + 16,-(GetCamera().y - AllObjects[i].position.y) + 16);
            move_sprite(AllObjects[i].Sprite + 2,-(GetCamera().x - AllObjects[i].position.x) + 8,-(GetCamera().y - AllObjects[i].position.y) + 24);
            move_sprite(AllObjects[i].Sprite + 3,-(GetCamera().x - AllObjects[i].position.x) + 16,-(GetCamera().y - AllObjects[i].position.y) + 24);
            break;
        }
    }
}