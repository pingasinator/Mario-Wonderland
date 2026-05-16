#include <gb/gb.h>
#include "Mathf.h"

void Tile_Mario_Interact(unsigned char Tile,int X,int Y,Vector2 Velocity,int sideX,int sideY) BANKED;
void Tile_Use_Coin(int x,int y) BANKED;
void Tile_Overworld_Mario_Interact(unsigned char Tile) BANKED;
void Tile_Mario_Interact_Pipe(unsigned char basedTile,int side) BANKED;