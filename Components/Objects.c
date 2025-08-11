
#include "..\include\Sprite.h"
#include "..\include\Objects.h"
#include "..\include\Camera.h"
#include "..\include\GameSystem.h"
#include "..\include\Mario.h"
#include "..\include\Animations\Objects.h"
#include "..\include\Enemies.h"
#include "..\include\Level.h"

#include <gb\gb.h>
#include <asm\sm83\string.h>
#include <stdlib.h>

#pragma bank 14

const Object nullObject = {.type=0,.enabled=0,.Sprite=0,.animstate=0,.returnToPoint=0,.hitbox={.position={.x=0,.y=0},.pixelsize={.x=0,.y=0},.pixeloffset={.x=0,.y=0}}};
const Object fireball = {.type=Object_Type_Fireball,.enabled=1,.hitbox={.pixelsize={.x=8,.y=8},.pixeloffset={.x=0,.y=-8}}};
const Object coin = {.type = Object_Type_Coin,.enabled = 1,.velocity={.x=0,.y=-10},};
const Object hiddenCoin = {.type=Object_Type_HiddenCoin,.enabled=1,.hitbox={.pixelsize={.x=8,.y=8},.pixeloffset={.x=0,.y=-8}}};

const Object Item = {.type=0,.start=1,.enabled=1,.dir=1,.hitbox={.pixelsize={.x=8,.y=8},.pixeloffset={.x=0,.y=-8}}};

Object Object_Buffer[10];
int Object_number;

extern Vector2 Camera;
extern char Mario_Transformation;
extern Collision Mario_Hitbox;
extern char Mario_Star;
extern unsigned char Mario_State;

extern char Time;
extern char Coins;
extern char Lifes;

extern Enemy* AllEnemies;
extern int Enemies_Number;

extern Scene CurrentScene;

int FireballNumber = 0;

void Object_Reset(void) BANKED
{
    for(int i = 0; i < 10;i++)
    {
        if(Object_Buffer[i].Sprite != 0)
        {
            Object_Buffer[i].Sprite = Remove_NonMarioObject_Sprite(Object_Buffer[i].Sprite,4);
        }
        Object_Buffer[i] = nullObject;
    }
    Object_number = 0;
}

void Objects_Update(void) BANKED
{
    int j=0;
    int k=0;
    for(int i = 0;i < Object_number;i++)
    {
        if(Object_Buffer[i].enabled)
        {
            switch(Object_Buffer[i].type)
            {
                case Object_Type_Block:
                case Object_Type_BumpedBrick:
                case Object_Type_ObjectBrick:
                case Object_Type_DestroyedBrick:
                Blocks_Update(&Object_Buffer[i]);
                break;

                case Object_Type_Coin:
                Coin_Update(&Object_Buffer[i]);
                break;

                case Object_Type_Fireball:
                FireBall_Update(&Object_Buffer[i]);
                break;

                case Object_Type_HiddenCoin:
                HiddenCoin_Update(&Object_Buffer[i]);
                break;

                case Object_Type_Item_Mushroom:
                case Object_Type_Item_FireFlower:
                case Object_Type_Item_RacoonLeaf:
                case Object_Type_Item_Koopashell:
                case Object_Type_Item_Tinyshroom:
                case Object_type_Item_Star:
                case Object_Type_Item_1UP:
                Object_Item_Update(&Object_Buffer[i]);
                break;
            }
            Object_Buffer[j] = Object_Buffer[i];
            j++;
        }else
        {
            k++;
        }
    }
    Object_number -= k;
}

void Blocks_Update(Object *o) BANKED
{
    switch(o->type)
    {
        case Object_Type_BumpedBrick:
        case Object_Type_ObjectBrick:
        Anim_Object_Brick(o);
        break;

        case Object_Type_DestroyedBrick:

        break;

        default:
        Anim_Object_Block(o);
        break;
    }

    o->hitbox.position.y += o->returnToPoint ? 2 : -2;
    o->returnToPoint = o->hitbox.position.y < o->originalPosition.y - 4 ?  1 : o->returnToPoint;

    if(o->returnToPoint && o->hitbox.position.y >= o->originalPosition.y)
    {
        switch (o->type)
        {
            case Object_Type_BumpedBrick:
            Set_Tile(0x8B,o->originalPosition.x,o->originalPosition.y);
            o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,4);
            break;

            case Object_Type_DestroyedBrick:
            Set_Tile(0x00,o->originalPosition.x,o->originalPosition.y);
            break;
        
            default:
            Set_Tile(0x97,o->originalPosition.x,o->originalPosition.y);
            o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,4);
            break;
        }

        *o = nullObject;
    }
}

void Object_Item_Update(Object *o) BANKED
{
    if(o->start)
    {
        Object_Item_Start(o);
    }else
    {
        switch(o->type)
        {
            case Object_Type_Item_Mushroom:
            case Object_Type_Item_1UP:
            case Object_Type_Item_Tinyshroom:
            Object_Item_Mushroom_Update(o);
            break;

            case Object_Type_Item_FireFlower:
            case Object_Type_Item_RacoonLeaf:
            case Object_Type_Item_Koopashell:
            Object_Item_StaticItem_Update(o);
            break;

            case Object_type_Item_Star:
            Object_Item_Star_Update(o);
            break;
        }
    }
}

void Object_Item_Start(Object *o) BANKED
{
    o->hitbox.position.y -= 2;
    o->start = !(o->hitbox.position.y <= o->originalPosition.y - 16);
    Display_Item(o);
}

void Object_Item_Mushroom_Update(Object *o) BANKED
{
    if(o->hitbox.position.x > Camera.x - 8 * 2 && o->hitbox.position.x < Camera.x + 22 * 8)
    {
        o->velocity.y += Time;
        o->dir = Get_Tile(o->hitbox.position.x + o->hitbox.pixeloffset.x + o->dir * (o->hitbox.pixelsize.x + 1),o->hitbox.position.y + o->hitbox.pixeloffset.y) >= 0x80 ? o->dir - 2 * Sign(o->dir) : o->dir;
        o->velocity.x = o->dir * Time;
        o->velocity.y = Clamp(o->velocity.y,-2,2);
        o->hitbox.position.x += o->velocity.x;
        o->hitbox.position.y += o->velocity.y;
        TilemapCollisionPhysicsSide(&o->hitbox,&o->velocity,0);

        Collision c;
        c = o->hitbox;
        
        if(OnCollision(c,Mario_Hitbox) &&! (Mario_State == Mario_State_Dead))
        {
            if(o->type != Object_Type_Item_1UP)
            {
                Set_Transformation(o->type);
            }
            Lifes += (o->type == Object_Type_Item_1UP);
            o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,4);
            *o = nullObject;
        }

    }else
    {
        o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,4);
        *o = nullObject;
    }

    Display_Item(o);
}

void Object_Item_StaticItem_Update(Object *o)BANKED 
{
    if(o->hitbox.position.x > Camera.x - 8 * 2 && o->hitbox.position.x < Camera.x + 22 * 8)
    {
        Collision c;
        c = o->hitbox;
        if(OnCollision(c,Mario_Hitbox) &&! (Mario_State == Mario_State_Dead))
        {
            Set_Transformation(o->type);
            o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,4);
            *o = nullObject;
        }

    }else
    {
        o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,4);
        *o = nullObject;
    }

    Display_Item(o);
}

void Object_Item_Star_Update(Object *o)BANKED
{
    if(o->hitbox.position.x > Camera.x - 8 * 2 && o->hitbox.position.x < Camera.x + 22 * 8)
    {
        o->velocity.y += Time;
        o->velocity.x = o->dir * Time * 2;
        
        Vector2 Rpos = {.x=o->hitbox.position.x + Sign(o->dir) * 8,.y=o->hitbox.position.y-1};
        Vector2 Rdir = {.x=0,.y=-1};

        o->dir = Raycast(Rpos,Rdir,8) ? o->dir - 2 * Sign(o->dir) : o->dir;
        
        Vector2 R_Ground_pos = {.x=o->hitbox.position.x + Sign(o->dir) * 8,.y=o->hitbox.position.y};
        Vector2 R_Ground_dir = {.x=0,.y=1};

        o->velocity.y = Raycast(R_Ground_pos,R_Ground_dir,2) ? -8 : o->velocity.y;
        o->velocity.y = Clamp(o->velocity.y,-8,4);
        TilemapCollisionPhysics(&o->hitbox,&o->velocity);

        o->hitbox.position.x += o->velocity.x;
        o->hitbox.position.y += o->velocity.y;
        Collision c;
        c = o->hitbox;
        if(OnCollision(c,Mario_Hitbox))
        {
            o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,4);
            *o = nullObject;
            Mario_Star = 1;
        }

        Display_Item(o);
    }else
    {
        o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,4);
        *o = nullObject;
    }
}

void Coin_Update(Object *o) BANKED
{
    o->velocity.y++;
    o->velocity.y = Clamp(o->velocity.y,-10,4);
    o->hitbox.position.y += o->velocity.y;

    Anim_Object_Coin(o);

    if(o->velocity.y > 0 && o->hitbox.position.y >= o->originalPosition.y)
    {
        Set_Tile(0x97,o->originalPosition.x,o->originalPosition.y);
        Remove_NonMarioObject_Sprite(o->Sprite,4);
        *o = nullObject;
    }
}

void HiddenCoin_Update(Object *o) BANKED
{
    if(!OnCollision(o->hitbox,Mario_Hitbox))
    {
        Set_Tile(0x04,o->hitbox.position.x,o->hitbox.position.y);
        *o = nullObject;
    }
}

void FireBall_Update(Object *o) BANKED
{
    if(o->hitbox.position.x > Camera.x - 8 * 2 && o->hitbox.position.x < Camera.x + 22 * 8 && o->hitbox.position.y > Camera.y - 8 && o->hitbox.position.y < Camera.y + 19 * 8)
    {
        char onGround = Get_Tile(o->hitbox.position.x,o->hitbox.position.y + o->hitbox.pixeloffset.y + o->hitbox.pixelsize.y) >= 0x80;
        char onWall = Get_Tile(o->hitbox.position.x,o->hitbox.position.y + o->hitbox.pixeloffset.y) >= 0x80;

        o->velocity.x = o->dir * 7;
        o->velocity.y++;
        o->velocity.y = Clamp(o->velocity.y,-5,5);
        o->velocity.y = onGround ? -5 : o->velocity.y;
        Anim_Object_Fireball(o);

        for(int i = 0;i < Enemies_Number;i++)
        {
            if(AllEnemies[i].Enabled && OnCollision(o->hitbox,AllEnemies[i].Hitbox) &&! AllEnemies[i].Knockback)
            {
                Enemy_KnockBack(&AllEnemies[i],o->dir);
                o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,2);
                FireballNumber--;
                *o = nullObject;
                break;
            }
        }

        if(onWall)
        {
            goto DF;
        }
        
        o->hitbox.position.x += o->velocity.x;
        o->hitbox.position.y += o->velocity.y;

    }else
    {
        DF:
        o->Sprite = Remove_NonMarioObject_Sprite(o->Sprite,2);
        FireballNumber--;
        *o = nullObject;
    } 
}

void Object_Create_HiddenCoin(int x,int y) BANKED
{
    for(int i = 0; i < 10;i++)
    {
        if(!Object_Buffer[i].enabled)
        {
            Set_Tile(0x00,x,y);
            Object_Buffer[i] = hiddenCoin;
            Object_Buffer[i].hitbox.position.x = x;
            Object_Buffer[i].hitbox.position.y = y;
            break;
        }
    }
}

Object *Object_Create(unsigned char Type,int x, int y,int dir) BANKED
{
    if(Object_number < 10)
    {
        Object_number++;
        switch(Type)
        {
            case Object_Type_Item_Mushroom:
            case Object_Type_Item_FireFlower:
            case Object_Type_Item_RacoonLeaf:
            case Object_Type_Item_Koopashell:
            case Object_Type_Item_Tinyshroom:
            case Object_type_Item_Star:
            case Object_Type_Item_1UP:
            Object_Buffer[Object_number - 1] = Item;
            Object_Buffer[Object_number - 1].Sprite = Add_Sprite(4);
            break;

            case Object_Type_Fireball:
            if(FireballNumber < 2)
            {
                FireballNumber++;
                Object_Buffer[Object_number - 1] = fireball;
                Object_Buffer[Object_number - 1].dir = dir;
                Object_Buffer[Object_number - 1].Sprite = Add_Sprite(2);
            }
            break;

            case Object_Type_Coin:
            Coins++;
            if(Coins >= 100)
            {
                Coins = 0;
                Lifes++;
                Lifes = Clamp(Lifes,0,99);
            }
            Object_Buffer[Object_number - 1] = coin;
            break;

            case Object_Type_Block:
            Object_Buffer[Object_number - 1].Sprite = Add_Sprite(4);
            break;
        }

        Object_Buffer[Object_number - 1].type = Type;
        Object_Buffer[Object_number - 1].enabled = 1;
        Object_Buffer[Object_number - 1].hitbox.position.x = x;
        Object_Buffer[Object_number - 1].hitbox.position.y = y;
        Object_Buffer[Object_number - 1].originalPosition.x = x;
        Object_Buffer[Object_number - 1].originalPosition.y = y;

        return &Object_Buffer[Object_number - 1];
    }else
    {
        return NULL;
    }
}

void Q_Block(int Type,int x,int y) BANKED
{
    Object *Block = Object_Create(Object_Type_Block,(x / 16) * 16,(y / 16) * 16,0);
    if(Block != NULL)
    {
        Set_Tile(0x80,x,y);
        Block->type = Object_Type_Block;
        switch (Type)
        {
            case 0x81:
            Object_Create(Object_Type_Coin,Block->originalPosition.x + 8,Block->originalPosition.y,0);
            break;
    
            case 0x83:
            Object_Create(Object_Type_Item_Mushroom,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x84:
            Object_Create(Mario_Transformation >= 1 ? Object_Type_Item_FireFlower : Object_Type_Item_Mushroom ,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x85:
            Object_Create(Mario_Transformation >= 1 ? Object_Type_Item_RacoonLeaf : Object_Type_Item_Mushroom,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x86:
            Object_Create(Mario_Transformation >= 1 ? Object_Type_Item_Koopashell : Object_Type_Item_Mushroom,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x87:
            Object_Create(Object_Type_Item_Tinyshroom,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x89:
            Object_Create(Object_type_Item_Star,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x8A:
            Object_Create(Object_Type_Item_1UP,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x8B:
            if(Mario_Transformation >= 1)
            {
                Block->type = Object_Type_DestroyedBrick;
                Block->Sprite = Remove_NonMarioObject_Sprite(Block->Sprite,4);
            }else
            {
                Block->type = Object_Type_BumpedBrick;
                Anim_Object_Brick(Block);
            }
            break;

            case 0x8C:
            Block->type = Object_Type_ObjectBrick;
            Object_Create(Object_Type_Coin,Block->originalPosition.x,Block->originalPosition.y,0);
            break;

            case 0x8D:
            Block->type = Object_Type_ObjectBrick;
            Object_Create(Object_Type_Item_Mushroom,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x8E:
            Block->type = Object_Type_ObjectBrick;
            Object_Create(Mario_Transformation >= 1 ? Object_Type_Item_FireFlower : Object_Type_Item_Mushroom ,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x8F:
            Block->type = Object_Type_ObjectBrick;
            Object_Create(Mario_Transformation >= 1 ? Object_Type_Item_RacoonLeaf : Object_Type_Item_Mushroom,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x90:
            Block->type = Object_Type_ObjectBrick;
            Object_Create(Mario_Transformation >= 1 ? Object_Type_Item_Koopashell : Object_Type_Item_Mushroom,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x94:
            Block->type = Object_Type_ObjectBrick;
            Object_Create(Object_type_Item_Star,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;

            case 0x95:
            Block->type = Object_Type_ObjectBrick;
            Object_Create(Object_Type_Item_1UP,Block->originalPosition.x + 8,Block->originalPosition.y + 16,0);
            break;
        }
    }
}