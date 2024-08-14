#include "Mathf.h"

#ifndef Level_H
#define Level_H

typedef struct
{
    unsigned char* Tilemap;
    Vector2 position;
    int ID;
    Vector2 MinBounds;
    Vector2 MaxBounds;
} Screen;

void SetLevel(void);
void ShowLevel(void);
void initLevelVram(void);
Screen GetCurrentScreen(void);
void Level_Update(void);

Screen *GetCurrentLevel(void);
#endif