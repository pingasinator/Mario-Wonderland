#include "include\Mathf.h"

int Sign(int i)
{
    return i < 0 ? -1 : i > 0 ? 1 : 0;
}

int Clamp(int value, int min, int max)
{
    return value < min ? min : value > max ? max : value;
}