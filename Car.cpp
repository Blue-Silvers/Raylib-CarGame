#include "Car.h"
Car::Car()
{

}
void Car::Start()
{
}
void Car::Update()
{
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		if (mPlayerX > 0)
		{
			mPlayerX -= mPlayerSpeed;
		}
		mPlayerRotaion += mPlayerVelocity / mPlayerMaxVelocity *2;
	}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		if (mPlayerX + mPlayerSizeX < GetScreenWidth())
		{
				mPlayerX += mPlayerSpeed;
		}
		mPlayerRotaion -= mPlayerVelocity / mPlayerMaxVelocity *2;
	}
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
	{
		if (mPlayerVelocity != - mPlayerMaxVelocity)
		{
			mPlayerVelocity -= 0.1;
		}

		mPlayerY += mPlayerVelocity;
	}
	else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
	{
		if (mPlayerVelocity != mPlayerMaxVelocity)
		{
			mPlayerVelocity += 0.1;
		}

		mPlayerY += mPlayerVelocity;
	}
	else 
	{
		if (mPlayerVelocity > 0.1)
		{
			mPlayerVelocity -= 0.2;
		}
		else if (mPlayerVelocity < -0.1)
		{
			mPlayerVelocity += 0.2;
		}

		if (mPlayerVelocity > 0.1 || mPlayerVelocity < -0.1)
		{
		mPlayerY += mPlayerVelocity;
		}
		
	}
}
void Car::Draw()
{
	Rectangle rec{ mPlayerX, mPlayerY, mPlayerSizeX, mPlayerSizeY };
	Vector2 origin{ mPlayerSizeX / 2, mPlayerSizeY / 2 };
	DrawRectanglePro(rec, origin, mPlayerRotaion, WHITE);
}
