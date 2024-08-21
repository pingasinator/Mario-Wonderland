#include "include\collision.h"
#include "include\Sprite.h"


int TileMapCollisionSide(Collision A,Vector2 *velocity,int side)
{
    unsigned char* Tilemap = Get_Tilemap();
    Vector2 pos;
    pos.x = A.position.x + A.offset.x * A.pixeloffset.x;
    pos.y = A.position.y + A.offset.y * A.pixeloffset.y;

    switch(side)
    {
        case 0:
            for(int x = 0; x <= A.size.x; x++)
            {
                if(Tilemap[(pos.x + x * A.pixelsize.x) / 16 + ((pos.y + A.size.y * A.pixelsize.y + velocity->y) / 16) * 128] > 0)
                {
                    while(Tilemap[(pos.x + x * A.pixelsize.x) / 16 + ((pos.y + A.size.y * A.pixelsize.y + velocity->y) / 16) * 128] > 0)
                    {
                        velocity->y--;
                    }

                    if(Tilemap[(pos.x + x * A.pixelsize.x) / 16 + ((pos.y + A.size.y * A.pixelsize.y) / 16) * 128] > 0)
                    {
                        return 1;
                    }
                }   
            }

        break;

        case 1:
            for(int x = 0; x <= A.size.x; x++)
            {
                if(Tilemap[(pos.x + x * A.pixelsize.x) / 16 + ((pos.y + velocity->y) / 16) * 128] > 0)
                {
                    while(Tilemap[(pos.x + x * A.pixelsize.x) / 16 + ((pos.y + velocity->y) / 16) * 128] > 0)
                    {
                        velocity->y++;
                    }

                    if(Tilemap[(pos.x + x * A.pixelsize.x) / 16 + ((pos.y) / 16) * 128] > 0)
                    {
                        return 1;
                    }
                }   
            }
        break;

        case 2:
            for(int y = 0; y <= A.size.y; y++)
            {
                if(Tilemap[(pos.x + velocity->x) / 16 + ((pos.y + y * A.pixelsize.y) / 16) * 128] > 0)
                {
                    while(Tilemap[(pos.x + velocity->x) / 16 + ((pos.y + y * A.pixelsize.y) / 16) * 128] > 0)
                    {
                        velocity->x++;
                    }

                    if(Tilemap[(pos.x) / 16 + ((pos.y + y * A.pixelsize.y) / 16) * 128] > 0)
                    {
                        return 1;
                    }
                }   
            }
        break;

        case 3:
            for(int y = 0; y <= A.size.y; y++)
            {
                if(Tilemap[(pos.x + A.size.x * A.pixelsize.x + velocity->x) / 16 + ((pos.y + y * A.pixelsize.y) / 16) * 128] > 0)
                {
                    while(Tilemap[(pos.x + A.size.x * A.pixelsize.x + velocity->x) / 16 + ((pos.y + y * A.pixelsize.y) / 16) * 128] > 0)
                    {
                        velocity->x--;
                    }

                    if(Tilemap[(pos.x + A.size.x * A.pixelsize.x) / 16 + ((pos.y + y * A.pixelsize.y) / 16) * 128] > 0)
                    {
                        return 1;
                    }
                }   
            }
        break;
    }
    return 0;
}

int Raycast(Vector2 point,Vector2 dir,Vector2 velocity,int size,int pixelSize)
{
    dir.x = Clamp(dir.x,-1,1);
    dir.y = Clamp(dir.y,-1,1);
    for(int i = 0; i < size + 1;i++)
    {
        if(Get_Tilemap()[(point.x + dir.x * i * pixelSize - velocity.x) / 16 + (point.y + dir.y * i * pixelSize - velocity.y) / 16 * 128] > 0)
        {
            return 1;
        }
    }

    return 0;
}