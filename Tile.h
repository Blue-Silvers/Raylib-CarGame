#pragma once
#include "raylib.h"

class Tile
{
private:

	float mTileSize = 50.0f;
	float mTileX = 50.0f;
	float mTileY = 50.0f;

public:

	Tile();
	void Update();
	void Draw(float x, float y);
	void Start();
};

