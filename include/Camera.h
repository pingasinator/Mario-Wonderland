#include "Mathf.h"

#ifndef Game_H
#define Game_H

Vector2 GetCamera(void);
Vector2 GetCameraCenter(void);
Vector2 GetVRamCamera(int i);
void MoveCamera(int x,int y);
Vector2 GetPositionInVram(Vector2 position);
#endif