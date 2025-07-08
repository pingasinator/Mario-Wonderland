#pragma bank 2 

extern unsigned char T_null[];
extern unsigned char T_Grey_Light[];
extern unsigned char T_Grey_Dark[];
extern unsigned char T_Black[];
extern unsigned char T_Coin[];
extern unsigned char T_Hidden_Coin[];
extern unsigned char T_Lava_Top[];
extern unsigned char T_Water_Top[];
extern unsigned char T_End_Background[];
extern unsigned char T_End_Block_UL[];
extern unsigned char T_End_Block_UR[];
extern unsigned char T_End_Block_DL[];
extern unsigned char T_End_Block_DR[];

extern unsigned char T_Q_Block[];
extern unsigned char T_Brick[];
extern unsigned char T_Alt_Block[];
extern unsigned char T_Used_Block[];
extern unsigned char T_Pipe_V_UL[];
extern unsigned char T_Pipe_V_UR[];
extern unsigned char T_Pipe_V_ML[];
extern unsigned char T_Pipe_V_MR[];
extern unsigned char T_Pipe_V_DL[];
extern unsigned char T_Pipe_V_DR[];
extern unsigned char T_Pipe_H_UL[];
extern unsigned char T_Pipe_H_DL[];
extern unsigned char T_Pipe_H_MU[];
extern unsigned char T_Pipe_H_MD[];
extern unsigned char T_Pipe_H_DR[];
extern unsigned char T_Pipe_H_UR[];

extern unsigned char T_OW_Ground_0[];
extern unsigned char T_OW_Ground_1[];
extern unsigned char T_OW_Ground_2[];
extern unsigned char T_OW_Ground_3[];
extern unsigned char T_OW_Ground_4[];
extern unsigned char T_OW_Ground_5[];
extern unsigned char T_OW_Ground_6[];
extern unsigned char T_OW_Ground_7[];
extern unsigned char T_OW_Ground_8[];
extern unsigned char T_OW_Ground_9[];
extern unsigned char T_OW_Ground_10[];
extern unsigned char T_OW_Ground_11[];
extern unsigned char T_OW_Ground_12[];
extern unsigned char T_OW_Ground_13[];
extern unsigned char T_OW_Ground_14[];
extern unsigned char T_OW_Ground_15[];
extern unsigned char T_OW_Ground_16[];
extern unsigned char T_OW_Ground_17[];
extern unsigned char T_OW_Ground_18[];
extern unsigned char T_OW_Ground_19[];

extern unsigned char T_OW_background_0[];
extern unsigned char T_OW_background_1[];
extern unsigned char T_OW_background_2[];
extern unsigned char T_OW_background_3[];
extern unsigned char T_OW_background_4[];
extern unsigned char T_OW_background_5[];
extern unsigned char T_OW_background_6[];
extern unsigned char T_OW_background_7[];
extern unsigned char T_OW_background_8[];
extern unsigned char T_OW_background_9[];
extern unsigned char T_OW_background_10[];
extern unsigned char T_OW_background_11[];
extern unsigned char T_OW_background_12[];
extern unsigned char T_OW_background_13[];
extern unsigned char T_OW_background_14[];
extern unsigned char T_OW_background_15[];

const unsigned char *Overworld_Ground_Palette[] = 
{
    T_Grey_Light,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,
    T_Alt_Block,T_Used_Block,T_Pipe_V_UL,T_Pipe_V_UR,T_Pipe_V_ML,T_Pipe_V_MR,T_Pipe_V_DL,T_Pipe_V_DR,T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_MU,T_Pipe_H_MD,T_Pipe_H_DR,T_Pipe_H_UR,T_Pipe_V_UL,T_Pipe_V_UR,
    T_Pipe_V_DL,T_Pipe_V_DR,T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_DR,T_Pipe_H_UR,T_OW_Ground_0,T_OW_Ground_1,T_OW_Ground_2,T_OW_Ground_3,T_OW_Ground_4,T_OW_Ground_5,
    T_OW_Ground_6,T_OW_Ground_7,T_OW_Ground_8,T_OW_Ground_9,T_OW_Ground_10,T_OW_Ground_11,T_OW_Ground_12,T_OW_Ground_13,T_OW_Ground_14,
    T_OW_Ground_15,T_OW_Ground_16,T_OW_Ground_17,T_OW_Ground_18,T_OW_Ground_19
};

const unsigned char *Overworld_Background_Palette[] = 
{
    T_Grey_Light,T_null,T_Grey_Dark,T_Black,T_Coin,T_Hidden_Coin,T_Lava_Top,T_Grey_Dark,T_Water_Top,T_Grey_Light,T_End_Background,T_End_Block_UL,T_End_Block_UR,T_End_Block_DL,T_End_Block_DR,
    T_OW_background_0,T_OW_background_1,T_OW_background_2,T_OW_background_3,T_OW_background_4,T_OW_background_5,T_OW_background_6,T_OW_background_7,
    T_OW_background_8,T_OW_background_9,T_OW_background_10,T_OW_background_11,T_OW_background_12,T_OW_background_13,T_OW_background_14,T_OW_background_15
};
