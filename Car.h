#pragma once
#include "raylib.h"

class Car
{
private:

	float mPlayerSpeed = 5;
	float mPlayerVelocity = 0;
	float mPlayerMaxVelocity = 5;
	float mPlayerRotaion = 0;

public:
	float mPlayerX = 50;
	float mPlayerY = 150;
	float mPlayerSizeX = 20;
	float mPlayerSizeY = 40;
	bool mCanGoForward = true;
	Car();
	void Update();
	void Draw();
	void Start();
};

