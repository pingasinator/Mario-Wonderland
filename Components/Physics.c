#include "..\include\collision.h"
#include "..\include\Physic.h"
#include <gb\gb.h>

#pragma bank 12

void ApplyPhysics(Collision *hitbox,Vector2 *velocity) BANKED
{
    Vector2 max = {.x=TileMapCollisionSide(hitbox,3),.y=TileMapCollisionSide(hitbox,1)};
    Vector2 min = {.x=TileMapCollisionSide(hitbox,2),.y=TileMapCollisionSide(hitbox,0)};


    if((min.y == 1 && velocity->y > 0) || (max.y == 1 && velocity->y < 0))
    {
        velocity->y = 0;
    }

    if((max.x == 1 && velocity->x > 0) || (min.x == 1 && velocity->x < 0))
    {
        velocity->x = 0;
    }

    while(max.y == 3 && min.y == 0)
    {
        hitbox->position.y++;
        velocity->y = 0;
        max.y=TileMapCollisionSide(hitbox,1);
        min.y=TileMapCollisionSide(hitbox,0);

        if(max.y == 1)
        {
            break;
        }
    }

    while(max.x == 3  && min.x == 0)
    {
        hitbox->position.x--;
        velocity->x = 0;
        max.x=TileMapCollisionSide(hitbox,3);
        min.x=TileMapCollisionSide(hitbox,2);
        if(max.x == 1)
        {
            break;
        }
    }

    while(min.x == 3  && max.x == 0)
    {
        hitbox->position.x++;
        velocity->x = 0;
        max.x=TileMapCollisionSide(hitbox,3);
        min.x=TileMapCollisionSide(hitbox,2);
        if(min.x == 1)
        {
            break;
        }
    }

    while(min.y == 3 && max.y == 0)
    {
        hitbox->position.y--;
        velocity->y = 0;
        max.y=TileMapCollisionSide(hitbox,1);
        min.y=TileMapCollisionSide(hitbox,0);

        if(min.y == 1)
        {
            break;
        }
    }

}

void ApplyPhysicsOnSide(Collision *hitbox,Vector2 *velocity,int side) BANKED
{
    switch(side)
    {
        case 0:
        char A = TileMapCollisionSide(hitbox,0);

        if(A == 1 && velocity->y > 0)
        {
            velocity->y = 0;
        }

        while(A == 3)
        {
            hitbox->position.y--;
            velocity->y = 0;
            A = TileMapCollisionSide(hitbox,0);
            if(A == 1)
            {
                break;
            }
        }   
        break;
    }
}