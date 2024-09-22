#ifndef TilePalette_H
#define TilePalette_H

char *DefaultPalette[11] = 
{
    T_null,T_Block_P,T_U_Block_P,T_Alt_Block_P,T_Q_Block_P,T_Coin,T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_UR,T_Pipe_H_DR,
};

char T_null[4] = 
{
    0x00,0x00,0x00,0x00
};

char T_Block_P[4] = 
{
    0x01,0x02,0x03,0x04
};

char T_U_Block_P[4] = 
{
    0x05,0x06,0x07,0x08
};

char T_Alt_Block_P[4] = 
{
    0x09,0x0A,0x0B,0x0C
};

char T_Q_Block_P[4] = 
{
    0x0D,0x0E,0x0F,0X10
};

char T_Coin[4] = 
{
    0x11,0x12,0x13,0x14
};

char T_Pipe_H_UL[4] = 
{
    0x15,0x16,0x17,0x00
};

char T_Pipe_H_DL[4] = 
{
    0x17,0x00,0x18,0x19
};

char T_Pipe_H_UR[4] = 
{
    22,21,0,23
};

char T_Pipe_H_DR[4] = 
{
    22,23,0,24
};



#endif