#pragma once
#include "raylib.h"
class LoadAllTextureAtStart
{
private:

public :
	Texture2D loadGrass, loadRoad, loadCheckpoint, loadStartLine1, loadStartLine2, loadStartPos, loadObstacle, loadTribune;
	LoadAllTextureAtStart();
	void Start();
};

