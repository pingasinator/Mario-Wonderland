#include "include\Enemies.h"

void Update_Enemy(Enemy *e)
{
    switch(e->type)
    {
        case 0:
        Update_Goomba(e);
        break;
    }
}

void Update_Goomba(Enemy *e)
{
    e->velocity.x = Clamp(e->velocity.x,-2,2);
    e->velocity.y = Clamp(e->velocity.y,-2,2);

    e->position.x += e->velocity.x;
    e->position.y += e->velocity.y;
    
}