#include "..\include\Items.h"
#include "..\include\Sprite.h"
#include "..\include\Mario.h"
#include "..\include\Camera.h"
#include "..\include\GameSystem.h"

extern Vector2 Camera;
extern int Lifes;

extern char Mario_Star;

extern Collision Mario_Hitbox;

Item nullItem = {.dir=0,.originalPosition={.x=0,.y=0},.position={.x=0,.y=0},.Sprite=0,.start=0,.type=0,.Used=0,.velocity={.x=0,.y=0},.Hitbox={.pixeloffset={.x=0,.y=0},.pixelsize={.x=0,.y=0},.position={.x=0,.y=0}}};
Item AllItems[4];

#pragma bank 18

void Reset_Items(void)BANKED
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

void Items_Update(void)BANKED
{
    for(int i = 0; i <4;i++)
    {
        if(AllItems[i].Used)
        {
            switch(AllItems[i].type)
            {
                case 1:
                case 5:
                Mushroom_Update(&AllItems[i]);
                break;

                case 2:
                FireFlower_Update(&AllItems[i]);
                break;

                case 3:
                Leaf_Update(&AllItems[i]);
                break;

                case 4:
                Star_Update(&AllItems[i]);
                break;
            }
        }
    }
}

void Create_Item(int type,int x,int y)BANKED
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

                case 3:
                AllItems[i].type = 3;
                AllItems[i].Hitbox.pixelsize.x = 14;
                AllItems[i].Hitbox.pixelsize.y = 14;
                AllItems[i].Hitbox.pixeloffset.x = -6;
                AllItems[i].Hitbox.pixeloffset.y = -8;
                if(AllItems[i].Sprite != 0)
                {
                    set_sprite_tile(AllItems[i].Sprite,0x86);
                    set_sprite_tile(AllItems[i].Sprite + 1,0x87);
                    set_sprite_tile(AllItems[i].Sprite + 2,0x88);
                    set_sprite_tile(AllItems[i].Sprite + 3,0x89);
                }
                break;

                case 4:
                AllItems[i].type = 4;
                AllItems[i].dir = 1;
                AllItems[i].Hitbox.pixelsize.x = 14;
                AllItems[i].Hitbox.pixelsize.y = 14;
                AllItems[i].Hitbox.pixeloffset.x = -6;
                AllItems[i].Hitbox.pixeloffset.y = -8;
                if(AllItems[i].Sprite != 0)
                {
                    set_sprite_prop(AllItems[i].Sprite + 1,S_FLIPX);
                    set_sprite_prop(AllItems[i].Sprite + 3,S_FLIPX);
                    set_sprite_tile(AllItems[i].Sprite,0x8A);
                    set_sprite_tile(AllItems[i].Sprite + 1,0x8A);
                    set_sprite_tile(AllItems[i].Sprite + 2,0x8B);
                    set_sprite_tile(AllItems[i].Sprite + 3,0x8B);
                }
                break;

                case 5:
                AllItems[i].type = 5;
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
            }
            break;
        }
    }
}

void Mushroom_Update(Item *i)BANKED 
{
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
        if(i->position.x > Camera.x - 8 * 2 && i->position.x < Camera.x + 22 * 8)
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
            TilemapCollisionPhysics(&i->Hitbox,&i->velocity);

            i->position.x += i->velocity.x;
            i->position.y += i->velocity.y;

            if(OnCollision(i->Hitbox,Mario_Hitbox) &&! Mario_isDead())
            {
                if(i->type == 1)
                {
                    Set_Transformation(1);
                }else
                {
                    Lifes += 1;
                }

                i->Sprite = Remove_Sprite(i->Sprite,4);
                *i = nullItem;
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
        move_sprite(i->Sprite,-(Camera.x - i->position.x),-(Camera.y - i->position.y));
        move_sprite(i->Sprite+1,-(Camera.x - i->position.x)+8,-(Camera.y - i->position.y));
        move_sprite(i->Sprite+2,-(Camera.x - i->position.x),-(Camera.y - i->position.y) + 8);
        move_sprite(i->Sprite+3,-(Camera.x - i->position.x)+8,-(Camera.y - i->position.y) + 8);
    }
}

void FireFlower_Update(Item *i)BANKED 
{
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
        if(i->position.x > Camera.x - 8 * 2 && i->position.x < Camera.x + 22 * 8)
        {
            if(i->Sprite == 0)
            {
                i->Sprite = Add_Sprite(4);
            }

            if(OnCollision(i->Hitbox,Mario_Hitbox))
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
        move_sprite(i->Sprite,-(Camera.x - i->position.x),-(Camera.y - i->position.y));
        move_sprite(i->Sprite+1,-(Camera.x - i->position.x)+8,-(Camera.y - i->position.y));
        move_sprite(i->Sprite+2,-(Camera.x - i->position.x),-(Camera.y - i->position.y) + 8);
        move_sprite(i->Sprite+3,-(Camera.x - i->position.x)+8,-(Camera.y - i->position.y) + 8);
    }
}

void Leaf_Update(Item *i)BANKED
{
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
        if(i->position.x > Camera.x - 8 * 2 && i->position.x < Camera.x + 22 * 8)
        {
            if(i->Sprite == 0)
            {
                i->Sprite = Add_Sprite(4);
            }

            if(OnCollision(i->Hitbox,Mario_Hitbox))
            {

                i->Sprite = Remove_Sprite(i->Sprite,4);
                *i = nullItem;
                Set_Transformation(3);
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
        set_sprite_tile(i->Sprite,0x86);
        set_sprite_tile(i->Sprite + 1,0x87);
        set_sprite_tile(i->Sprite + 2,0x88);
        set_sprite_tile(i->Sprite + 3,0x89);
        move_sprite(i->Sprite,-(Camera.x - i->position.x),-(Camera.y - i->position.y));
        move_sprite(i->Sprite+1,-(Camera.x - i->position.x)+8,-(Camera.y - i->position.y));
        move_sprite(i->Sprite+2,-(Camera.x - i->position.x),-(Camera.y - i->position.y) + 8);
        move_sprite(i->Sprite+3,-(Camera.x - i->position.x)+8,-(Camera.y - i->position.y) + 8);
    }
}

void Star_Update(Item *i)BANKED
{
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
        if(i->position.x > Camera.x - 8 * 2 && i->position.x < Camera.x + 22 * 8)
        {
            if(i->Sprite == 0)
            {
                i->Sprite = Add_Sprite(4);
            }

            i->velocity.y += Get_Time();
            i->velocity.x = i->dir * Get_Time() * 2;
        
            Vector2 Rpos = {.x=i->position.x + Sign(i->dir) * 8,.y=i->position.y-1};
            Vector2 Rdir = {.x=0,.y=-1};

            i->dir = Raycast(Rpos,Rdir,8) ? i->dir - 2 * Sign(i->dir) : i->dir;
        
            Vector2 R_Ground_pos = {.x=i->position.x + Sign(i->dir) * 8,.y=i->position.y};
            Vector2 R_Ground_dir = {.x=0,.y=1};

            i->velocity.y = Raycast(R_Ground_pos,R_Ground_dir,2) ? -8 : i->velocity.y;
            i->velocity.y = Clamp(i->velocity.y,-8,4);
            TilemapCollisionPhysics(&i->Hitbox,&i->velocity);

            i->position.x += i->velocity.x;
            i->position.y += i->velocity.y;

            if(OnCollision(i->Hitbox,Mario_Hitbox))
            {

                i->Sprite = Remove_Sprite(i->Sprite,4);
                *i = nullItem;
                Mario_Star = 1;
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
        set_sprite_tile(i->Sprite,0x8A);
        set_sprite_tile(i->Sprite + 1,0x8A);
        set_sprite_tile(i->Sprite + 2,0x8B);
        set_sprite_tile(i->Sprite + 3,0x8B);
        set_sprite_prop(i->Sprite + 1,S_FLIPX);
        set_sprite_prop(i->Sprite + 3,S_FLIPX);
        move_sprite(i->Sprite,-(Camera.x - i->position.x),-(Camera.y - i->position.y));
        move_sprite(i->Sprite+1,-(Camera.x - i->position.x)+8,-(Camera.y - i->position.y));
        move_sprite(i->Sprite+2,-(Camera.x - i->position.x),-(Camera.y - i->position.y) + 8);
        move_sprite(i->Sprite+3,-(Camera.x - i->position.x)+8,-(Camera.y - i->position.y) + 8);
    }
}