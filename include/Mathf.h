#ifndef Mathf_H
#define Mathf_H

typedef struct
{
    int x;
    int y;
    
} Vector2;

typedef struct
{
    Vector2 max;
    Vector2 min;
} Bound;

int Sign(int i);
int Clamp(int value, int min, int max);

#endif