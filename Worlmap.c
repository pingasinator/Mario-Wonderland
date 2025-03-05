
#include "include\World.h"
#include "include\Sprite.h"
#include "include\GameSystem.h"
#include "include\Level.h"
#include "include\Animations\Mario\WorldMario.h"
#include <gb\gb.h>

extern char Time;
extern char Coins;
extern char Lifes;
extern unsigned char World_1_Tilemap[];

extern unsigned char allInputsDown[];
extern unsigned char LastPoint;
extern World saveFile_1_World_1;

Vector2 World_Mario_Position;

unsigned char World_Dir;

World_Point point;

unsigned char World_HUD[] = {0x6D,0x6E,0x70,0x70,0x07,0x6F,0x6E,0x70,0x70,0x07,0x07,0x07,0x7A,0x7B,0x7C,0x7D,0x7E,0x71,0x7F,0x71};

int Mario_World_Animstate = 0;

char currentWorld;

void init_World(void)
{

}

void World_Update(void)
{
    ENABLE_RAM;
    SWITCH_RAM(1);
    Reset_Vram();
    move_bkg(0,0);
    Time = 1;
    init_World_Mario_Vram();
    init_World_Vram();
    init_World_BKG(World_1_Tilemap);

    World_Dir = LastPoint;

    while(1)
    {
        Input_Update();
        World_Mario_Position.x = point.position.x * 8;
        World_Mario_Position.y = point.position.y * 8;
        point = saveFile_1_World_1.points[World_Dir];
        if(allInputsDown[2])
        {
            World_Dir--;
            World_Dir = Clamp(World_Dir,0,7);
        }else if(allInputsDown[1])
        {
            World_Dir++;
            World_Dir = Clamp(World_Dir,0,7);
        }else if(allInputsDown[5])
        {
            switch(point.state)
            {
                case 1:
                Anim_Mario_World_EnterLevel();
                delay(500);
                SetLevel(point.Level);
                Set_GameMode(1);
                Save();
                goto EOL;
                break;

                case 2:
                World_Dir = point.WarpPoint;
                break;
            }

        }

        Anim_Mario_World_Down(Mario_World_Animstate);
        Mario_World_Animstate++;
        Mario_World_Animstate = Mario_World_Animstate >= 20 ? 0 : Mario_World_Animstate;
        World_HUD_Update();
        World_Display_Mario();
        SHOW_WIN;
        SHOW_BKG;
        SHOW_SPRITES;
        delay(60);
    }
    EOL:
    DISABLE_RAM;
}

void World_Display_Mario(void)
{
    move_sprite(0,World_Mario_Position.x + 4,World_Mario_Position.y + 8);
    move_sprite(1,World_Mario_Position.x + 12,World_Mario_Position.y + 8);
    move_sprite(2,World_Mario_Position.x + 4,World_Mario_Position.y + 16);
    move_sprite(3,World_Mario_Position.x + 12,World_Mario_Position.y + 16);
}

void World_HUD_Update(void)
{
    World_HUD[2] = 0x70 + Lifes / 10;
    World_HUD[3] = 0x70 + (Lifes - Lifes / 10);
    World_HUD[7] = 0x70 + Coins / 10;
    World_HUD[8] = 0x70 + (Coins - Coins / 10);
    move_win(7,136);
    
    set_win_tiles(0,0,20,1,World_HUD);
}