#include "Mathf.h"
#include <gb/gb.h>

#ifndef Collision_H
#define Collision_H

typedef struct 
{
    Vector2 position;
    Vector2 pixelsize;
    Vector2 pixeloffset;
}Collision;

int Raycast(Vector2 point,Vector2 dir,int pixelSize) BANKED;

int OnCollision(Collision A,Collision B) BANKED;
int OnCollisionSide(Collision A,Collision B, int side) BANKED;
void TilemapCollisionPhysics(Collision *A,Vector2* Velocity) BANKED;
void TilemapCollisionPhysicsSide(Collision *A,Vector2* Velocity,int side) BANKED;
void MarioTilemapCollisionPhysics(Collision *A,Vector2* Velocity) BANKED;
#endif