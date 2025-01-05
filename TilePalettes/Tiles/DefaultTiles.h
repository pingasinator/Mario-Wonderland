#ifndef DefaultTiles_H
#define DefaultTiles_H

//The Hexa values are the emplacement in the Vram

//{Top_Left, Top_Right, Bottom_Left, Bottom_Right}

unsigned char T_null[4] = {0x00,0x00,0x00,0x00};

unsigned char T_Brick[4] = {0x01,0x02,0x03,0x04};

unsigned char T_Used_Block[4] = {0x05,0x06,0x07,0x08};

unsigned char T_Alt_Block[4] = {0x09,0x0A,0x0B,0x0C};

unsigned char T_Q_Block[4] = {0x0D,0x0E,0x0F,0X10};

unsigned char T_Coin[4] = {0x11,0x12,0x13,0x14};

unsigned char T_Pipe_V_UL[4] = {0x1E,0x1F,0x21,0x00};

unsigned char T_Pipe_V_UR[4] = {0x1F,0x20,0x00,0x22};

unsigned char T_Pipe_V_ML[4] = {0x21,0x00,0x21,0x00};

unsigned char T_Pipe_V_MR[4] = {0x00,0x22,0x00,0x22};

unsigned char T_Pipe_V_DL[4] = {0x21,0x00,0x1E,0x1F};

unsigned char T_Pipe_V_DR[4] = {0x00,0x22,0X1F,0x20};

unsigned char T_Pipe_H_UL[4] = {0x19,0x1A,0x1B,0x00};

unsigned char T_Pipe_H_DL[4] = {0x1B,0x00,0x1C,0x1D};

unsigned char T_Pipe_H_MD[4] = {0x00,0x00,0x1D,0x1D};

unsigned char T_Pipe_H_MU[4] = {0x1A,0x1A,0x00,0x00};

unsigned char T_Pipe_H_UR[4] = {0x1A,0x19,0x00,0x1B};

unsigned char T_Pipe_H_DR[4] = { 0x00,0x1B,0x1D,0x1C};

unsigned char T_Water_Top[4] = {0X23,0X24,0x7D,0x7D};

unsigned char T_Water[4] = {0x7D,0x7D,0x7D,0x7D};

unsigned char T_Lava_Top[4] = {0X25,0X26,0x7E,0x7E};

unsigned char T_Lava[4] = {0x7E,0x7E,0x7E,0x7E};

unsigned char T_Cloud[4] = {0x15,0x16,0x17,0x18};

unsigned char T_End_Background[4] = {0x27,0x7F,0x28,0x7F};

unsigned char T_End_Block_UL[4] = {0x29,0x2A,0x2C,0x7F};

unsigned char T_End_Block_UR[4] = {0x2A,0x2B,0x7F,0x2D};

unsigned char T_End_Block_DL[4] = {0x2C,0x7F,0x2E,0x2F};

unsigned char T_End_Block_DR[4] = {0x7F,0x2D,0x2F,0x30};

unsigned char T_Black[4] = {0x7F,0x7F,0x7F,0x7F};

unsigned char T_Overworld_Ground_0[] = {37,31,33,45};

unsigned char T_Overworld_Ground_1[] = {32,38,46,34};

unsigned char T_Overworld_Ground_2[] = {33,47,39,35};

unsigned char T_Overworld_Ground_3[] = {48,34,35,40};

unsigned char T_Overworld_Ground_4[] = {33,45,33,0};

unsigned char T_Overworld_Ground_5[] = {46,34,48,34};

unsigned char T_Overworld_Ground_6[] = {37,38,33,34};

unsigned char T_Overworld_Ground_7[] = {33,34,39,40};

unsigned char T_Overworld_Ground_8[] = {33,34,33,34};

unsigned char T_Overworld_Ground_9[] = {45,46,35,36};

unsigned char T_Overworld_Ground_10[] = {0x31,0x32,0x3F,0x40};

unsigned char T_Overworld_Ground_11[] = {0x31,0x32,0x3F,0x40};

unsigned char T_Overworld_Ground_12[] = {0x31,0x32,0x3F,0x40};

unsigned char T_Overworld_Ground_13[] = {0x3F,0x40,0x41,0x42};

unsigned char T_Overworld_Ground_14[] = {0x31,0x32,0x3F,0x40};

unsigned char T_Overworld_Ground_15[] = {0x31,0x32,0x3F,0x40};

unsigned char T_Overworld_Ground_16[] = {0x3F,0x40,0x3E,0x42};

unsigned char T_Overworld_background_Bush[] = {0,0,0,0};

#endif