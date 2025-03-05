
#pragma bank 2

extern unsigned char T_null[];
extern unsigned char T_Grey_Light[];
extern unsigned char T_Grey_Dark[];
extern unsigned char T_Black[];
extern unsigned char T_Coin[];
extern unsigned char T_Lava_Top[];
extern unsigned char T_Water_Top[];
extern unsigned char T_End_Background[];
extern unsigned char T_End_Block_UL[];
extern unsigned char T_End_Block_UR[];
extern unsigned char T_End_Block_DL[];
extern unsigned char T_End_Block_DR[];
extern unsigned char T_Overworld_background_Cloud_0[];
extern unsigned char T_Overworld_background_Cloud_1[];
extern unsigned char T_Overworld_background_Cloud_2[];
extern unsigned char T_Overworld_background_Cloud_3[];

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
extern unsigned char T_Cloud[];

extern unsigned char T_Overworld_Ground_0[];
extern unsigned char T_Overworld_Ground_1[];
extern unsigned char T_Overworld_Ground_2[];
extern unsigned char T_Overworld_Ground_3[];
extern unsigned char T_Overworld_Ground_4[];
extern unsigned char T_Overworld_Ground_5[];
extern unsigned char T_Overworld_Ground_6[];
extern unsigned char T_Overworld_Ground_7[];
extern unsigned char T_Overworld_Ground_8[];
extern unsigned char T_Overworld_Ground_9[];
extern unsigned char T_Overworld_Ground_10[];
extern unsigned char T_Overworld_Ground_11[];
extern unsigned char T_Overworld_Ground_12[];
extern unsigned char T_Overworld_Ground_13[];
extern unsigned char T_Overworld_Ground_14[];
extern unsigned char T_Overworld_Ground_15[];
extern unsigned char T_Overworld_Ground_16[];

extern unsigned char T_Underground_Ground_0[];
extern unsigned char T_Underground_Ground_1[];
extern unsigned char T_Underground_Ground_2[];
extern unsigned char T_Underground_Ground_3[];
extern unsigned char T_Underground_Ground_4[];
extern unsigned char T_Underground_Ground_5[];
extern unsigned char T_Underground_Ground_6[];
extern unsigned char T_Underground_Ground_7[];
extern unsigned char T_Underground_Ground_8[];
extern unsigned char T_Underground_Ground_9[];
extern unsigned char T_Underground_Ground_10[];
extern unsigned char T_Underground_Ground_11[];
extern unsigned char T_Underground_Ground_12[];
extern unsigned char T_Underground_Ground_13[];
extern unsigned char T_Underground_Ground_14[];
extern unsigned char T_Underground_Ground_15[];
extern unsigned char T_Underground_Ground_16[];

extern unsigned char T_Airship_Ground_0[];
extern unsigned char T_Airship_Ground_1[];
extern unsigned char T_Airship_Ground_2[];
extern unsigned char T_Airship_Ground_3[];
extern unsigned char T_Airship_Ground_4[];
extern unsigned char T_Airship_Ground_5[];
extern unsigned char T_Airship_Ground_6[];
extern unsigned char T_Airship_Ground_7[];
extern unsigned char T_Airship_Ground_8[];
extern unsigned char T_Airship_Ground_9[];
extern unsigned char T_Airship_Ground_10[];
extern unsigned char T_Airship_Ground_11[];
extern unsigned char T_Airship_Ground_12[];
extern unsigned char T_Airship_Ground_13[];
extern unsigned char T_Airship_Ground_14[];
extern unsigned char T_Airship_Ground_15[];
extern unsigned char T_Airship_Ground_16[];

const unsigned char *Overworld_Background_Palette[] = 
{
    T_null,T_Grey_Light,T_Grey_Dark,T_Black,T_Coin,T_Lava_Top,T_Grey_Dark,T_Water_Top,T_Grey_Light,T_End_Background,T_End_Block_UL,T_End_Block_UR,T_End_Block_DL,T_End_Block_DR,
    T_Overworld_background_Cloud_0,T_Overworld_background_Cloud_1,T_Overworld_background_Cloud_2,T_Overworld_background_Cloud_3
};

const unsigned char *Overworld_Ground_Palette[] = 
{
    T_null,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Brick,T_Brick,T_Brick,T_Brick,T_Alt_Block,T_Used_Block,T_Pipe_V_UL,T_Pipe_V_UR,T_Pipe_V_ML,T_Pipe_V_MR,T_Pipe_V_DL,T_Pipe_V_DR,
    T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_MU,T_Pipe_H_MD,T_Pipe_H_DR,T_Pipe_H_UR,T_Pipe_V_UL,T_Pipe_V_UR,T_Pipe_V_DL,T_Pipe_V_DR,T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_DR,T_Pipe_H_UR,
    T_Cloud,T_Overworld_Ground_0,T_Overworld_Ground_1,T_Overworld_Ground_2,T_Overworld_Ground_3,T_Overworld_Ground_4,T_Overworld_Ground_5,T_Overworld_Ground_6,T_Overworld_Ground_7,
    T_Overworld_Ground_8,T_Overworld_Ground_9,T_Overworld_Ground_10,T_Overworld_Ground_11,T_Overworld_Ground_12,T_Overworld_Ground_13,T_Overworld_Ground_14,T_Overworld_Ground_15,
    T_Overworld_Ground_16
};

const unsigned char *Underground_Ground_Palette[] = 
{
    T_null,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Brick,T_Brick,T_Brick,T_Brick,T_Alt_Block,T_Used_Block,T_Pipe_V_UL,T_Pipe_V_UR,T_Pipe_V_ML,T_Pipe_V_MR,T_Pipe_V_DL,T_Pipe_V_DR,
    T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_MU,T_Pipe_H_MD,T_Pipe_H_DR,T_Pipe_H_UR,T_Pipe_V_UL,T_Pipe_V_UR,T_Pipe_V_DL,T_Pipe_V_DR,T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_DR,T_Pipe_H_UR,
    T_Cloud,T_Underground_Ground_0,T_Underground_Ground_1,T_Underground_Ground_2,T_Underground_Ground_3,T_Underground_Ground_4,T_Underground_Ground_5,T_Underground_Ground_6,
    T_Underground_Ground_7,T_Underground_Ground_8,T_Underground_Ground_9,T_Underground_Ground_10,T_Underground_Ground_11,T_Underground_Ground_12,T_Underground_Ground_13,T_Underground_Ground_14,
    T_Underground_Ground_15
};

const unsigned char *Underground_Background_Palette[] = 
{
    T_null,T_Grey_Light,T_Grey_Dark,T_Black,T_Coin,T_Water_Top,T_Grey_Light,T_Lava_Top,T_Grey_Dark,T_End_Background,T_End_Block_UL,T_End_Block_UR,T_End_Block_DL,T_End_Block_DR,

};

const unsigned char *Airship_Ground_Palette[] = 
{
    T_null,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Brick,T_Brick,T_Brick,T_Brick,T_Alt_Block,T_Used_Block,T_Pipe_V_UL,T_Pipe_V_UR,T_Pipe_V_ML,T_Pipe_V_MR,T_Pipe_V_DL,T_Pipe_V_DR,
    T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_MU,T_Pipe_H_MD,T_Pipe_H_DR,T_Pipe_H_UR,T_Pipe_V_UL,T_Pipe_V_UR,T_Pipe_V_DL,T_Pipe_V_DR,T_Pipe_H_UL,T_Pipe_H_DL,T_Pipe_H_DR,T_Pipe_H_UR,
    T_Cloud,T_Airship_Ground_0,T_Airship_Ground_1,T_Airship_Ground_2,T_Airship_Ground_3,T_Airship_Ground_4,T_Airship_Ground_5,T_Airship_Ground_6,T_Airship_Ground_7,
    T_Airship_Ground_8,T_Airship_Ground_9,T_Airship_Ground_10,T_Airship_Ground_11,T_Airship_Ground_12,T_Airship_Ground_13,T_Airship_Ground_14,T_Airship_Ground_15,
    T_Airship_Ground_16
};


const unsigned char *Airship_Background_Palette[] = 
{
    T_null,T_Grey_Light,T_Grey_Dark,T_Black,T_Coin,T_Water_Top,T_Grey_Light,T_Lava_Top,T_Grey_Dark,T_End_Background,T_End_Block_UL,T_End_Block_UR,T_End_Block_DL,T_End_Block_DR,
};