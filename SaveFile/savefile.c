#include "..\include\World.h"
#include "..\include\GameSystem.h"

extern unsigned char World_1_Tilemap[];

World_Point World_1_Points[] = 
{
    {.Level=0,.position={.x=0x01,.y=0x05},.state=0},
    {.Level=1,.position={.x=0x07,.y=0x03},.state=1},
    {.Level=2,.position={.x=0x0C,.y=0x03},.state=1},
    {.Level=0,.position={.x=0x11,.y=0x03},.state=2},
    {.Level=0,.position={.x=0x05,.y=0x0E},.state=2},
    {.Level=3,.position={.x=0x0A,.y=0x0E},.state=1},
    {.Level=4,.position={.x=0x10,.y=0x0D},.state=1},
};

unsigned char LastPoint = 0;

SaveFile SaveFile_1 = {.Worlds=&saveFile_1_World_1};

World saveFile_1_World_1 = {.points=World_1_Points,.tilemap=World_1_Tilemap};
World saveFile_1_World_2 = {.points=World_1_Points,.tilemap=World_1_Tilemap};
World saveFile_1_World_3 = {.points=World_1_Points,.tilemap=World_1_Tilemap};
World saveFile_1_World_4 = {.points=World_1_Points,.tilemap=World_1_Tilemap};