#pragma once
#include "raylib.h"
#include "Environement.h"
#include "Car.h"


class Tile
{
private:

	float mTileSize = 50.0f;
	float mTileX = 50.0f;
	float mTileY = 50.0f;
    int mTileMap[16][24]
    {
        { 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 5, 5, 0, 0, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0},
        { 5, 0, 0, 1, 1, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
        { 5, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 7, 9, 9, 0, 0, 0, 0, 0},
        { 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 5, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0},
        { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 2, 1, 1, 0, 0, 0, 0},
        { 0, 1, 1, 0, 5, 5, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0},
        { 0, 1, 1, 0, 0, 5, 5, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0},
        { 0, 2, 2, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 1, 1, 0, 0, 5, 0, 0, 1, 1, 1, 0},
        { 0, 1, 1, 0, 7, 9, 9, 0, 0, 0, 1, 2, 1, 1, 0, 0, 5, 5, 5, 0, 0, 2, 2, 0},
        { 0, 1, 1, 0, 9, 9, 9, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 0, 0, 1, 1, 0},
        { 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        { 0, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 6, 6, 6, 6, 3, 1, 1, 1, 1, 0, 0},
        { 0, 5, 1, 1, 2, 1, 1, 1, 1, 0, 0, 5, 1, 6, 6, 6, 6, 4, 1, 1, 1, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    Texture2D grass, road, checkpoint, startLine1, startLine2, startPos, obstacle, tribune;


public:

	Tile();
	int Update(Car car, int x, int y, bool activeEnd);
	void Draw(int x, int y);
	void Start(int x, int y, Texture2D loadGrass, Texture2D loadRoad, Texture2D loadCheckpoint, Texture2D loadStartLine1, Texture2D loadStartLine2, Texture2D loadStartPos, Texture2D loadObstacle, Texture2D loadTribune);

    bool mCheckpoint = true;
    bool mValidateCheckpoint = false;
};

