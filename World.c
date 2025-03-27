
#include "include\World.h"
#include "include\Sprite.h"
#include "include\GameSystem.h"
#include "include\Level.h"
#include "include\Animations\Mario\WorldMario.h"
#include <gb\gb.h>

extern char Time;
extern char Coins;
extern char Lifes;

extern unsigned char allInputsDown[];
extern unsigned char SavedPoint;

extern char GameMode;

extern SaveFile *currentSaveFile;
extern SaveFile SaveFile_1;

Vector2 World_Mario_Position;
Vector2 World_Mario_Dir;

char World_Dir;
char Last_Dir;

World_Point lastPoint;
World_Point currentPoint;

unsigned char World_HUD[] = {0x6D,0x6E,0x70,0x70,0x07,0x6F,0x6E,0x70,0x70,0x07,0x07,0x07,0x7A,0x7B,0x7C,0x7D,0x7E,0x71,0x7F,0x71};

int Mario_World_Animstate = 0;

extern World *World_List[];
World *currentWorld;

void World_Update(void)
{
    ENABLE_RAM;
    SWITCH_RAM(1);

    currentSaveFile = &SaveFile_1;
    Reset_Vram();
    move_bkg(0,0);
    Time = 1;
    init_World_Mario_Vram();
    SWITCH_ROM(2);
    init_World_Vram();
    init_World_BKG(SaveFile_1.LastWorld);

    currentWorld = World_List[0];

    World_Dir = currentSaveFile->LastLevel;
    World_Mario_Position.x = currentWorld->points[World_Dir].position.x * 8;
    World_Mario_Position.y = currentWorld->points[World_Dir].position.y * 8;

    while(1)
    {
        Input_Update();
        currentPoint = currentWorld->points[World_Dir];
        World_Mario_Dir.x = -Sign(World_Mario_Position.x - currentPoint.position.x * 8) * 2;
        World_Mario_Dir.y = -Sign(World_Mario_Position.y - currentPoint.position.y * 8) * 2;
        World_Mario_Position.x += World_Mario_Dir.x;
        World_Mario_Position.y += World_Mario_Dir.y;

        if(World_Mario_Dir.x == 0 && World_Mario_Dir.y == 0)
        {
            if(currentPoint.state == 4)
            {
                if(Last_Dir == World_Dir - 1)
                {
                    lastPoint = currentPoint;
                    Last_Dir = World_Dir;
                    World_Dir++;
                    World_Dir = Clamp(World_Dir,0,currentWorld->pointsCount - 1);

                }else if(Last_Dir == World_Dir + 1)
                {
                    lastPoint = currentPoint;
                    Last_Dir = World_Dir;
                    World_Dir--;
                    World_Dir = Clamp(World_Dir,0,currentWorld->pointsCount - 1);
                }
            }else
            {
                if(allInputsDown[2])
                {
                    if(currentPoint.state != 3)
                    {
                        lastPoint = currentPoint;
                        Last_Dir = World_Dir;
                        World_Dir--;
                        World_Dir = Clamp(World_Dir,0,currentWorld->pointsCount - 1);
                    }
    
                }else if(allInputsDown[1])
                {
                    if((currentPoint.state != 2 && currentPoint.state != 1 )|| (currentPoint.state == 1 && SaveFile_1.Levels[0][currentPoint.Level - 1]))
                    {
                        lastPoint = currentPoint;
                        Last_Dir = World_Dir;
                        World_Dir++;
                        World_Dir = Clamp(World_Dir,0,currentWorld->pointsCount - 1);
                    }
                }else if(allInputsDown[5])
                {
                    switch(currentPoint.state)
                    {
                        case 1:
                        case 5:
                        Anim_Mario_World_EnterLevel();
                        delay(500);
                        SetLevel(currentPoint.Level);
                        GameMode = 1;
                        Save();
                        goto EOL;
                        break;
            
                        case 2:
                        case 3:
                        World_Dir = currentPoint.WarpPoint;
                        currentPoint = currentWorld->points[World_Dir];
                        World_Mario_Position.x = currentPoint.position.x * 8;
                        World_Mario_Position.y = currentPoint.position.y * 8;
                        break;
                    }
                }
            }

        }

        Anim_Mario_World_Move(Mario_World_Animstate);
        Mario_World_Animstate++;
        Mario_World_Animstate = Mario_World_Animstate >= 15 ? 0 : Mario_World_Animstate;
        for(int i = 0;i < currentWorld->pointsCount;i++)
        {
            if(currentWorld->points[i].state == 1)
            {
                set_bkg_tile_xy(currentWorld->points[i].position.x,currentWorld->points[i].position.y,SaveFile_1.Levels[0][currentWorld->points[i].Level - 1] ? 0x2C : 0x3C);
            }else if(currentWorld->points[i].state == 5)
            {
                set_bkg_tile_xy(currentWorld->points[i].position.x,currentWorld->points[i].position.y - 1,SaveFile_1.Levels[0][currentWorld->points[i].Level - 1] ? 0x0E : 0x0C );
                set_bkg_tile_xy(currentWorld->points[i].position.x + 1,currentWorld->points[i].position.y - 1,SaveFile_1.Levels[0][currentWorld->points[i].Level - 1] ? 0x0F : 0x0D);
                set_bkg_tile_xy(currentWorld->points[i].position.x,currentWorld->points[i].position.y,SaveFile_1.Levels[0][currentWorld->points[i].Level - 1] ? 0x1E :  0x1C);
                set_bkg_tile_xy(currentWorld->points[i].position.x + 1,currentWorld->points[i].position.y,SaveFile_1.Levels[0][currentWorld->points[i].Level - 1] ? 0x1F :  0x1D);
            }

        }
        World_HUD_Update();
        SHOW_WIN;
        SHOW_BKG;
        SHOW_SPRITES;
        delay(30);
    }

    EOL:
    DISABLE_RAM;
}

void Set_Level_Clear(int index)
{
    ENABLE_RAM;
    SWITCH_RAM(1);
    for(int i = 0; i < currentWorld->pointsCount;i++)
    {
        if(currentWorld->points[i].Level == index)
        {
            SaveFile_1.Levels[0][currentWorld->points[i].Level - 1] = 1;
        }
    }

    DISABLE_RAM;
}

void World_HUD_Update(void)
{
    World_HUD[2] = 0x70 + Lifes / 10;
    World_HUD[3] = 0x70 + (Lifes - (Lifes / 10) * 10);
    World_HUD[7] = 0x70 + Coins / 10;
    World_HUD[8] = 0x70 + (Coins - (Coins / 10) * 10);
    World_HUD[19] = 0x70 + currentPoint.Level;
    move_win(7,136);
    
    set_win_tiles(0,0,20,1,World_HUD);
}