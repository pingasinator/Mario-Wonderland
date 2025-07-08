#include "..\include\collision.h"
#include "..\include\Sprite.h"
#include "..\include\Level.h"
#include "..\include\Tile.h"

#include <gb\gb.h>

extern Level currentLevel;
extern unsigned char Tilemap[];

#pragma bank 13

int TileMapCollisionSide(Collision *A,int side) BANKED
{
    Vector2 pos;
    pos.x = A->position.x + A->pixeloffset.x;
    pos.y = A->position.y + A->pixeloffset.y;
    int boundOut = 0;
    int boundIn = 0;
 
 

    switch(side)
    {
        case 0:
        for(int i = A->pixelsize.x; i > 0; i -= 8)
        {
            if(Get_Tile(pos.x + i,pos.y + A->pixelsize.y) >= 0x80 || Get_Tile(pos.x - i,pos.y + A->pixelsize.y) >= 0x80)
            {
                return 1;
            }
        }

        break;

        case 1:
        for(int i = A->pixelsize.x; i > 0; i -= 8)
        {
            if(Get_Tile(pos.x + i,pos.y - A->pixelsize.y) >= 0x80 || Get_Tile(pos.x - i,pos.y - A->pixelsize.y) >= 0x80)
            {
                return 1;
            }
        }

        break;

        case 2:
        for(int i = A->pixelsize.y; i > 0; i -= 8)
        {
            if(Get_Tile(pos.x - A->pixelsize.x,pos.y + i) >= 0x80 || Get_Tile(pos.x - A->pixelsize.x,pos.y - i) >= 0x80)
            {
                return 1;
            }
        }

        break;

        case 3:
        for(int i = A->pixelsize.y; i > 0; i -= 8)
        {
            if(Get_Tile(pos.x + A->pixelsize.x,pos.y + i) >= 0x80 || Get_Tile(pos.x + A->pixelsize.x,pos.y - i) >= 0x80)
            {
                return 1;
            }
        }
        break;
    }
    
    return 0;
}

int OnCollision(Collision A,Collision B) BANKED
{
    Vector2 A_minpos = {.x=A.position.x + A.pixeloffset.x - A.pixelsize.x,.y=A.position.y + A.pixeloffset.y - A.pixelsize.y};
    Vector2 A_maxpos = {.x=A.position.x + A.pixeloffset.x + A.pixelsize.x,.y=A.position.y + A.pixeloffset.y + A.pixelsize.y};
    Vector2 B_minpos = {.x=B.position.x + B.pixeloffset.x - B.pixelsize.x,.y=B.position.y + B.pixeloffset.y - B.pixelsize.y};
    Vector2 B_maxpos = {.x=B.position.x + B.pixeloffset.x + B.pixelsize.x,.y=B.position.y + B.pixeloffset.y + B.pixelsize.y};
    
    return ((A_minpos.y >= B_minpos.y && A_minpos.y <= B_maxpos.y) || (A_maxpos.y <= B_maxpos.y && A_maxpos.y >= B_minpos.y) || (A_minpos.y <= B_minpos.y && A_maxpos.y >= B_maxpos.y )) && ((A_minpos.x >= B_minpos.x && A_minpos.x <= B_maxpos.x) || (A_maxpos.x <= B_maxpos.x && A_maxpos.x >= B_minpos.x) || (A_minpos.x <= B_minpos.x && A_maxpos.x >= B_maxpos.x ));
}

int OnCollisionSide(Collision A,Collision B, int side) BANKED
{
    Vector2 A_minpos = {.x=A.position.x + A.pixeloffset.x - A.pixelsize.x,.y=A.position.y + A.pixeloffset.y - A.pixelsize.y};
    Vector2 A_maxpos = {.x=A.position.x + A.pixeloffset.x + A.pixelsize.x,.y=A.position.y + A.pixeloffset.y + A.pixelsize.y};
    Vector2 B_minpos = {.x=B.position.x + B.pixeloffset.x - B.pixelsize.x,.y=B.position.y + B.pixeloffset.y - B.pixelsize.y};
    Vector2 B_maxpos = {.x=B.position.x + B.pixeloffset.x + B.pixelsize.x,.y=B.position.y + B.pixeloffset.y + B.pixelsize.y};
    int H;
    int V;
    switch(side)
    {
        case 0:

        break;

        case 1:
        H = ((A_minpos.x >= B_minpos.x && A_minpos.x <= B_maxpos.x) || (A_maxpos.x <= B_maxpos.x && A_maxpos.x >= B_minpos.x) || (A_minpos.x >= B_minpos.x && A_maxpos.x <= B_maxpos.x));
        V = ((A_minpos.y >= B_minpos.y && A_minpos.y <= B_maxpos.y));
        return H && V;
        break;

        case 2:
        H = ((A_minpos.x >= B_minpos.x && A_minpos.x <= B_maxpos.x));
        V = ((A_minpos.y >= B_minpos.y && A_minpos.y <= B_maxpos.y) || (A_maxpos.y <= B_maxpos.y && A_maxpos.y >= B_minpos.y) || (A_minpos.y >= B_minpos.y && A_maxpos.y <= B_maxpos.y));
        return H && V;
        break; 

        case 3:
        H = (A_maxpos.x <= B_maxpos.x && A_maxpos.x >= B_minpos.x);
        V = ((A_minpos.y >= B_minpos.y && A_minpos.y <= B_maxpos.y) || (A_maxpos.y <= B_maxpos.y && A_maxpos.y >= B_minpos.y) || (A_minpos.y >= B_minpos.y && A_maxpos.y <= B_maxpos.y));
        return H && V;
        break;
    }

    return 0;
}

int Raycast(Vector2 point,Vector2 dir,int pixelSize) BANKED
{
    dir.x = Clamp(dir.x,-1,1);
    dir.y = Clamp(dir.y,-1,1);
    for(int i = pixelSize; i >= 0; i -= 8)
    {
        if(Get_Tile(point.x + dir.x * i,point.y + dir.y * pixelSize) >= 0x80)
        {
            return 1;
        }
    }

    return 0;
}

void TilemapCollisionPhysics(Collision *A,Vector2* Velocity) BANKED
{

    Vector2 pos;
    pos.x = A->position.x + A->pixeloffset.x;
    pos.y = A->position.y + A->pixeloffset.y;

    int i = 0;

    for(int i = A->pixelsize.x - 1;i >= 0 ;i-= 8)
    {
        if(pos.y + A->pixelsize.y > 0 && pos.y + A->pixelsize.y < currentLevel.Width * 16)
        {
            if((Get_Tile(pos.x + i,pos.y + A->pixelsize.y) >= 0x80 && Get_Tile(pos.x + i,pos.y + A->pixelsize.y - 8) < 0x80) || (Get_Tile(pos.x - i,pos.y + A->pixelsize.y) >= 0x80 && Get_Tile(pos.x - i,pos.y + A->pixelsize.y - 8) < 0x80))
            {
                
                for(int j = 0; j < 9;j++)
                {
                    if((Get_Tile(pos.x + i,pos.y + A->pixelsize.y) >= 0x80 && Get_Tile(pos.x + i,pos.y + A->pixelsize.y - j) < 0x80) || (Get_Tile(pos.x - i,pos.y + A->pixelsize.y) >= 0x80 && Get_Tile(pos.x - i,pos.y + A->pixelsize.y - j) < 0x80))
                    {
                        Velocity->y = Velocity->y > 0 ? 0 : Velocity->y;
    
                        A->position.y -= (j - 1);
                        pos.y = A->position.y + A->pixeloffset.y;
                        break;
                    }
                }
            }
        }


        pos.y = A->position.y + A->pixeloffset.y;
        if(pos.y - A->pixelsize.y > 0 && pos.y - A->pixelsize.y < currentLevel.Width * 16)
        {
            if((Get_Tile(pos.x + i,pos.y - A->pixelsize.y) >= 0x80 && Get_Tile(pos.x + i,pos.y - A->pixelsize.y + 8) < 0x80) || (Get_Tile(pos.x - i,pos.y - A->pixelsize.y) >= 0x80 && Get_Tile(pos.x - i,pos.y - A->pixelsize.y + 8) < 0x80))
            {
            
                for(int j = 0; j < 9;j++)
                {
                    if((Get_Tile(pos.x + i,pos.y - A->pixelsize.y) >= 0x80 && Get_Tile(pos.x + i,pos.y - A->pixelsize.y + j) < 0x80) || (Get_Tile(pos.x - i,pos.y - A->pixelsize.y) >= 0x80 && Get_Tile(pos.x - i,pos.y - A->pixelsize.y + j) < 0x80))
                    {
                        Velocity->y = Velocity->y < 0 ? 0 : Velocity->y;
                        A->position.y += (j - 1);
                        pos.y = A->position.y + A->pixeloffset.y;
                        break;
                    }
                }
            }
        }
    }

    for(int i = A->pixelsize.y - 1;i >= 0 ;i-= 8)
    {
        if(pos.x + A->pixelsize.x > 0 && pos.x + A->pixelsize.x < currentLevel.Length * 16)
        {
            if((Get_Tile(pos.x + A->pixelsize.x,pos.y + i) >= 0x80 && Get_Tile(pos.x + A->pixelsize.x - 8,pos.y + i) < 0x80) || (Get_Tile(pos.x + A->pixelsize.x,pos.y - i) >= 0x80 && Get_Tile(pos.x + A->pixelsize.x - 8,pos.y - i) < 0x80))
            {
            
                for(int j = 0; j < 9;j++)
                {
                    if((Get_Tile(pos.x + A->pixelsize.x,pos.y + i) >= 0x80 && Get_Tile(pos.x + A->pixelsize.x - j,pos.y + i) < 0x80) || (Get_Tile(pos.x + A->pixelsize.x,pos.y - i) >= 0x80 && Get_Tile(pos.x + A->pixelsize.x - j,pos.y - i) < 0x80))
                    {
                        Velocity->x = Velocity->x > 0 ? 0 : Velocity->x;
                        A->position.x -= j;
                        pos.x = A->position.x + A->pixeloffset.x;
                        break;
                    }
                }
            }
        }

        if(pos.x - A->pixelsize.x > 0 && pos.x - A->pixelsize.x < currentLevel.Length * 16)
        {
            if((Get_Tile(pos.x - A->pixelsize.x,pos.y + i) >= 0x80 && Get_Tile(pos.x - A->pixelsize.x + 8,pos.y + i) < 0x80) || (Get_Tile(pos.x - A->pixelsize.x,pos.y + i) >= 0x80 && Get_Tile(pos.x - A->pixelsize.x + 8,pos.y + i) < 0x80))
            {
            
                for(int j = 0; j < 9;j++)
                {
                    if((Get_Tile(pos.x - A->pixelsize.x,pos.y + i) >= 0x80 && Get_Tile(pos.x - A->pixelsize.x + j,pos.y + i) < 0x80) || (Get_Tile(pos.x - A->pixelsize.x,pos.y - i) >= 0x80 && Get_Tile(pos.x - A->pixelsize.x + j,pos.y - i) < 0x80))
                    {
                        Velocity->x = Velocity->x < 0 ? 0 : Velocity->x;
                        A->position.x += j;
                        pos.x = A->position.x + A->pixeloffset.x;
                        break;
                    }
                }
            }
        }
    }
}

void MarioTilemapCollisionPhysics(Collision *A,Vector2* Velocity) BANKED
{
    
    Vector2 pos;
    pos.x = A->position.x + A->pixeloffset.x;
    pos.y = A->position.y + A->pixeloffset.y;

    unsigned char c_Right;
    unsigned char c_Left;
    unsigned char c_Mid;
    unsigned char c_Up;
    unsigned char c_Down;

    for(int i = A->pixelsize.x - 1;i >= 0 ;i-= 16)
    {
        if(pos.y + A->pixelsize.y > 0 && pos.y + A->pixelsize.y < currentLevel.Width * 16)
        {
            c_Right = Get_Tile(pos.x + i,pos.y + A->pixelsize.y);
            Tile_Mario_Interact(c_Right,pos.x + i,pos.y + A->pixelsize.y,*Velocity,0);
            c_Left = Get_Tile(pos.x - i,pos.y + A->pixelsize.y);
            Tile_Mario_Interact(c_Left,pos.x - i,pos.y + A->pixelsize.y,*Velocity,0);
            if((c_Right >= 0x80 && Get_Tile(pos.x + i,pos.y + A->pixelsize.y - 16) < 0x80) || (c_Left >= 0x80 && Get_Tile(pos.x - i,pos.y + A->pixelsize.y - 16) < 0x80))
            {
                Velocity->y = Velocity->y > 0 ? 0 : Velocity->y;
                A->position.y = ((pos.y + A->pixelsize.y) / 16) * 16;
                pos.y = A->position.y + A->pixeloffset.y;
            }
        }


        pos.y = A->position.y + A->pixeloffset.y;
        if(pos.y - A->pixelsize.y > 0 && pos.y - A->pixelsize.y < currentLevel.Width * 16)
        {
            c_Right = Get_Tile(pos.x + i,pos.y - A->pixelsize.y);
            Tile_Mario_Interact(c_Right,pos.x + i,pos.y- A->pixelsize.y,*Velocity,1);
            c_Left = Get_Tile(pos.x - i,pos.y - A->pixelsize.y);
            Tile_Mario_Interact(c_Left,pos.x - i,pos.y- A->pixelsize.y,*Velocity,1);
            if((c_Right >= 0x80 && Get_Tile(pos.x + i,pos.y - A->pixelsize.y + 16) < 0x80) || (c_Left >= 0x80 && Get_Tile(pos.x - i,pos.y - A->pixelsize.y + 16) < 0x80))
            {
                Velocity->y = Velocity->y < 0 ? 0 : Velocity->y;
                A->position.y = ((pos.y - A->pixelsize.y) / 16 + 1) * 16 + A->pixelsize.y * 2;
                pos.y = A->position.y - A->pixeloffset.y;
            }
        }
    }

    for(int i = A->pixelsize.y - 1;i >= 0 ;i-= 16)
    {
        pos.x = A->position.x + A->pixeloffset.x;
        if(pos.x + A->pixelsize.x > 0 && pos.x + A->pixelsize.x < currentLevel.Length * 16)
        {
            c_Mid = Get_Tile(pos.x + A->pixelsize.x,pos.y);
            c_Down = Get_Tile(pos.x + A->pixelsize.x,pos.y + i);
            c_Up = Get_Tile(pos.x + A->pixelsize.x,pos.y - i);

            if((c_Down >= 0x80 && Get_Tile(pos.x + A->pixelsize.x - 16,pos.y + i) < 0x80) || (c_Up >= 0x80 && Get_Tile(pos.x + A->pixelsize.x - 16,pos.y - i) < 0x80))
            {
                Velocity->x = Velocity->x > 0 ? 0 : Velocity->x;
                A->position.x = ((pos.x + A->pixelsize.x) / 16) * 16 - 8;
                pos.x = A->position.x + A->pixeloffset.x;

            }
        }

        if(pos.x - A->pixelsize.x > 0 && pos.x - A->pixelsize.x < currentLevel.Length * 16)
        {
            c_Mid = Get_Tile(pos.x - A->pixelsize.x,pos.y);
            c_Down = Get_Tile(pos.x - A->pixelsize.x,pos.y + i);
            c_Up = Get_Tile(pos.x - A->pixelsize.x,pos.y - i);
            if((c_Down >= 0x80 && Get_Tile(pos.x - A->pixelsize.x + 16,pos.y + i) < 0x80) || (c_Up >= 0x80 && Get_Tile(pos.x - A->pixelsize.x + 16,pos.y - i) < 0x80))
            {
                Velocity->x = Velocity->x < 0 ? 0 : Velocity->x;
                A->position.x = ((pos.x - A->pixelsize.x) / 16 + 1) * 16 + 8;
                pos.x = A->position.x - A->pixeloffset.x;
            }
        }
    }
}

void TilemapCollisionPhysicsSide(Collision *A,Vector2* Velocity,int side) BANKED
{
    ENABLE_RAM;
    SWITCH_RAM(2);
    Vector2 pos;
    pos.x = A->position.x + A->pixeloffset.x;
    pos.y = A->position.y + A->pixeloffset.y;

    switch (side)
    {
        case 0:
            for(int i = A->pixelsize.x - 1;i >= 0 ;i-= 16)
            {
                if(pos.y + A->pixelsize.y > 0 && pos.y + A->pixelsize.y < currentLevel.Width * 16)
                {
                    if(Get_Tile(pos.x + i,pos.y + A->pixelsize.y) >= 0x80 || Get_Tile(pos.x - i,pos.y + A->pixelsize.y) >= 0x80 )
                    {
                        Velocity->y = Velocity->y > 0 ? 0 : Velocity->y;
                        A->position.y = ((pos.y + A->pixelsize.y) / 16) * 16;
                        pos.y = A->position.y + A->pixeloffset.y;
                    }
                }
            }
        break;
    
    }
}