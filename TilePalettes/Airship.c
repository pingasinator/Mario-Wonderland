#pragma bank 5

extern unsigned char T_null[];
extern unsigned char T_Grey_Light[];
extern unsigned char T_Grey_Dark[];
extern unsigned char T_Black[];
extern unsigned char T_Coin[];
extern unsigned char T_Hidden_Coin[];
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
extern unsigned char T_Pipe_V_Head_L[];
extern unsigned char T_Pipe_V_Head_R[];
extern unsigned char T_Pipe_V_Body_L[];
extern unsigned char T_Pipe_V_Body_R[];
extern unsigned char T_Pipe_H_Head_U[];
extern unsigned char T_Pipe_H_Head_D[];
extern unsigned char T_Pipe_H_Body_U[];
extern unsigned char T_Pipe_H_Body_D[];

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

const unsigned char *Airship_Ground_Palette[] = 
{
    T_null,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Q_Block,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,T_Brick,
    T_Alt_Block,T_Used_Block,T_Pipe_V_Head_L,T_Pipe_V_Head_R,T_Pipe_V_Body_L,T_Pipe_V_Body_R,T_Pipe_V_Head_L,T_Pipe_V_Head_R,T_Pipe_H_Head_U,T_Pipe_H_Head_D,T_Pipe_H_Body_U,T_Pipe_H_Body_D,T_Pipe_H_Head_D,T_Pipe_H_Head_U,T_Pipe_V_Head_L,T_Pipe_V_Head_R,
    T_Pipe_V_Head_L,T_Pipe_V_Head_R,T_Pipe_H_Head_U,T_Pipe_H_Head_D,T_Pipe_H_Head_D,T_Pipe_H_Head_U,T_Pipe_V_Head_L,T_Pipe_V_Head_R,T_Pipe_V_Head_L,T_Pipe_V_Head_R,T_Pipe_H_Head_U,T_Pipe_H_Head_D,T_Pipe_H_Head_D,T_Pipe_H_Head_U,
    T_Airship_Ground_0,T_Airship_Ground_1,T_Airship_Ground_2,T_Airship_Ground_3,T_Airship_Ground_4,T_Airship_Ground_5,T_Airship_Ground_6,T_Airship_Ground_7,
    T_Airship_Ground_8,T_Airship_Ground_9,T_Airship_Ground_10,T_Airship_Ground_11,T_Airship_Ground_12,T_Airship_Ground_13,T_Airship_Ground_14,T_Airship_Ground_15,
    T_Airship_Ground_16
};

const unsigned char *Airship_Background_Palette[] = 
{
    T_null,T_Grey_Light,T_Grey_Dark,T_Black,T_Coin,T_Water_Top,T_Grey_Light,T_Grey_Dark,T_End_Background,T_End_Block_UL,T_End_Block_UR,T_End_Block_DL,T_End_Block_DR,
};