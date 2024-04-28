#include "Tile.h"
Tile::Tile()
{

}
void Tile::Start(int x, int y, Texture2D loadGrass, Texture2D loadRoad, Texture2D loadCheckpoint, Texture2D loadStartLine1, Texture2D loadStartLine2, Texture2D loadStartPos, Texture2D loadObstacle, Texture2D loadTribune)
{
	//load texture
	if (mTileMap[y][x] == (int)TileType::GRASS)
	{
		grass = loadGrass;
	}
	else if (mTileMap[y][x] == (int)TileType::ROAD)
	{
		road = loadRoad;
	}
	else if (mTileMap[y][x] == (int)TileType::CHECKPOINT)
	{
		checkpoint = loadCheckpoint;
		mCheckpoint = false;
	}
	else if (mTileMap[y][x] == (int)TileType::STARTLINE1)
	{
		startLine1 = loadStartLine1;
	}
	else if (mTileMap[y][x] == (int)TileType::STARTLINE2)
	{
		startLine2 = loadStartLine2;
	}
	else if (mTileMap[y][x] == (int)TileType::STARTPOS)
	{
		startPos = loadStartPos;
	}
	else if (mTileMap[y][x] == (int)TileType::OBSTACLE)
	{
		grass = loadGrass;
		obstacle = loadObstacle;
	}
	else if (mTileMap[y][x] == (int)TileType::TRIBUNE)
	{
		tribune = loadTribune;
	}
}
int Tile::Update(Car car, int x, int y, bool activeEnd)
{
	if (mCheckpoint == false && car.mPlayerX + car.mPlayerSizeX / 2 > mTileX * x && car.mPlayerX + car.mPlayerSizeX / 2 < mTileX * x + mTileSize && car.mPlayerY + car.mPlayerSizeY / 2 > mTileY * y && car.mPlayerY + car.mPlayerSizeY / 2 < mTileY * y + mTileSize)
	{
		mCheckpoint = true;
		mValidateCheckpoint = true;
		return 1;
	}
	if (activeEnd == true && car.mPlayerX + car.mPlayerSizeX / 2 > mTileX * x && car.mPlayerX + car.mPlayerSizeX / 2 < mTileX * x + mTileSize && car.mPlayerY + car.mPlayerSizeY / 2 > mTileY * y && car.mPlayerY + car.mPlayerSizeY / 2 < mTileY * y + mTileSize)
	{
		if (mTileMap[y][x] == (int)TileType::STARTLINE1 || mTileMap[y][x] == (int)TileType::STARTLINE2)
		{
			return 2;
		}
	}
	if (car.mPlayerX + car.mPlayerSizeX / 2 > mTileX * x && car.mPlayerX + car.mPlayerSizeX / 2 < mTileX * x + mTileSize && car.mPlayerY + car.mPlayerSizeY / 2 > mTileY * y && car.mPlayerY + car.mPlayerSizeY / 2 < mTileY * y + mTileSize)
	{
		if (mTileMap[y][x] == (int)TileType::GRASS)
		{
			return 3;
		}
	}
	if (car.mPlayerX + car.mPlayerSizeX > mTileX * x && car.mPlayerX < mTileX * x + mTileSize && car.mPlayerY + car.mPlayerSizeY > mTileY * y + mTileSize && car.mPlayerY - car.mPlayerSizeY < mTileY * y + mTileSize)
	{
		if (mTileMap[y][x] == (int)TileType::OBSTACLE || mTileMap[y][x] == (int)TileType::TRIBUNE || mTileMap[y][x] == 9)
		{
			return 4;
		}
	}
}
void Tile::Draw(int x, int y)
{
	Rectangle rec{ mTileX * x, mTileY * y, mTileSize, mTileSize };
	Vector2 origin{ 0, 0};
	if (mTileMap[y][x]== (int)TileType::GRASS)
	{
		DrawTexturePro(grass, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	}
	else if (mTileMap[y][x] == (int)TileType::ROAD)
	{
		DrawTexturePro(road, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	}
	else if (mTileMap[y][x] == (int)TileType::CHECKPOINT)
	{
		DrawTexturePro(checkpoint, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	}
	else if (mTileMap[y][x] == (int)TileType::STARTLINE1)
	{
		DrawTexturePro(startLine1, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	}
	else if (mTileMap[y][x] == (int)TileType::STARTLINE2)
	{
		DrawTexturePro(startLine2, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	}
	else if (mTileMap[y][x] == (int)TileType::STARTPOS)
	{
		DrawTexturePro(startPos, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
	}
	else if (mTileMap[y][x] == (int)TileType::OBSTACLE)
	{
		DrawTexturePro(grass, Rectangle{ 0, 0, 128, 128 }, rec, origin, 0.0f, WHITE);
		DrawTexturePro(obstacle, Rectangle{ 0, 0, 141, 141 }, rec, origin, 0.0f, LIGHTGRAY);
	}
	else if (mTileMap[y][x] == (int)TileType::TRIBUNE)
	{
		DrawTexturePro(tribune, Rectangle{ 0, 0, 448, 223 }, Rectangle { mTileX * x, mTileY * y, mTileSize *3, mTileSize *2 }, origin, 0.0f, WHITE);
	}
}
