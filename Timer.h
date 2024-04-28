#pragma once

#include "raylib.h"
class Timer
{
private:

	float mSecond;
	float mMinute;
	bool mStopTimer = false;

public:

	Timer();
	void Update();
	void Draw(Font ft);
	void Start();
	void Pause();
	float mGetSecond;
	float mGetMinute;
};

