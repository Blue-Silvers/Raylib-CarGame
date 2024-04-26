#include "raylib.h"
#include <iostream>
#include "Car.h"
#include "Tile.h"

using namespace std;

    void Start();
    void Update();
    void Draw();
    void End();

    Font ft;
    Car car;
    Tile map[24][16];

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
        car.Update(GetFrameTime());
    }

    void Draw()
    {
        BeginDrawing();

        ClearBackground(DARKGREEN);


        for (int x = 0; x < 24; x++)
        {
            for (int y = 0; y < 16; y++)
            {
                map[x][y].Draw(x,y);
            }
        }

        car.Draw();
        EndDrawing();
    }


    void End()
    {
        CloseWindow();
    }