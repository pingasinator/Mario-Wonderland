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
            if(Tilemap[boundOut] > 1 || Tilemap[boundIn] > 1)
            {
                return (Tilemap[boundOut] > 1) + (Tilemap[boundIn] > 1) * 2;
            }
            i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
        }

        break;

        case 1:
        while(i <= A->pixelsize.x)
        {
            boundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y) / 16) * 128;
            boundOut = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y - 1) / 16) * 128;
            if(Tilemap[boundOut] > 1 || Tilemap[boundIn] > 1)
            {
                return (Tilemap[boundOut] > 1) + (Tilemap[boundIn] > 1) * 2;
            }
            i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
        }

        break;

        case 2:
        while(i <= A->pixelsize.y)
        {
            boundIn = (A->position.x + A->pixeloffset.x) / 16 + ((pos.y + i) / 16) * 128;
            boundOut = (A->position.x+ A->pixeloffset.x - 1) / 16 + ((pos.y + i) / 16) * 128;
            if(Tilemap[boundOut] > 1 || Tilemap[boundIn] > 1)
            {
                return (Tilemap[boundOut] > 1) + (Tilemap[boundIn] > 1) * 2;
            }
            i += i + 16 <= A->pixelsize.y ? 16 : i == A->pixelsize.y ? 1 : A->pixelsize.y - i;
        }

        break;

        case 3:
        while(i <= A->pixelsize.y)
        {
            boundIn = (A->position.x + A->pixeloffset.x + A->pixelsize.x) / 16 + ((pos.y + i) / 16) * 128;
            boundOut = (A->position.x+ A->pixeloffset.x + A->pixelsize.x + 1) / 16 + ((pos.y + i) / 16) * 128;
            if(Tilemap[boundOut] > 1 || Tilemap[boundIn] > 1)
            {
                return (Tilemap[boundOut] > 1) + (Tilemap[boundIn] > 1) * 2;
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
    char *Tilemap = Get_Tilemap();
    int i=0;
    while(i <= pixelSize)
    {
        if(Tilemap[(point.x + dir.x * pixelSize) / 16 + ((point.y + dir.y * pixelSize) / 16) * 128]  > 1)
        {
            return Tilemap[(point.x + dir.x * pixelSize) / 16 + ((point.y + dir.y * pixelSize) / 16) * 128] > 1;
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
        if(Tilemap[MinboundIn] > 1  || Tilemap[MaxboundIn] > 1)
        {            
            Velocity->y = (Tilemap[MinboundIn] > 1 && Tilemap[MaxboundIn] < 1) && Velocity->y > 0 ? 0 : (Tilemap[MaxboundIn] > 1 && Tilemap[MinboundIn] < 1) && Velocity->y < 0 ? 0 : Velocity->y;
            while((Tilemap[MinboundIn] > 1 && Tilemap[MaxboundIn] < 1) || (Tilemap[MaxboundIn] > 1 && Tilemap[MinboundIn] < 1))
            {
                A->position.y += Tilemap[MinboundIn] > 1 ? -1 : Tilemap[MaxboundIn] > 1 ? 1 : 0;
                pos.x = A->position.x + A->pixeloffset.x;
                MinboundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y) / 16) * 128;
                MaxboundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y) / 16) * 128;
            }
        }
        i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
    }

    pos.x = A->position.x + A->pixeloffset.x;
    pos.y = A->position.y + A->pixeloffset.y;

    while(i <= A->pixelsize.y)
    {
        int MinboundIn = (A->position.x + A->pixeloffset.x) / 16 + ((pos.y + i) / 16) * 128;
        int MaxboundIn = (A->position.x + A->pixeloffset.x + A->pixelsize.x) / 16 + ((pos.y + i) / 16) * 128;
        if(Tilemap[MinboundIn] > 1  || Tilemap[MaxboundIn] > 1)
        {
            while((Tilemap[MinboundIn] > 1 && Tilemap[MaxboundIn] < 1) || (Tilemap[MaxboundIn] > 1 && Tilemap[MinboundIn] < 1))
            {
                A->position.x += Tilemap[MinboundIn] > 1 ? -1 : Tilemap[MaxboundIn] > 1 ? 1 : 0;
                pos.y = A->position.y + A->pixeloffset.y;
                Velocity->x = Tilemap[MinboundIn] > 1 && Velocity->x < 0 ? 0 : Tilemap[MaxboundIn] > 1 && Velocity->x > 0 ? 0 : Tilemap[MinboundIn] > 1  && Tilemap[MaxboundIn] > 1 ? 0 : Velocity->x;
                MinboundIn = (A->position.x + A->pixeloffset.x + A->pixelsize.x) / 16 + ((pos.y + i) / 16) * 128;
                MaxboundIn = (A->position.x + A->pixeloffset.x) / 16 + ((pos.y + i) / 16) * 128;
            }
        }
        i += i + 16 <= A->pixelsize.y ? 16 : i == A->pixelsize.y ? 1 : A->pixelsize.y - i;
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
            if(Tilemap[MinboundIn] > 1)
            {
                Velocity->y = (Tilemap[MinboundIn] > 1) && Velocity->y > 0 ? 0 : Velocity->y;
                while(Tilemap[MinboundIn] > 1 )
                {
                    A->position.y += Tilemap[MinboundIn] > 1 ? -1 : 0;
                    pos.x = A->position.x + A->pixeloffset.x;
                    MinboundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y + A->pixelsize.y) / 16) * 128;
                }
            }
            i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
        }
        break;
    
    }
}