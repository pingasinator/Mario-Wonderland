#include "Mathf.h"
#include "Enemies.h"
#include "Objects.h"

#ifndef Level_H
#define Level_H

typedef struct
{
    unsigned char *Tilemap;
    Enemy *Enemies;
    Vector2 Spawnpoint;
    char EnemiesCount;
    unsigned char Length;
    unsigned char Width;
    EndLevelObject Endblock;
    unsigned char Palette;
    unsigned char LevelID;
} Level;

void EndBlock_Update(void);
void Reset_Level(void);
void SetLevel(int LevelSelected);
void Timer_Update(void);
void ShowLevel(void);
void Set_Level_End(void);
void Level_Update(void);
Level GetLevel(int i);
#endif