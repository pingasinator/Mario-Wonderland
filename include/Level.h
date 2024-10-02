#include "Mathf.h"
#include "Enemies.h"

#ifndef Level_H
#define Level_H

typedef struct
{
    unsigned char *Tilemap;
    Enemy *Enemies;
    Vector2 Spawnpoint;
} Level;

void SetLevel(int LevelSelected);
void ShowLevel(void);
void Level_Update(void);
Level GetLevel(int i);
#endif