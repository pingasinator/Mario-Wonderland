#include "..\include\collision.h"
#include "..\include\Sprite.h"

#include <gb\gb.h>

#pragma bank 13

int TileMapCollisionSide(Collision *A,int side) BANKED
{
    unsigned char* Tilemap = Get_Tilemap();
    Vector2 pos;
    pos.x = A->position.x + A->pixeloffset.x;
    pos.y = A->position.y + A->pixeloffset.y;
    int boundOut = 0;
    int boundIn = 0;
    int i = 0;
 

    switch(side)
    {
        case 0:
        while(i <= A->pixelsize.x)
        {
            boundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y) / 16) * 128;
            boundOut = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y + 1) / 16) * 128;
            if(Tilemap[boundOut] >= 0x80 || Tilemap[boundIn] >= 0x80)
            {
                return (Tilemap[boundOut] >= 0x80) + (Tilemap[boundIn] >= 0x80) * 2;
            }
            i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
        }

        break;

        case 1:
        while(i <= A->pixelsize.x)
        {
            boundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y) / 16) * 128;
            boundOut = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y - 1) / 16) * 128;
            if(Tilemap[boundOut] >= 0x80 || Tilemap[boundIn] >= 0x80)
            {
                return (Tilemap[boundOut] >= 0x80) + (Tilemap[boundIn] >= 0x80) * 2;
            }
            i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
        }

        break;

        case 2:
        while(i <= A->pixelsize.y)
        {
            boundIn = (A->position.x + A->pixeloffset.x) / 16 + ((pos.y + i) / 16) * 128;
            boundOut = (A->position.x+ A->pixeloffset.x - 1) / 16 + ((pos.y + i) / 16) * 128;
            if(Tilemap[boundOut] >= 0x80 || Tilemap[boundIn] >= 0x80)
            {
                return (Tilemap[boundOut] >= 0x80) + (Tilemap[boundIn] >= 0x80) * 2;
            }
            i += i + 16 <= A->pixelsize.y ? 16 : i == A->pixelsize.y ? 1 : A->pixelsize.y - i;
        }

        break;

        case 3:
        while(i <= A->pixelsize.y)
        {
            boundIn = (A->position.x + A->pixeloffset.x + A->pixelsize.x) / 16 + ((pos.y + i) / 16) * 128;
            boundOut = (A->position.x+ A->pixeloffset.x + A->pixelsize.x + 1) / 16 + ((pos.y + i) / 16) * 128;
            if(Tilemap[boundOut] >= 0x80 || Tilemap[boundIn] >= 0x80)
            {
                return (Tilemap[boundOut] >= 0x80) + (Tilemap[boundIn] >= 0x80) * 2;
            }
            i += i + 16 <= A->pixelsize.y ? 16 : i == A->pixelsize.y ? 1 : A->pixelsize.y - i;
        }
        break;
    }
    return 0;
}

int OnCollision(Collision A,Collision B) BANKED
{
    Vector2 A_minpos = {.x=A.position.x + A.pixeloffset.x,.y=A.position.y + A.pixeloffset.y};
    Vector2 A_maxpos = {.x=A_minpos.x + A.pixelsize.x,.y=A_minpos.y + A.pixelsize.y};
    Vector2 B_minpos = {.x=B.position.x + B.pixeloffset.x,.y=B.position.y + B.pixeloffset.y};
    Vector2 B_maxpos = {.x=B_minpos.x + B.pixelsize.x,.y=B_minpos.y + B.pixelsize.y};

    int H = (A_minpos.x >= B_minpos.x && A_minpos.x <= B_maxpos.x) || (A_maxpos.x <= B_maxpos.x && A_maxpos.x >= B_minpos.x) || (A_minpos.x <= B_minpos.x && A_maxpos.x >= B_maxpos.x )? 1 : 0;
    int V = (A_minpos.y >= B_minpos.y && A_minpos.y <= B_maxpos.y) || (A_maxpos.y <= B_maxpos.y && A_maxpos.y >= B_minpos.y) || (A_minpos.y <= B_minpos.y && A_maxpos.y >= B_maxpos.y )? 1 : 0;
    
    return V == 1 && H == 1? 1 : 0;
}

int OnCollisionSide(Collision A,Collision B, int side) BANKED
{
    Vector2 A_minpos = {.x=A.position.x + A.pixeloffset.x,.y=A.position.y + A.pixeloffset.y};
    Vector2 A_maxpos = {.x=A_minpos.x + A.pixelsize.x,.y=A_minpos.y + A.pixelsize.y };
    Vector2 B_minpos = {.x=B.position.x + B.pixeloffset.x,.y=B.position.y + B.pixeloffset.y};
    Vector2 B_maxpos = {.x=B_minpos.x + B.pixelsize.x,.y=B_minpos.y + B.pixelsize.y};


    switch(side)
    {
        case 0:

        break;

        case 1:
        int H = ((A_minpos.x >= B_minpos.x && A_minpos.x <= B_maxpos.x) || (A_maxpos.x <= B_maxpos.x && A_maxpos.x >= B_minpos.x) || (A_minpos.x >= B_minpos.x && A_maxpos.x <= B_maxpos.x));
        int V = ((A_minpos.y >= B_minpos.y && A_minpos.y <= B_maxpos.y));
        return H && V;
        break;
    }

    return 0;
}

int Raycast(Vector2 point,Vector2 dir,int pixelSize) BANKED
{
    dir.x = Clamp(dir.x,-1,1);
    dir.y = Clamp(dir.y,-1,1);
    unsigned char *Tilemap = Get_Tilemap();
    int i=0;
    while(i <= pixelSize)
    {
        if(Tilemap[(point.x + dir.x * pixelSize) / 16 + ((point.y + dir.y * pixelSize) / 16) * 128]  >= 0x80)
        {
            return Tilemap[(point.x + dir.x * pixelSize) / 16 + ((point.y + dir.y * pixelSize) / 16) * 128] >= 0x80;
        }
        i += i + 16 <= pixelSize ? 16 : i == pixelSize ? 1 : pixelSize - i;
    }

    return 0;
}

void TilemapCollisionPhysics(Collision *A,Vector2* Velocity) BANKED
{
    unsigned char *Tilemap = Get_Tilemap();
    Vector2 pos;
    pos.x = A->position.x + A->pixeloffset.x;
    pos.y = A->position.y + A->pixeloffset.y;

    int i = 0;
    while(i <= A->pixelsize.x)
    {
        int MinboundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y) / 16) * 128;
        int MaxboundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y) / 16) * 128;
        if(Tilemap[MinboundIn] >= 0x80 && Tilemap[(pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y - 8) / 16) * 128] < 0x80)
        {   
            Velocity->y = Velocity->y > 0 ? 0 : Velocity->y;
            for(int j = 8; j > 0;j--)
            {
                if(Tilemap[(pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y - j) / 16) * 128] >= 0x80)
                {
                    A->position.y -= j;
                    break;
                }
            }
        }

        if(Tilemap[MaxboundIn] >= 0x80 && Tilemap[(pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + 8) / 16) * 128] < 0x80)
        {   
            Velocity->y = Velocity->y < 0 ? 0 : Velocity->y;
            for(int j = 8; j > 0;j--)
            {
                if(Tilemap[(pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y + j) / 16) * 128] >= 0x80)
                {
                    A->position.y += j;
                    break;
                }
            }
        }
        i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
    }

    pos.y = A->position.y + A->pixeloffset.y;

    while(i < A->pixelsize.y)
    {
        int MinboundIn = (A->position.x + A->pixeloffset.x) / 16 + ((pos.y + i) / 16) * 128;
        int MaxboundIn = (A->position.x + A->pixeloffset.x + A->pixelsize.x) / 16 + ((pos.y + i) / 16) * 128;

        if(Tilemap[MinboundIn] >=0x80 && Tilemap[(A->position.x + A->pixeloffset.x + 8) / 16 + ((pos.y + i) / 16) * 128] < 0x80)
        {
            Velocity->x = Velocity->x < 0 ? 0 : Velocity->x;
            for(int j = 8; j > 0;j--)
            {
                if(Tilemap[(A->position.x + A->pixeloffset.x + j) / 16 + ((pos.y + i) / 16) * 128] >= 0x80)
                {
                    A->position.x += j;
                    break;
                }
            }
        }

        if(Tilemap[MaxboundIn] >= 0x80 && Tilemap[(A->position.x + A->pixeloffset.x + A->pixelsize.x- 8) / 16 + ((pos.y + i) / 16) * 128] < 0x80)
        {
            Velocity->x = Velocity->x > 0 ? 0 : Velocity->x;
            for(int j = 8; j > 0;j--)
            {
                if(Tilemap[(A->position.x + A->pixeloffset.x + A->pixelsize.x - j) / 16 + ((pos.y + i) / 16) * 128] >= 0x80)
                {
                    A->position.x -= j;
                    break;
                }
            }
        }
        i += i + 16 <= A->pixelsize.y ? 16 : A->pixelsize.y - i;
    }
}

void TilemapCollisionPhysicsSide(Collision *A,Vector2* Velocity,int side) BANKED
{
    unsigned char *Tilemap = Get_Tilemap();
    Vector2 pos;
    pos.x = A->position.x + A->pixeloffset.x;
    pos.y = A->position.y + A->pixeloffset.y;

    switch (side)
    {
        case 0:
        int i = 0;
        while(i <= A->pixelsize.x)
        {
            int MinboundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y) / 16) * 128;
            if(Tilemap[MinboundIn] > 0x80)
            {
                Velocity->y = (Tilemap[MinboundIn] > 0x80) && Velocity->y > 0 ? 0 : Velocity->y;
                while(Tilemap[MinboundIn] > 0x80)
                {
                    A->position.y += Tilemap[MinboundIn] > 0x80 ? -1 : 0;
                    pos.x = A->position.x + A->pixeloffset.x;
                    MinboundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y) / 16) * 128;
                }
            }
            i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
        }
        break;
    
    }
}