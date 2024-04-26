#include "Car.h"

#include "raymath.h"
#include <cmath>
Car::Car()
{

}
void Car::Start()
{
}
void Car::Update(float timeDeltaTime)
{
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		mPlayerRotaion -= mPlayerVelocity / mPlayerMaxVelocity * mPlayerSpeed * DEG2RAD * timeDeltaTime;
	}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		mPlayerRotaion += mPlayerVelocity / mPlayerMaxVelocity * mPlayerSpeed * DEG2RAD * timeDeltaTime;
	}
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
	{
		if (mPlayerVelocity < mPlayerMaxVelocity)
		{
			mPlayerVelocity += 0.5;
		}
	}
	else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
	{
		if (mPlayerVelocity > -mPlayerMaxVelocity)
		{
			mPlayerVelocity -= 0.5;
		}
	}
	else 
	{
		mPlayerVelocity = Lerp(mPlayerVelocity, 0, timeDeltaTime * 2);
	}

	mPlayerX += cos(mPlayerRotaion)*(mPlayerVelocity * timeDeltaTime);
	mPlayerY += sin(mPlayerRotaion)*(mPlayerVelocity * timeDeltaTime);

}
void Car::Draw()
{
	Rectangle rec{ mPlayerX, mPlayerY, mPlayerSizeX, mPlayerSizeY };
	Vector2 origin{ mPlayerSizeX / 2, mPlayerSizeY / 2 };
	DrawRectanglePro(rec, origin, mPlayerRotaion * RAD2DEG, WHITE);
}
