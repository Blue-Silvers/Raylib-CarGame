#include "Tile.h"
Tile::Tile()
{

}
void Tile::Start()
{
}
void Tile::Update()
{
}
void Tile::Draw(float x, float y)
{
	DrawRectangle(x * mTileX, y * mTileY, mTileSize, mTileSize, BLACK);

	DrawRectangle(x * mTileX+5, y * mTileY+5, mTileSize-10, mTileSize-10, GRAY);
}
