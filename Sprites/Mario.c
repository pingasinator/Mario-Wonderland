#pragma bank 3

const unsigned char null[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
};

const unsigned char Mario_Small_Idle[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x01,0x01,
    0x06,0x06,
    0x09,0x08,
    0x13,0x13,
    
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0xF0,0xF0,
    0x28,0x08,
    0xFC,0x7C,
    0xFE,0xFE,

    0x1F,0x1E,
    0x3F,0x28,
    0x3F,0x2D,
    0x3F,0x23,
    0x1F,0x18,
    0x1F,0x1C,
    0x23,0x23,
    0x46,0x46,

    0x28,0x08,
    0x78,0x58,
    0xFC,0x04,
    0xFC,0xCC,
    0xF8,0xF8,
    0xF0,0x10,
    0xF8,0xF8,
    0x94,0x94,

    0x4F,0x49,
    0x5F,0x50,
    0x3F,0x30,
    0x3F,0x39,
    0x1F,0x1F,
    0x1F,0x18,
    0x1F,0x10,
    0x1F,0x1F,

    0xFE,0xFA,
    0xAE,0xAA,
    0xFC,0xFC,
    0xF8,0xF8,
    0xF0,0xF0,
    0xF0,0x90,
    0x68,0x48,
    0xF8,0xF8
};

const unsigned char Mario_Small_Move_0[] = 
{

    0x1F,0x1E,
    0x3F,0x28,
    0x3F,0x2D,
    0x3F,0x23,
    0x1F,0x18,
    0x1F,0x1C,
    0x27,0x27,
    0x4F,0x49,

    0x28,0x08,
    0x78,0x58,
    0xFC,0x04,
    0xFC,0xCC,
    0xF8,0xF8,
    0xF0,0x10,
    0xF8,0xF8,
    0x9C,0x94,

    0x7F,0x50,
    0x3F,0x30,
    0x1F,0x19,
    0x1F,0x1F,
    0x0F,0x0F,
    0x0F,0x08,
    0x07,0x04,
    0x03,0x03,

    0xFC,0xF4,
    0xA8,0xA8,
    0xF0,0xF0,
    0xE0,0xE0,
    0xC0,0xC0,
    0xC0,0x40,
    0xA0,0x20,
    0xE0,0xE0
};

const unsigned char Mario_Small_Move_1[] =
{
    0x1F,0x1E,
    0x3F,0x28,
    0x3F,0x2D,
    0x3F,0x23,
    0x1F,0x18,
    0x0F,0x0C,
    0x17,0x17,
    0x23,0x23,

    0x28,0x08,
    0x78,0x58,
    0xFC,0x04,
    0xFC,0xCC,
    0xF8,0xF8,
    0xF0,0x10,
    0xF0,0xF0,
    0x5E,0x5E,

    0x27,0x24,
    0x3F,0x28,
    0x1F,0x18,
    0x1F,0x1C,
    0x3F,0x2F,
    0x3F,0x23,
    0x1E,0x10,
    0x0F,0x0F,

    0xFE,0xFA,
    0xDE,0x52,
    0xFE,0x72,
    0xFE,0xE2,
    0xFE,0xE6,
    0x1C,0x1C,
    0x80,0x80,
    0x80,0x80
};

const unsigned char Mario_Small_Move_2[] =
{
    0x1F,0x1C,
    0x3F,0x28,
    0x3F,0x2D,
    0x3F,0x23,
    0x1F,0x18,
    0x0F,0x0C,
    0x13,0x13,
    0x23,0x22,

    0x24,0x04,
    0x74,0x54,
    0xFC,0x04,
    0xFC,0x8C,
    0xF8,0xF8,
    0xF0,0x10,
    0xF0,0xF0,
    0xCC,0x4C,

    0x37,0x24,
    0x7F,0x54,
    0x7F,0x4E,
    0x7F,0x4F,
    0x7F,0x4F,
    0x51,0x51,
    0x61,0x61,
    0x00,0x00,

    0xFE,0x3A,
    0xEE,0x2A,
    0xFC,0x7C,
    0xF8,0xF8,
    0xF8,0xF8,
    0xF8,0xC8,
    0xFC,0x04,
    0xFC,0xFC
};

const unsigned char Mario_Small_Jump[] = 
{
    0X00,0X00,
    0X00,0X00,
    0X00,0X00,
    0X00,0X00,
    0X01,0X01,
    0X06,0X06,
    0X09,0X08,
    0x13,0x13,

    0X00,0X00,
    0X00,0X00,
    0X00,0X00,
    0X1C,0X1C,
    0XFE,0XE2,
    0X5E,0X12,
    0XFE,0XFA,
    0xFC,0xFC,
    
    0x1F,0x1E,
    0x3F,0x28,
    0x3F,0x2D,
    0x3F,0x23,
    0x3F,0x38,
    0x47,0x44,
    0x9F,0x9F,
    0xFC,0xA4,

    0x2A,0x0A,
    0x7A,0x5A,
    0xFE,0x06,
    0xFC,0xCC,
    0xFC,0xFC,
    0xF8,0x18,
    0xF0,0xF0,
    0x96,0x96,

    0x7F,0x43,
    0xFF,0xC3,
    0xFF,0xA7,
    0xFF,0x9F,
    0xFF,0x9F,
    0xA0,0xA0,
    0xC0,0xC0,
    0x00,0x00,

    0xFA,0xFA,
    0x7E,0x72,
    0xFE,0xE2,
    0xFE,0xE2,
    0xFC,0xE4,
    0x18,0x18,
    0x00,0x00,
    0x00,0x00
};

const unsigned char Mario_Small_Fall[] = 
{

    0x28,0x08,
    0x78,0x58,
    0xFC,0x04,
    0xFC,0xCC,
    0xF8,0xF8,
    0xF0,0x10,
    0xF8,0xF8,
    0xFC,0xA4
};

const unsigned char Mario_Small_Slide[] = 
{
    0x3F,0x3C,
    0x3F,0x28,
    0x3F,0x2D,
    0x3F,0x23,
    0x7F,0x79,
    0xFF,0x9F,
    0xF7,0x94,
    0x7F,0x78,

    0x24,0x04,
    0x74,0x54,
    0xFC,0x04,
    0xFC,0xCC,
    0xF8,0xF8,
    0xF8,0x18,
    0xE4,0xE4,
    0xC2,0x42,

    0x3F,0x38,
    0x2F,0x2C,
    0x37,0x27,
    0x1F,0x11,
    0x0F,0x09,
    0x1F,0x17,
    0x2F,0x20,
    0x3F,0x3F,

    0xC6,0x42,
    0xFC,0x84,
    0xF8,0xF8,
    0xF8,0x78,
    0xF0,0xF0,
    0x80,0x80,
    0x80,0x80,
    0x80,0x80,

    0x1E,0x1E,
    0x13,0x13,
    0x21,0x21,
    0x23,0x21,
    0x4F,0x43,
    0xBC,0xBC,
    0xC0,0xC0,
    0x00,0x00
};

const unsigned char Mario_Small_Crounch[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x03,0x03,
    0x0C,0x0C,
    0x13,0x13,
    0x2F,0x25,
    0x3F,0x3C,

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0xC8,0xC8,
    0x78,0x38,
    0xF0,0xF0,
    0xF8,0x78,
    0xFC,0x44,

    0x5F,0x58,
    0xA7,0xA6,
    0xC3,0x81,
    0xFF,0xC3,
    0xFF,0xFF,
    0x7F,0x7D,
    0x3E,0x20,
    0x3F,0x3F,

    0xFC,0x64,
    0xF8,0x98,
    0xF8,0xF8,
    0x68,0x68,
    0xF0,0xF0,
    0xE0,0xA0,
    0xD0,0x90,
    0xF0,0xF0
};

const unsigned char Mario_Small_Front[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x03,0x03,
    0x0C,0x0C,
    0x17,0x10,
    0x2F,0x27,

    0x3F,0x3F,
    0x79,0x78,
    0x7B,0x52,
    0x7F,0x4C,
    0x3F,0x3C,
    0x3F,0x27,
    0x3F,0x38,
    0x4F,0x4F,

    0xB4,0xB4,
    0xFB,0xCB,
    0xFF,0x87,
    0xFF,0x8F,
    0x7F,0x7F,
    0x2F,0x23,
    0x5F,0x41,
    0x7F,0x7F
};

const unsigned char Mario_Dead[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x28,0x28,
    0x7C,0x54,
    0x7C,0x44,
    0xFF,0x83,
    0xFC,0x8C,

    0xF7,0xD0,
    0xAF,0xA7,
    0x9F,0x9F,
    0xB9,0xB8,
    0xBB,0xB2,
    0xBF,0xAC,
    0x5F,0x58,
    0x37,0x27,

    0x38,0x20,
    0x7F,0x70,
    0x9F,0x9F,
    0xEB,0x8B,
    0xFF,0x8F,
    0xFF,0x8F,
    0x7F,0x4F,
    0x30,0x30
};

const unsigned char Mario_Small_Swim_0[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x01,0x01,
    0x06,0x06,

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0xF0,0xF0,
    0x28,0x08,

    0x09,0x08,
    0x13,0x13,
    0x1F,0x1C,
    0x3F,0x28,
    0x3F,0x2D,
    0x3F,0x23,
    0x1F,0x19,
    0x0F,0x0C,

    0xFC,0x7C,
    0xFE,0xFE,
    0x25,0x08,
    0x78,0x58,
    0xFC,0x04,
    0xFC,0xCC,
    0xF8,0xF8,
    0xFC,0x1C,

    0x13,0x13,
    0x10,0x10,
    0x1C,0x1C,
    0x3F,0x2F,
    0x3F,0x2F,
    0x7F,0x4F,
    0xCF,0x8F,
    0xF7,0xF7,

    0xFE,0xEA,
    0x7F,0x45,
    0x7F,0x45,
    0xFE,0xFE,
    0x50,0x50,
    0xF0,0xF0,
    0xE0,0xE0,
    0x80,0x80
};

const unsigned char Mario_Small_Swim_1[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x01,0x01,
    0x06,0x06,
    0x09,0x08,
    0x13,0x13,

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0xF0,0xF0,
    0x28,0x08,
    0xFC,0x7C,
    0xFE,0xFE,

    0x1F,0x1C,
    0x3F,0x28,
    0x3F,0x2D,
    0x3F,0x23,
    0x3F,0x3D,
    0x7F,0x43,
    0x7C,0x44,
    0x3C,0x24,

    0x28,0x08,
    0x78,0x58,
    0xFC,0x04,
    0xFC,0xCC,
    0xF8,0xF8,
    0xF0,0x10,
    0xF0,0xF0,
    0xA8,0xA8,

    0x38,0x38,
    0x7F,0x4F,
    0xDF,0x9F,
    0xFF,0xFF,
    0x1F,0x17,
    0x3B,0x23,
    0x77,0x47,
    0x78,0x78,

    0xA8,0xA8,
    0xA8,0xA8,
    0x50,0x50,
    0xF0,0xF0,
    0xE0,0xE0,
    0xC0,0xC0,
    0x00,0x00,
    0x00,0x00
};

const unsigned char Mario_Great_Idle[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x01,0x01,
    0x06,0x06,
    0x08,0x08,

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0xE0,0xE0,
    0x10,0x10,
    0xE8,0x08,

    0x13,0x11,
    0x2F,0x23,
    0x3E,0x2C,
    0x7C,0x78,
    0xFC,0x98,
    0xFF,0x9C,
    0xFF,0x89,
    0x7F,0x63,

    0xFC,0xFC,
    0xFE,0xFE,
    0x4C,0x0C,
    0xE8,0xA8,
    0xE8,0xA8,
    0x84,0x04,
    0xFC,0x04,
    0xFC,0xFC,

    0x3F,0x30,
    0x3F,0x3C,
    0x4F,0x4F,
    0x87,0x84,
    0x8F,0x88,
    0x8F,0x88,
    0xE7,0x84,
    0x7F,0x43,

    0xF8,0xF8,
    0xF0,0x10,
    0xF0,0xF0,
    0xDC,0x5C,
    0xEE,0x2A,
    0xFE,0x3A,
    0xDE,0x5A,
    0x9C,0x9C,

    0x7F,0x7F,
    0x7F,0x7F,
    0x7F,0x7F,
    0x3F,0x3F,
    0x3F,0x3F,
    0x79,0x41,
    0x7E,0x40,
    0x7F,0x7F,

    0xF8,0xF8,
    0xF0,0xF0,
    0xF0,0xB0,
    0xE0,0x60,
    0xE0,0xE0,
    0x90,0x10,
    0xE8,0x88,
    0xF8,0xF8
};

const unsigned char Mario_Great_Move_0[] = 
{
    0x3F,0x3F,
    0x3F,0x3F,
    0x1F,0x1F,
    0x0F,0x0F,
    0x1F,0x13,
    0x1E,0x10,
    0x0F,0x08,
    0x07,0x07,

    0xF8,0xF8,
    0xF0,0xF0,
    0xE0,0xE0,
    0xE0,0xE0,
    0xC0,0xC0,
    0x40,0x40,
    0xA0,0x20,
    0xE0,0xE0
};

const unsigned char Mario_Great_Move_1[] = 
{
    
    0x3F,0x30,
    0x1F,0x1C,
    0x23,0x23,
    0x47,0x47,
    0x4F,0x48,
    0x5F,0x50,
    0x7F,0x50,
    0xFF,0xE4,

    0xF8,0xF8,
    0xF0,0x10,
    0xF6,0xF6,
    0x9F,0x19,
    0xCF,0x89,
    0xFF,0x7D,
    0xD6,0x56,
    0x94,0x94,

    0xFF,0xBF,
    0xFF,0xBF,
    0xFF,0xBF,
    0xDF,0x9F,
    0xD3,0x93,
    0xA3,0xA2,
    0xC3,0xC2,
    0x03,0x03,

    0xFC,0xFC,
    0xF8,0xF8,
    0xF8,0xF8,
    0xF0,0xF0,
    0xF0,0xF0,
    0xC8,0x08,
    0xF4,0x04,
    0xFC,0xFC
};

const unsigned char Mario_Great_Move_2[] = 
{

    0x1F,0x18,
    0x3F,0x3E,    
    0x47,0x47,
    0x8F,0x88,    
    0x9F,0x90,
    0x9F,0x90,
    0xDF,0x98,
    0x7F,0x4F,

    0xFC,0x7C,
    0xF8,0x08,    
    0xF0,0xF0,    
    0x90,0x90,    
    0xCC,0x4C,
    0xFF,0x7B,
    0xB5,0xB5,
    0x3B,0x39,    
    
    0x3F,0x3F,
    0x3F,0x3F,    
    0x3F,0x3F,
    0x7F,0x7F,    
    0x4F,0x7F,
    0x42,0x72,
    0x3D,0x21,
    0x1F,0x1F,

    0xFB,0xF9,
    0xFF,0xF9,    
    0xFF,0xF9,
    0x1F,0x13,    
    0x0E,0x0E,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00
};

const unsigned char Mario_Great_Jump[] = 
{

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x1C,0x1C,
    0xFE,0xE2,
    0x3F,0x21,
    0xDF,0x11,

    0x13,0x11,
    0x2F,0x23,
    0x3E,0x2C,
    0x7C,0x78,
    0xFC,0x98,
    0xFF,0x9C,
    0xFF,0x89,
    0x7F,0x63,

    0xFF,0xFB,
    0xFE,0xFE,
    0x4D,0x0D,
    0xE9,0xA9,
    0xE9,0xA9,
    0xE5,0x05,
    0xFF,0x05,
    0xFE,0xFE,


    0xFF,0xF9,
    0x0F,0x0C,
    0xE3,0xE3,
    0xF9,0x11,
    0xFD,0x09,
    0xFD,0x09,
    0xFF,0x1F,
    0xFF,0xFF,

    0xFE,0xFA,
    0xFC,0x14,
    0xF8,0xF8,
    0x18,0x18,
    0x88,0x88,
    0xFB,0xFB,
    0x35,0x35,
    0x3B,0x39,

    0xFF,0xBF,
    0xFF,0xBF,
    0xFF,0xBF,
    0xFC,0x9C,
    0xD0,0x90,
    0xA0,0xA0,
    0xC0,0xC0,
    0x00,0x00,

    0xFB,0xF9,
    0xFF,0xF9,
    0xFF,0xF9,
    0x1F,0x13,
    0x0E,0x0E,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,


    0x00,0x00,
    0x01,0x01,
    0x02,0x02,
    0x03,0x03,
    0x03,0x02,
    0x03,0x02,
    0x01,0x01,
    0x00,0x00
};

const unsigned char Mario_Great_Fall[] =
{
    0x1F,0x18,
    0x3F,0x3E,
    0x47,0x47,
    0x8F,0x88,
    0x9F,0x90,
    0x9F,0x90,
    0xDF,0x98,
    0x7F,0x4F
};

const unsigned char Mario_Great_Slide[] = 
{
    0x09,0x08,
    0x17,0x11,
    0x1F,0x16,
    0x3E,0x3C,
    0x3E,0x2C,
    0x7F,0x46,
    0x7F,0x48,
    0x3F,0x27,

    0xFC,0xFC,
    0xFE,0xFE,
    0x26,0x06,
    0x74,0x54,
    0x74,0x54,
    0xC2,0x02,
    0xFE,0x82,
    0xFE,0xFE,

    0x1F,0x18,
    0x7F,0x70,
    0xFF,0x90,
    0xFF,0x89,
    0xF7,0x97,
    0x73,0x73,
    0x1F,0x1D,
    0x3F,0x3B,

    0xFC,0xFC,
    0xDC,0x5C,
    0xC2,0xC2,
    0x85,0x81,
    0xFD,0x05,
    0xF9,0xF9,
    0xE3,0xE3,
    0xFE,0xFE,

    0x37,0x27,
    0x1D,0x11,
    0x0F,0x08,
    0x0F,0x0C,
    0x0F,0x0F,
    0x13,0x10,
    0x2F,0x20,
    0x3F,0x3F,

    0xFE,0xFE,
    0xFC,0xBC,
    0xF8,0xD8,
    0xE0,0xE0,
    0xC0,0xC0,
    0xC0,0x40,
    0xC0,0x40,
    0xC0,0xC0
};

const unsigned char Mario_Great_Crounch[] = 
{
    0x07,0x07,
    0x18,0x18,
    0x27,0x27,
    0x4F,0x4A,
    0x7F,0x78,
    0x7F,0x70,
    0xCF,0xCE,
    0x91,0x91,

    0xF2,0xF2,
    0x1E,0x0E,
    0xFC,0x9C,
    0xFE,0xFE,
    0xF9,0x39,
    0xFF,0x61,
    0xFF,0x7F,
    0xFE,0xBE,

    0xC1,0x80,
    0x63,0x41,
    0xFF,0xE3,
    0xFF,0xFF,
    0xFF,0xFF,
    0x7C,0x7C,
    0x3F,0x20,
    0x3F,0x3F,

    0xF8,0x88,
    0x74,0x74,
    0x34,0x34,
    0xFC,0xFC,
    0xF8,0xF8,
    0xC8,0xC8,
    0x74,0x64,
    0xFC,0xFC
};

const unsigned char Mario_Great_Front[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x07,0x07,
    0x18,0x18,
    0x23,0x20,
    0x4F,0x43,

    0x7F,0x6F,
    0x3F,0x3F,
    0x79,0x78,
    0xF3,0xA2,
    0xF3,0x92,
    0xFE,0x94,
    0x7F,0x7C,
    0x3F,0x2F,

    0xCF,0xCC,
    0x5F,0x58,
    0xBF,0xBF,
    0xF8,0xC8,
    0xFC,0x84,
    0xFF,0x87,
    0xFB,0xCB,
    0x73,0x73,

    0x3F,0x3F,
    0x3F,0x3F,
    0x3F,0x3F,
    0x1F,0x1F,
    0x1F,0x1F,
    0x2F,0x21,
    0x5F,0x41,
    0x7F,0x7F,
};

const unsigned char Mario_Great_Swim_0[] = 
{
    0x3F,0x30,
    0x1F,0x1E,
    0x23,0x23,
    0x40,0x40,
    0x60,0x40,
    0x7C,0x60,
    0xFF,0xFC,
    0xFF,0x7F,

    0xF8,0xF8,
    0xF0,0x10,
    0xFC,0xFC,
    0xFE,0xDA,
    0xFF,0x85,
    0xFF,0x85,
    0xFE,0x0E,
    0xF0,0xF0,

    0x7E,0x7E,
    0x7F,0x7F,
    0xFF,0xFF,
    0x3F,0x3F,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,

    0x50,0x50,
    0xE0,0xE0,
    0xC0,0xC0,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x01,0x01,
    0x03,0x02,

    0x03,0x02,
    0x07,0x04,
    0x0C,0x08,
    0x0F,0x0F,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
};

const unsigned char Mario_Great_Swim_1[] = 
{
    0x1F,0x18,
    0x7F,0x7E,
    0xFD,0x85,
    0xFC,0x84,
    0x7C,0x44,
    0x7F,0x69,
    0xFF,0xFF,
    0xFF,0xFF,

    0xFC,0x7C,
    0xF8,0x08,
    0xF0,0xF0,
    0xB0,0xB0,
    0xA8,0xA8,
    0x48,0x48,
    0xF8,0xF8,
    0xF8,0x28,

    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0x7F,
    0x9E,0x1E,
    0x60,0x60,
    0x80,0x80,
    0x00,0x00,

    0x19,0x11,
    0x1F,0x1F,
    0x00,0x00,
    0x01,0x01,
    0x01,0x01,
    0x03,0x02,
    0x03,0x03,
    0x00,0x00,

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x03,0x03,
    0x04,0x04,
    0x09,0x08,
    
};

const unsigned char Mario_Fire[] = 
{
    0x00,0x00,
    0x0E,0x0E,
    0x09,0x09,
    0x08,0x08,
    0x04,0x04,
    0x02,0x02,
    0x07,0x07,
    0x08,0x08,

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x80,0x80,
    0x40,0x40,
    0xE0,0xE0,
    0xB0,0xB0,
    0xE8,0xE8,

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x80,0x80,
    0x5C,0x5C,
    0xFE,0xE2,
    0xBF,0xB1,
    0xEF,0xE1
};

const unsigned char Mario_WorldMap_Small[] = 
{
    0x01,0x01,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,

    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00
};