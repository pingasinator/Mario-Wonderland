#include "Mathf.h"
#include <gb/gb.h>

#ifndef World_H
#define World_H

typedef struct 
{
    Vector2 position;
    unsigned char state;
    unsigned char Level;
    unsigned char WarpPoint;
}World_Point;

typedef struct
{
    World_Point *points;
    unsigned char *tilemap;
    unsigned char pointsCount;
}World;

void World_Update(void);
void World_HUD_Update(void);
void Set_Level_Clear(int index);
#endif