#include "include\collision.h"
#include "include\Level.h"


int TileMapCollisionSide(Collision A,Vector2 velocity,int side)
{
    Vector2 pos;
    pos.x = A.position.x + A.offset.x * A.pixeloffset.x;
    pos.y = A.position.y + A.offset.y * A.pixeloffset.y;

    switch(side)
    {
        case 0:
            for(int x = 0; x <= A.size.x; x++)
            {
                int ox = pos.x + x * A.pixelsize.x + 1 < 0 ? 32 * 8: 0;
                int oy = pos.y + A.size.y * A.pixelsize.y + 1 < 0 ? 32 * 8: 0;
                for(int i = 0; i < 2; i++)
                {
                    if((GetCurrentLevel()[i].position.x == (pos.x + - velocity.x + x * A.pixelsize.x - ox) / 8 / 32) && (GetCurrentLevel()[i].position.y == (pos.y + A.size.y * A.pixelsize.y - oy) / 8 / 32))
                    {
                        if(GetCurrentLevel()[i].Tilemap[((pos.x + - velocity.x + x * A.pixelsize.x - ox) / 8 - GetCurrentLevel()[i].position.x * 32) + ((pos.y + A.size.y * A.pixelsize.y - oy) / 8 - GetCurrentLevel()[i].position.y * 32) * 32])
                        {
                           return 1; 
                        }
                    }
                }
            }

        break;

        case 1:
            for(int x = 0; x <= A.size.x; x++)
            {
                int ox = pos.x + x * A.pixelsize.x < 0 ? 32 * 8: 0;
                int oy = pos.y < 0 ? 32 * 8: 0;
                for(int i = 0; i < 2; i++)
                {
                    if((GetCurrentLevel()[i].position.x == (pos.x - velocity.x + x * A.pixelsize.x - ox) / 8 / 32) && (GetCurrentLevel()[i].position.y == (pos.y - oy) / 8 / 32))
                    {
                        if(GetCurrentLevel()[i].Tilemap[((pos.x - velocity.x + x * A.pixelsize.x - ox) / 8 - GetCurrentLevel()[i].position.x * 32) + ((pos.y - oy) / 8 - GetCurrentLevel()[i].position.y * 32) * 32])
                        {
                           return 1; 
                        }
                    }
                }
            }

        break;

        case 2:
            for(int y = 0; y <= A.size.y; y++)
            {
                int ox = pos.x + A.size.x * A.pixelsize.x < 0 ? 32 * 8: 0;
                int oy = pos.y + y * A.pixelsize.y < 0 ? 32 * 8: 0;
                for(int i = 0; i < 2; i++)
                {
                    if((GetCurrentLevel()[i].position.x == (pos.x + A.size.x * A.pixelsize.x - ox) / 8 / 32) && (GetCurrentLevel()[i].position.y == (pos.y +  y * A.pixelsize.y - oy) / 8 / 32))
                    {
                        if(GetCurrentLevel()[i].Tilemap[((pos.x + A.size.x * A.pixelsize.x - ox) / 8 - GetCurrentLevel()[i].position.x * 32) + ((pos.y + y * A.pixelsize.y - oy) / 8 - GetCurrentLevel()[i].position.y * 32) * 32])
                        {
                           return 1; 
                        }
                    }
                }
            }
        break;

        case 3:
            for(int y = 0; y <= A.size.y; y++)
            {
                int ox = pos.x + A.size.x * A.pixelsize.x < 0 ? 32 * 8: 0;
                int oy = pos.y + y * A.pixelsize.y < 0 ? 32 * 8: 0;
                for(int i = 0; i < 2; i++)
                {
                    if((GetCurrentLevel()[i].position.x == (pos.x - ox) / 8 / 32) && (GetCurrentLevel()[i].position.y == (pos.y +  y * A.pixelsize.y - oy) / 8 / 32))
                    {
                        if(GetCurrentLevel()[i].Tilemap[((pos.x - ox) / 8 - GetCurrentLevel()[i].position.x * 32) + ((pos.y + y * A.pixelsize.y - oy) / 8 - GetCurrentLevel()[i].position.y * 32) * 32])
                        {
                           return 1; 
                        }
                    }
                }
            }
        break;
    }
    return 0;
}