#include "Car.h"


Car::Car()
{

}
void Car::Start()
{
	carTexture = LoadTexture("kenney_racing-pack/PNG/Cars/car_blue_small_5.png");
	mPlayerX = 815;
	mPlayerY = 675;
	mPlayerRotaion = 0;
	mPlayerVelocity = 0;
}
void Car::Update(float timeDeltaTime, float multiplicator)
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
		if (mCanGoForward == false) 
		{
			mPlayerVelocity = 0;
		}
	}
	else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
	{
		if (mPlayerVelocity > -mPlayerMaxVelocity)
		{
			mPlayerVelocity -= 0.5;
		}
		if (mCanGoBackward == false)
		{
			mPlayerVelocity = 0;
		}
	}
	else 
	{
		mPlayerVelocity = Lerp(mPlayerVelocity, 0, timeDeltaTime * 2);
	}

	mPlayerX += cos(mPlayerRotaion)*(mPlayerVelocity * multiplicator * timeDeltaTime);
	mPlayerY += sin(mPlayerRotaion)*(mPlayerVelocity * multiplicator * timeDeltaTime);

	if (multiplicator == 0)
	{
		mCanGoForward = false;
		mPlayerX += cos(mPlayerRotaion) * (mPlayerVelocity * timeDeltaTime);
		mPlayerY += sin(mPlayerRotaion) * (mPlayerVelocity * timeDeltaTime);
	}
	else {
		mCanGoForward = true;
	}

	if (mPlayerX < mPlayerSizeY)
	{
		mPlayerX = mPlayerSizeY;
	}
	if (mPlayerY < mPlayerSizeY)
	{
		mPlayerY = mPlayerSizeY;
	}
	if (mPlayerX + mPlayerSizeY > GetScreenWidth())
	{
		mPlayerX = GetScreenWidth() - mPlayerSizeY;
	}
	if (mPlayerY + mPlayerSizeY > GetScreenHeight())
	{
		mPlayerY = GetScreenHeight() - mPlayerSizeY;
	}

}
void Car::Draw()
{
	Rectangle rec{ mPlayerX, mPlayerY, mPlayerSizeX, mPlayerSizeY };
	Vector2 origin{ mPlayerSizeX / 2, mPlayerSizeY / 2 };
	//DrawRectanglePro(rec, origin, mPlayerRotaion * RAD2DEG, WHITE);
	DrawTexturePro(carTexture, Rectangle { 0, 0, 65, 39 }, rec, origin, mPlayerRotaion * RAD2DEG, WHITE);
}
