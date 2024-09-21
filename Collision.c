#include "include\collision.h"
#include "include\Sprite.h"


int TileMapCollisionSide(Collision *A,Vector2 *velocity,int side)
{
    unsigned char* Tilemap = Get_Tilemap();
    Vector2 pos;
    pos.x = A->position.x + A->pixeloffset.x;
    pos.y = A->position.y + A->pixeloffset.y;
    Vector2 overload = {.x=A->pixelsize.x - (A->pixelsize.x / 16) * 16,.y=A->pixelsize.y - (A->pixelsize.y / 16) * 16};
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
            if(Tilemap[boundOut] > 0 && Tilemap[boundIn] > 0)
            {
                return 1;
            }else if(Tilemap[boundOut] > 0)
            {
                return 2;
            }
            i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
        }

        break;

        case 1:
        while(i <= A->pixelsize.x)
        {
            boundIn = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y) / 16) * 128;
            boundOut = (pos.x + i) / 16 + ((A->position.y + A->pixeloffset.y - 1) / 16) * 128;
            if(Tilemap[boundOut] > 0)
            {
                return 1;
            }
            i += i + 16 <= A->pixelsize.x ? 16 : i == A->pixelsize.x ? 1 : A->pixelsize.x - i;
        }

        break;

        case 2:
        while(i <= A->pixelsize.y)
        {
            boundIn = (A->position.x + A->pixeloffset.x) / 16 + ((pos.y + i) / 16) * 128;
            boundOut = (A->position.x+ A->pixeloffset.x - 1) / 16 + ((pos.y + i) / 16) * 128;
            if(Tilemap[boundOut] > 0)
            {
                
                return 1;
            }
            i += i + 16 <= A->pixelsize.y ? 16 : i == A->pixelsize.y ? 1 : A->pixelsize.y - i;
        }

        break;

        case 3:
        while(i <= A->pixelsize.y)
        {
            boundIn = (A->position.x + A->pixeloffset.x + A->pixelsize.x) / 16 + ((pos.y + i) / 16) * 128;
            boundOut = (A->position.x+ A->pixeloffset.x + A->pixelsize.x + 1) / 16 + ((pos.y + i) / 16) * 128;
            if(Tilemap[boundOut] > 0)
            {
                return 1;
            }
            i += i + 16 <= A->pixelsize.y ? 16 : i == A->pixelsize.y ? 1 : A->pixelsize.y - i;
        }
        break;
    }
    return 0;
}

int OnCollision(Collision A,Collision B)
{
    Vector2 A_minpos = {.x=A.position.x + A.pixeloffset.x,.y=A.position.y + A.pixeloffset.y};
    Vector2 A_maxpos = {.x=A_minpos.x + A.pixelsize.x,.y=A_minpos.y + A.pixelsize.y};
    Vector2 B_minpos = {.x=B.position.x + B.pixeloffset.x,.y=B.position.y + B.pixeloffset.y};
    Vector2 B_maxpos = {.x=B_minpos.x + B.pixelsize.x,.y=B_minpos.y + B.pixelsize.y};

    int H = (A_minpos.x >= B_minpos.x && A_minpos.x <= B_maxpos.x) || (A_maxpos.x <= B_maxpos.x && A_maxpos.x >= B_minpos.x) || (A_minpos.x <= B_minpos.x && A_maxpos.x >= B_maxpos.x )? 1 : 0;
    int V = (A_minpos.y >= B_minpos.y && A_minpos.y <= B_maxpos.y) || (A_maxpos.y <= B_maxpos.y && A_maxpos.y >= B_minpos.y) || (A_minpos.y <= B_minpos.y && A_maxpos.y >= B_maxpos.y )? 1 : 0;
    
    return V == 1 && H == 1? 1 : 0;
}

int OnCollisionSide(Collision A,Collision B,Vector2 *A_velocity,Vector2 *B_velocity, int side)
{
    Vector2 A_minpos = {.x=A.position.x + A.pixeloffset.x - A_velocity->x,.y=A.position.y + A.pixeloffset.y - A_velocity->y};
    Vector2 A_maxpos = {.x=A_minpos.x + A.pixelsize.x,.y=A_minpos.y + A.pixelsize.y };
    Vector2 B_minpos = {.x=B.position.x + B.pixeloffset.x - B_velocity->x,.y=B.position.y + B.pixeloffset.y - B_velocity->y};
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

int Raycast(Vector2 point,Vector2 dir,Vector2 velocity,int pixelSize)
{
    dir.x = Clamp(dir.x,-1,1);
    dir.y = Clamp(dir.y,-1,1);
    int overload = pixelSize - (pixelSize / 16) * 16;
    for(int i = 0; i < pixelSize / 16 ;i++)
    {
        if(Get_Tilemap()[(point.x + dir.x * i * 16 - velocity.x) / 16 + (point.y + dir.y * i * 16 - velocity.y) / 16 * 128] > 0)
        {
            return 1;
        }
    }

    if(overload > 0)
    {
        if(Get_Tilemap()[(point.x + dir.x * pixelSize - velocity.x) / 16 + (point.y + dir.y * pixelSize - velocity.y) / 16 * 128] > 0)
        {
            return 1;
        }
    }

    return 0;
}