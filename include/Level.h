#include "Mathf.h"
#include "Enemies.h"
#include "Objects.h"

#ifndef Level_H
#define Level_H



typedef struct 
{
    Vector2 Point;
    Vector2 Camera;
    unsigned char LevelID;
    unsigned char Scene;
}Spawn;

typedef struct 
{
    unsigned char *Tilemap;
    Enemy *Enemies;
    Spawn *Spawnpoints;
    char EnemiesCount;
    unsigned char Length;
    unsigned char Width;
    EndLevelObject Endblock;
    unsigned char Palette;
    unsigned char LevelID;
}Scene;

typedef struct
{
    unsigned char StartScene;
    Scene* Scenes;
} Level;

void Level_Set_Scene(unsigned char Index);
void Level_Load_Scene(int SelectedScene);
void EndBlock_Update(void);
void Reset_Level(void);
void SetLevel(int LevelSelected);
void Timer_Update(void);
void ShowLevel(void);
void Set_Level_End(void);
void Level_Update(void);
Level GetLevel(int i);
#endif