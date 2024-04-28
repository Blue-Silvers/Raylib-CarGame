#pragma once
#include "raylib.h"
#include "raymath.h"
#include <cmath>
class Car
{
private:

	float mPlayerSpeed = 100;
	float mPlayerVelocity = 0;
	float mPlayerMaxVelocity = 200;
	float mPlayerRotaion = 0;
	Texture2D carTexture;

public:
	float mPlayerX = 815;
	float mPlayerY = 675;
	float mPlayerSizeX = 50;
	float mPlayerSizeY = 28;
	bool mCanGoForward = true;
	bool mCanGoBackward = true;
	Car();
	void Update(float timeDeltaTime, float multiplicator);
	void Draw();
	void Start();
};

