#include "..\include\Animations\BKG.h"
#include "..\include\GameSystem.h"
#include <gb\gb.h>

int coin_animstate = 0;
int qblock_animstate = 0;
int Water_animstate = 0;
int Lava_animstate = 0;

extern unsigned char S_Coin_0[];
extern unsigned char S_Coin_1[];
extern unsigned char S_Coin_2[];
extern unsigned char S_Coin_3[];

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

void Anim_BKG_Update(void)
{
    Anim_BKG_Coin();
    Anim_Q_block();
    Anim_Water();
    Anim_Lava();
}

void Anim_BKG_Coin(void)
{
    SWITCH_ROM(3);
    switch (coin_animstate)
    {
        case 0:
        set_bkg_data(0x11,4,S_Coin_0);
        break;

        case 5:
        set_bkg_data(0x11,4,S_Coin_1);
        break;

        case 10:
        set_bkg_data(0x11,4,S_Coin_2);
        break;
       
        case 15:
        set_bkg_data(0x11,4,S_Coin_3);
        break;
    }

    coin_animstate += Get_Time();
    coin_animstate = coin_animstate >= 20 ? 0 : coin_animstate;
}

void Anim_Q_block(void)
{
    SWITCH_ROM(3);
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
    qblock_animstate += Get_Time();
    qblock_animstate = qblock_animstate >= 20 ? 0 : qblock_animstate;
}

void Anim_Water(void)
{
    SWITCH_ROM(3);
    switch(Water_animstate)
    {
        case 0:
        set_bkg_data(0x23,2,S_Water_0);
        break;

        case 5:
        set_bkg_data(0x23,2,S_Water_1);
        break;

        case 10:
        set_bkg_data(0x23,2,S_Water_2);
        break;

        case 15:
        set_bkg_data(0x23,2,S_Water_3);
        break;
    }
    Water_animstate += Get_Time();
    Water_animstate = Water_animstate >= 20 ? 0 : Water_animstate;
}

void Anim_Lava(void)
{
    SWITCH_ROM(3);
    switch(Lava_animstate)
    {
        case 0:
        set_bkg_data(0x25,2,S_Lava_0);
        break;

        case 5:
        set_bkg_data(0x25,2,S_Lava_1);
        break;

        case 10:
        set_bkg_data(0x25,2,S_Lava_2);
        break;

        case 15:
        set_bkg_data(0x25,2,S_Lava_3);
        break;
    }
    Lava_animstate += Get_Time();
    Lava_animstate = Lava_animstate >= 20 ? 0 : Lava_animstate;
}