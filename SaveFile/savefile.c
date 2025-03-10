#include "..\include\World.h"
#include "..\include\GameSystem.h"

World_Point World_1_Points[] = {
    {.Level=0,.position={.x=0x01,.y=0x05},.state=0},
    {.Level=0,.position={.x=0x02,.y=0x05},.state=4},
    {.Level=0,.position={.x=0x04,.y=0x03},.state=4},
    {.Level=1,.position={.x=0x07,.y=0x03},.state=1},
    {.Level=2,.position={.x=0x0C,.y=0x03},.state=1},
    {.Level=0,.position={.x=0x11,.y=0x03},.state=2,.WarpPoint=6},
    {.Level=0,.position={.x=0x05,.y=0x0E},.state=3,.WarpPoint=5},
    {.Level=3,.position={.x=0x0A,.y=0x0E},.state=1},
    {.Level=0,.position={.x=0x0F,.y=0x0E},.state=4},
    {.Level=4,.position={.x=0x10,.y=0x0D},.state=5},
};

unsigned char SavedPoint; 

unsigned char *SaveFile_1_Levels[] = 
{
    SaveFile_1_World_1_Levels,
    SaveFile_1_World_2_Levels,
    SaveFile_1_World_3_Levels,
    SaveFile_1_World_4_Levels,
    SaveFile_1_World_5_Levels,
    SaveFile_1_World_6_Levels,
    SaveFile_1_World_7_Levels,
    SaveFile_1_World_8_Levels,
};

unsigned char SaveFile_1_World_1_Levels[4];
unsigned char SaveFile_1_World_2_Levels[4];
unsigned char SaveFile_1_World_3_Levels[4];
unsigned char SaveFile_1_World_4_Levels[4];
unsigned char SaveFile_1_World_5_Levels[4];
unsigned char SaveFile_1_World_6_Levels[4];
unsigned char SaveFile_1_World_7_Levels[4];
unsigned char SaveFile_1_World_8_Levels[4];

SaveFile SaveFile_1;
SaveFile SaveFile_2;
SaveFile SaveFile_3;

World *World_List[]={
    &World_1,
    &World_2,
    &World_3,
    &World_4,
    &World_5,
    &World_6,
    &World_7,
    &World_8,
};

World World_1 = {.points=World_1_Points,.tilemap=1,.pointsCount=10};
World World_2 = {.points=World_1_Points,.tilemap=2,.pointsCount=0};
World World_3 = {.points=World_1_Points,.tilemap=3,.pointsCount=0};
World World_4 = {.points=World_1_Points,.tilemap=4,.pointsCount=0};
World World_5 = {.points=World_1_Points,.tilemap=5,.pointsCount=0};
World World_6 = {.points=World_1_Points,.tilemap=6,.pointsCount=0};
World World_7 = {.points=World_1_Points,.tilemap=7,.pointsCount=0};
World World_8 = {.points=World_1_Points,.tilemap=8,.pointsCount=0};