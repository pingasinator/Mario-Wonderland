#include "..\include\Animations\BKG.h"
#include "..\Sprites\AnimatedTiles.h"
#include <gb\gb.h>

int coin_animstate = 0;
int qblock_animstate = 0;

void Anim_BKG_Update(void)
{
    Anim_BKG_Coin();
    Anim_Q_block();
}

void Anim_BKG_Coin(void)
{
    switch (coin_animstate)
    {
        case 0:
        set_bkg_data(0x11,4,Coin_0);
        break;

        case 5:
        set_bkg_data(0x11,4,Coin_1);
        break;

        case 10:
        set_bkg_data(0x11,4,Coin_2);
        break;
       
        case 15:
        set_bkg_data(0x11,4,Coin_3);
        break;
    }

    coin_animstate++;
    coin_animstate = coin_animstate >= 20 ? 0 : coin_animstate;
}

void Anim_Q_block(void)
{
    switch(qblock_animstate)
    {
        case 0:
        set_bkg_data(0x0D,4,Block_Item_0);
        break;

        case 5:
        set_bkg_data(0x0D,4,Block_Item_1);
        break;

        case 10:
        set_bkg_data(0x0D,4,Block_Item_2);
        break;

        case 15:
        set_bkg_data(0x0D,4,Block_Item_3);
        break;
    }
    qblock_animstate++;
    qblock_animstate = qblock_animstate >= 20 ? 0 : qblock_animstate;
}