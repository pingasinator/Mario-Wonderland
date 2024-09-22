#include "collision.h"

#ifndef Physics_H
#define Physics_H

void ApplyPhysics(Collision *hitbox,Vector2 *velocity);
void ApplyPhysicsOnSide(Collision *hitbox,Vector2 *velocity,int side);
#endif