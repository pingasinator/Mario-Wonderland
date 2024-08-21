#include "Mathf.h"

#ifndef Collision_H
#define Collision_H

typedef struct 
{
    Vector2 size;
    Vector2 offset;
    Vector2 position;
    Vector2 pixelsize;
    Vector2 pixeloffset;
}Collision;

int Raycast(Vector2 point,Vector2 dir,Vector2 velocity,int size,int pixelSize);

int OnCollision(Collision A,Collision B);
int TileMapCollision(Collision A);
int TileMapCollisionSide(Collision A,Vector2 *velocity,int side);
#endif