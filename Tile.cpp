#include "Tile.h"
Tile::Tile()
{

}
void Tile::Start(int x, int y)
{
	//load texture
	if (mTileMap[y][x] == (int)TileType::GRASS)
	{
		grass = LoadTexture("kenney_racing-pack/PNG/Tiles/Grass/land_grass04.png");
	}
	else if (mTileMap[y][x] == (int)TileType::ROAD)
	{
		road = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt22.png");
	}
	else if (mTileMap[y][x] == (int)TileType::CHECKPOINT)
	{
		checkpoint = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt90.png");
	}
	else if (mTileMap[y][x] == (int)TileType::STARTLINE1)
	{
		startLine1 = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt87.png");
	}
	else if (mTileMap[y][x] == (int)TileType::STARTLINE2)
	{
		startLine2 = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt89.png");
	}
	else if (mTileMap[y][x] == (int)TileType::STARTPOS)
	{
		startPos = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt84.png");
	}
	else if (mTileMap[y][x] == (int)TileType::OBSTACLE)
	{
		grass = LoadTexture("kenney_racing-pack/PNG/Tiles/Grass/land_grass04.png");
		obstacle = LoadTexture("kenney_racing-pack/PNG/Objects/tree_small.png");
	}
	else if (mTileMap[y][x] == (int)TileType::TRIBUNE)
	{
		tribune = LoadTexture("kenney_racing-pack/PNG/Objects/tribune_full.png");
	}
}
void Tile::Update()
{
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
