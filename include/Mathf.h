#ifndef Mathf_H
#define Mathf_H

#define Abs(i) ((i) < 0 ? -(i) : (i))
#define Sign(i) ((i) < 0 ? -1 : (i) > 0 ? 1 : 0)
#define Sqrt(i) ((i) * (i))

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

int Clamp(int value, int min, int max);

#endif