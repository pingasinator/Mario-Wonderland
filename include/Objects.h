#include "Mathf.h"
#include "collision.h"

#ifndef Objects_H
#define Objects_H

#define Object_Type_Null 0x00
#define Object_Type_Item_Mushroom 0x01
#define Object_Type_Item_FireFlower 0x02
#define Object_Type_Item_RacoonLeaf 0x03
#define Object_Type_Item_Koopashell 0x04
#define Object_Type_Item_Tinyshroom 0x05
#define Object_Type_Item_1UP 0x06
#define Object_type_Item_Star 0x07
#define Object_Type_Coin 0x08
#define Object_Type_HiddenCoin 0x09
#define Object_Type_Block 0x0A
#define Object_Type_Brick 0x0B
#define Object_Type_BumpedBrick 0x0C
#define Object_Type_ObjectBrick 0x0D
#define Object_Type_DestroyedBrick 0x0E
#define Object_Type_Fireball 0x0F


typedef struct 
{
    Vector2 originalPosition;
    Collision hitbox;
    Vector2 velocity;
    int dir;
    char enabled;
    char returnToPoint;
    char Sprite;
    char animstate;
    char type;
    char start;
}Object;

typedef struct 
{
    char enabled;
    Collision hitbox;
    char Sprite;
    char animstate;
    char type;
    char state;
}EndLevelObject;

void Use_Coin(int x,int y) BANKED;
void Objects_Update(void) BANKED;
void Coin_Update(Object *o) BANKED;
void Blocks_Update(Object *o) BANKED;
void HiddenCoin_Update(Object *o) BANKED;

void Q_Block(int Type,int x,int y) BANKED;

void Object_Create_Item(int type,int x,int y)BANKED;
void Object_Create_Coin(int x,int y)  BANKED;
void Object_Create_FireBall(int dir,int x,int y) BANKED;
void Object_Create_HiddenCoin(int x,int y) BANKED;

void Object_Item_Start(Object *o) BANKED;
void Object_Item_Update(Object *o) BANKED;
void Object_Item_Mushroom_Update(Object *o) BANKED;
void Object_Item_StaticItem_Update(Object *o)BANKED;
void Object_Item_Star_Update(Object *o)BANKED;

void FireBall_Update(Object *o) BANKED;
void TileObject_Update(unsigned char Tile,int X,int Y,Vector2 Velocity,int side) BANKED;
#endif