#pragma once
#include "raylib.h"

class Car
{
private:

	float mPlayerSpeed = 100;
	float mPlayerVelocity = 0;
	float mPlayerMaxVelocity = 200;
	float mPlayerRotaion = 0;

public:
	float mPlayerX = 50;
	float mPlayerY = 150;
	float mPlayerSizeX = 40;
	float mPlayerSizeY = 20;
	bool mCanGoForward = true;
	Car();
	void Update(float timeDeltaTime);
	void Draw();
	void Start();
};

