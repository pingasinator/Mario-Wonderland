#include "..\include\Items.h"
#include "..\include\Sprite.h"
#include "..\include\Physic.h"
#include "..\include\Mario.h"
#include "..\include\Camera.h"
#include "..\include\GameSystem.h"

Item nullItem = {.dir=0,.originalPosition={.x=0,.y=0},.position={.x=0,.y=0},.Sprite=0,.start=0,.type=0,.Used=0,.velocity={.x=0,.y=0},.Hitbox={.pixeloffset={.x=0,.y=0},.pixelsize={.x=0,.y=0},.position={.x=0,.y=0}}};
Item AllItems[4];

void Reset_Items(void)
{
    for(int i = 0; i < 4;i++)
    {
        if(AllItems[i].Sprite != 0)
        {
            AllItems[i].Sprite = Remove_Sprite(AllItems[i].Sprite,4);
        }
        AllItems[i] = nullItem;
    }
}

void Items_Update(void)
{
    for(int i = 0; i <4;i++)
    {
        if(AllItems[i].Used)
        {
            switch(AllItems[i].type)
            {
                case 1:
                Mushroom_Update(&AllItems[i]);
                break;

                case 2:
                FireFlower_Update(&AllItems[i]);
                break;
            }
        }
    }
}

void Create_Item(int type,int x,int y)
{
    for(int i = 0; i < 4;i++)
    {
        if(!AllItems[i].Used)
        {
            AllItems[i].position.x = x;
            AllItems[i].position.y = y;
            AllItems[i].originalPosition.x = x;
            AllItems[i].originalPosition.y = y;
            AllItems[i].Sprite = Add_Sprite(4);
            AllItems[i].start = 1;
            AllItems[i].Used = 1;
            switch (type)
            {
                case 1:
                AllItems[i].type = 1;
                AllItems[i].dir = 1;
                AllItems[i].Hitbox.pixelsize.x = 14;
                AllItems[i].Hitbox.pixelsize.y = 14;
                AllItems[i].Hitbox.pixeloffset.x = -6;
                AllItems[i].Hitbox.pixeloffset.y = -8;
                if(AllItems[i].Sprite != 0)
                {
                    set_sprite_tile(AllItems[i].Sprite,0x80);
                    set_sprite_tile(AllItems[i].Sprite + 1,0x81);
                    set_sprite_tile(AllItems[i].Sprite + 2,0x82);
                    set_sprite_tile(AllItems[i].Sprite + 3,0x83);
                }
                break;

                case 2:
                AllItems[i].type = 2;
                AllItems[i].Hitbox.pixelsize.x = 14;
                AllItems[i].Hitbox.pixelsize.y = 14;
                AllItems[i].Hitbox.pixeloffset.x = -6;
                AllItems[i].Hitbox.pixeloffset.y = -8;
                if(AllItems[i].Sprite != 0)
                {
                    set_sprite_prop(AllItems[i].Sprite + 1,S_FLIPX);
                    set_sprite_prop(AllItems[i].Sprite + 3,S_FLIPX);
                    set_sprite_tile(AllItems[i].Sprite,0x84);
                    set_sprite_tile(AllItems[i].Sprite + 1,0x84);
                    set_sprite_tile(AllItems[i].Sprite + 2,0x85);
                    set_sprite_tile(AllItems[i].Sprite + 3,0x85);
                }

                break;
            }
            break;
        }
    }
}

void Mushroom_Update(Item *i) 
{
    Vector2 camera;
    camera  = GetCamera();
    while (i->start)
    {
        i->position.y -= 2;
        if(i->position.y <= i->originalPosition.y - 16)
        {
            i->start = 0;
        }
        break;
    }

        i->Hitbox.pixeloffset.x = -6;
        i->Hitbox.pixeloffset.y = -16;
        i->Hitbox.pixelsize.x = 14;
        i->Hitbox.pixelsize.y = 14;
        i->Hitbox.position = i->position;
    
    if(!i->start)
    {
        if(i->position.x > camera.x - 8 * 2 && i->position.x < camera.x + 22 * 8)
        {
            if(i->Sprite == 0)
            {
                i->Sprite = Add_Sprite(4);
            }

            i->velocity.y += Get_Time();
            i->velocity.x = i->dir * Get_Time();
        
            Vector2 Rpos = {.x=i->position.x + Sign(i->dir) * 8,.y=i->position.y-1};
            Vector2 Rdir = {.x=0,.y=-1};

            i->dir = Raycast(Rpos,Rdir,8) ? i->dir - 2 * Sign(i->dir) : i->dir;
            i->velocity.y = Clamp(i->velocity.y,-2,2);
            ApplyPhysicsOnSide(&i->Hitbox,&i->velocity,0);

            i->position.x += i->velocity.x;
            i->position.y += i->velocity.y;

            if(OnCollision(i->Hitbox,GetMarioCollision()))
            {
                i->Sprite = Remove_Sprite(i->Sprite,4);
                *i = nullItem;
                Set_Transformation(1);
            }

        }else
        {
            if(i->Sprite != 0)
            {
                i->Sprite = Remove_Sprite(i->Sprite,4);
            }
        }


    }
    
    if(i->Sprite != 0)
    {
        set_sprite_tile(i->Sprite,0x80);
        set_sprite_tile(i->Sprite + 1,0x81);
        set_sprite_tile(i->Sprite + 2,0x82);
        set_sprite_tile(i->Sprite + 3,0x83);
        move_sprite(i->Sprite,-(camera.x - i->position.x),-(camera.y - i->position.y));
        move_sprite(i->Sprite+1,-(camera.x - i->position.x)+8,-(camera.y - i->position.y));
        move_sprite(i->Sprite+2,-(camera.x - i->position.x),-(camera.y - i->position.y) + 8);
        move_sprite(i->Sprite+3,-(camera.x - i->position.x)+8,-(camera.y - i->position.y) + 8);
    }
}

void FireFlower_Update(Item *i) 
{
    Vector2 camera;
    camera  = GetCamera();
    while (i->start)
    {
        i->position.y -= 2;
        if(i->position.y <= i->originalPosition.y - 16)
        {
            i->start = 0;
        }
        break;
    }

        i->Hitbox.pixeloffset.x = -6;
        i->Hitbox.pixeloffset.y = -16;
        i->Hitbox.pixelsize.x = 14;
        i->Hitbox.pixelsize.y = 14;
        i->Hitbox.position = i->position;
    
    if(!i->start)
    {
        if(i->position.x > camera.x - 8 * 2 && i->position.x < camera.x + 22 * 8)
        {
            if(i->Sprite == 0)
            {
                i->Sprite = Add_Sprite(4);
            }

            if(OnCollision(i->Hitbox,GetMarioCollision()))
            {

                i->Sprite = Remove_Sprite(i->Sprite,4);
                *i = nullItem;
                Set_Transformation(2);
            }

        }else
        {
            if(i->Sprite != 0)
            {
                i->Sprite = Remove_Sprite(i->Sprite,4);
            }
        }


    }
    
    if(i->Sprite != 0)
    {
        set_sprite_tile(i->Sprite,0x84);
        set_sprite_tile(i->Sprite + 1,0x84);
        set_sprite_tile(i->Sprite + 2,0x85);
        set_sprite_tile(i->Sprite + 3,0x85);
        set_sprite_prop(i->Sprite + 1,S_FLIPX);
        set_sprite_prop(i->Sprite + 3,S_FLIPX);
        move_sprite(i->Sprite,-(camera.x - i->position.x),-(camera.y - i->position.y));
        move_sprite(i->Sprite+1,-(camera.x - i->position.x)+8,-(camera.y - i->position.y));
        move_sprite(i->Sprite+2,-(camera.x - i->position.x),-(camera.y - i->position.y) + 8);
        move_sprite(i->Sprite+3,-(camera.x - i->position.x)+8,-(camera.y - i->position.y) + 8);
    }
}
