#include "Mathf.h"

#ifndef Level_H
#define Level_H

typedef struct
{
    Vector2 position;
    Vector2 MinBounds;
    Vector2 MaxBounds;
} Screen;

void SetLevel(void);
void ShowLevel(void);
Screen GetCurrentScreen(void);
void Level_Update(void);

Screen *GetCurrentLevel(void);
#endif