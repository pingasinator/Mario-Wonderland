#include "include/Mathf.h"


int Clamp(int value, int min, int max)
{
    return value <= min ? min : value >= max ? max : value;
}