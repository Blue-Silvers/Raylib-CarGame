#pragma once

#include "raylib.h"
class Timer
{
private:

	float mSecond;
	float mMinute;

public:

	Timer();
	void Update();
	void Draw(Font ft);
	void Start();
};

