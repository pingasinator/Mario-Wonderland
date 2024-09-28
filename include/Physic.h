#include "collision.h"
#include <gb\gb.h>

#ifndef Physics_H
#define Physics_H

void ApplyPhysics(Collision *hitbox,Vector2 *velocity) BANKED;
void ApplyPhysicsOnSide(Collision *hitbox,Vector2 *velocity,int side) BANKED;
#endif