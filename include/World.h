#include "Mathf.h"

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
}World;

void World_Update(void);
void World_HUD_Update(void);
void World_Display_Mario(void);

#endif