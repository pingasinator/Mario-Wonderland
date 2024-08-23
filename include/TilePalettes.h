#ifndef TilePalette_H
#define TilePalette_H

char *Overworld_Palette[11] = 
{
    T_null,T_Block_P,T_Q_Block_P,T_U_Block_P,T_Alt_Block_P,T_Coin,T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_UR,T_Pipe_H_DR
};

char T_null[4] = 
{
    0,0,0,0
};

char T_Block_P[4] = 
{
    1,2,3,4
};

char T_Q_Block_P[4] = 
{
    5,6,7,8
};

char T_U_Block_P[4] = 
{
    9,10,11,12
};

char T_Alt_Block_P[4] = 
{
    13,14,15,16
};

char T_Coin[4] = 
{
    17,18,19,20
};

char T_Pipe_H_UL[4] = 
{
    21,22,23,0
};

char T_Pipe_H_DL[4] = 
{
    23,0,24,25
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