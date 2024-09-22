#include "Mathf.h"

#ifndef Collision_H
#define Collision_H

typedef struct 
{

    Vector2 position;
    Vector2 pixelsize;
    Vector2 pixeloffset;
}Collision;

int Raycast(Vector2 point,Vector2 dir,int pixelSize);

int OnCollision(Collision A,Collision B);
int OnCollisionSide(Collision A,Collision B,Vector2 *A_velocity,Vector2 *B_velocity, int side);
int TileMapCollision(Collision A);
int TileMapCollisionSide(Collision *A,int side);
#endif