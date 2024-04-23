#include "raylib.h"
#include <iostream>
#include "Car.h"

using namespace std;

    void Start();
    void Update();
    void Draw();
    void End();

    Font ft;
    Car car;

    int main() 
    {

        Start();

        while (!WindowShouldClose())
        {
            Update();
            Draw();
        }

        End();
        return 0;
    }


    void Start()
    {
        InitWindow(1200, 800, "Car Game");
        SetTargetFPS(60);
        ft = LoadFont("resources/fonts/jupiter_crash.png");
    }

    void Update()
    {
        car.Update();
    }

    void Draw()
    {
        BeginDrawing();

        ClearBackground(DARKGREEN);

        car.Draw();

        EndDrawing();
    }


    void End()
    {
        CloseWindow();
    }