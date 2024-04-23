#pragma once
#include "raylib.h"

class Car
{
private:

	float mPlayerSpeed = 5.0f;
	float mPlayerVelocity = 0.0f;
	float mPlayerMaxVelocity = 5.0f;
	float mPlayerRotaion = 0;

public:
	float mPlayerX = 50.0f;
	float mPlayerY = 150.0f;
	float mPlayerSizeX = 20.0f;
	float mPlayerSizeY = 40.0f;
	bool mCanGoForward = true;
	Car();
	void Update();
	void Draw();
	void Start();
};

