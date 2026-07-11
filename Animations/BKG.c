#include "../include/Animations/BKG.h"
#include "../include/GameSystem.h"
#include <gb/gb.h>

#pragma bank 2

char coin_animstate = 0;
char qblock_animstate = 0;
char Water_animstate = 0;
char Lava_animstate = 0;

extern char Time;

unsigned char *S_Coin_0;
unsigned char *S_Coin_1;
unsigned char *S_Coin_2;
unsigned char *S_Coin_3;

extern unsigned char S_Coin_Overworld_0[];
extern unsigned char S_Coin_Overworld_1[];
extern unsigned char S_Coin_Overworld_2[];
extern unsigned char S_Coin_Overworld_3[];

extern unsigned char S_Coin_UnderGround_0[];
extern unsigned char S_Coin_UnderGround_1[];
extern unsigned char S_Coin_UnderGround_2[];
extern unsigned char S_Coin_UnderGround_3[];

extern unsigned char S_Lava_0[];
extern unsigned char S_Lava_1[];
extern unsigned char S_Lava_2[];
extern unsigned char S_Lava_3[];

extern unsigned char S_Block_Item_0[];
extern unsigned char S_Block_Item_1[];
extern unsigned char S_Block_Item_2[];
extern unsigned char S_Block_Item_3[];

extern unsigned char S_Water_0[];
extern unsigned char S_Water_1[];
extern unsigned char S_Water_2[];
extern unsigned char S_Water_3[];

/**
 * 
 * @param i
**/
void Set_Anim_Palette(int i)BANKED{
    switch(i){
        case 0:
            S_Coin_0 = S_Coin_Overworld_0;
            S_Coin_1 = S_Coin_Overworld_1;
            S_Coin_2 = S_Coin_Overworld_2;
            S_Coin_3 = S_Coin_Overworld_3;
        break;

        case 1:
            S_Coin_0 = S_Coin_UnderGround_0;
            S_Coin_1 = S_Coin_UnderGround_1;
            S_Coin_2 = S_Coin_UnderGround_2;
            S_Coin_3 = S_Coin_UnderGround_3;
        break;

        case 2:
            S_Coin_0 = S_Coin_Overworld_0;
            S_Coin_1 = S_Coin_Overworld_1;
            S_Coin_2 = S_Coin_Overworld_2;
            S_Coin_3 = S_Coin_Overworld_3;
        break;

        case 3:
            S_Coin_0 = S_Coin_Overworld_0;
            S_Coin_1 = S_Coin_Overworld_1;
            S_Coin_2 = S_Coin_Overworld_2;
            S_Coin_3 = S_Coin_Overworld_3;
        break;
    }
}

/**
 * Update the animations in the background
**/
void Anim_BKG_Update(void) BANKED
{
    Anim_BKG_Coin();
}

void Anim_BKG_Coin(void)BANKED
{
    SWITCH_ROM(2);
    switch (coin_animstate)
    {
        case 0:
        set_bkg_data(0x14,4,S_Coin_0);
        break;

        case 5:
        set_bkg_data(0x14,4,S_Coin_1);
        break;

        case 10:
        set_bkg_data(0x14,4,S_Coin_2);
        break;
       
        case 15:
        set_bkg_data(0x14,4,S_Coin_3);
        break;
    }

    coin_animstate += Time;
    coin_animstate = coin_animstate >= 20 ? 0 : coin_animstate;
}

void Anim_Q_block(void)BANKED
{
    SWITCH_ROM(2);
    switch(qblock_animstate)
    {
        case 0:
        set_bkg_data(0x0D,4,S_Block_Item_0);
        break;

        case 5:
        set_bkg_data(0x0D,4,S_Block_Item_1);
        break;

        case 10:
        set_bkg_data(0x0D,4,S_Block_Item_2);
        break;

        case 15:
        set_bkg_data(0x0D,4,S_Block_Item_3);
        break;
    }
    qblock_animstate += Time;
    qblock_animstate = qblock_animstate >= 20 ? 0 : qblock_animstate;
}

void Anim_Water(void)BANKED
{
    SWITCH_ROM(2);
    switch(Water_animstate)
    {
        case 0:
        set_bkg_data(0x27,2,S_Water_0);
        break;

        case 5:
        set_bkg_data(0x27,2,S_Water_1);
        break;

        case 10:
        set_bkg_data(0x27,2,S_Water_2);
        break;

        case 15:
        set_bkg_data(0x27,2,S_Water_3);
        break;
    }
    Water_animstate += Time;
    Water_animstate = Water_animstate >= 20 ? 0 : Water_animstate;
}

void Anim_Lava(void)BANKED
{
    SWITCH_ROM(2);
    switch(Lava_animstate)
    {
        case 0:
        set_bkg_data(0x29,2,S_Lava_0);
        break;

        case 5:
        set_bkg_data(0x29,2,S_Lava_1);
        break;

        case 10:
        set_bkg_data(0x29,2,S_Lava_2);
        break;

        case 15:
        set_bkg_data(0x29,2,S_Lava_3);
        break;
    }
    Lava_animstate += Time;
    Lava_animstate = Lava_animstate >= 20 ? 0 : Lava_animstate;
}