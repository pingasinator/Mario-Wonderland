#include <gb\gb.h>
#include "..\Objects.h"

#ifndef Animation_Objects_H
#define Animation_Objects_H

#define Object_Type_Null 0x00
#define Object_Type_Coin 0x01
#define Object_Type_Block 0x02
#define Object_Type_Brick 0x03
#define Object_Type_BumpedBrick 0x04
#define Object_Type_ObjectBrick 0x05
#define Object_Type_DestroyedBrick 0x06
#define Object_Type_Mushroom 0x07

void Anim_Object_Coin(Object *o) BANKED;
void Anim_Object_Block(Object *o) BANKED;
void Anim_Object_Brick(Object *o) BANKED;
void Anim_Object_Fireball(Object *o) BANKED;
void Anim_Object_EndBlock(EndLevelObject *o) BANKED;
#endif