#include "raylib.h"
#include <iostream>
#include "Car.h"
#include "Tile.h"
#include "Timer.h"


using namespace std;

    void Start();
    void Update();
    void Draw();
    void End();

    Font ft;
    Car car;
    Tile map[24][16];
    Timer timer;
    int nbCheckPoint;
    bool allCheckpointValidate = false;

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
        car.Start();
        for (int x = 0; x < 24; x++)
        {
            for (int y = 0; y < 16; y++)
            {
                map[x][y].Start(x, y);
            }
        }
        allCheckpointValidate = false;
        timer.Start();
    }

    void Update()
    {
        nbCheckPoint = 0;
        car.Update(GetFrameTime());
        for (int x = 0; x < 24; x++)
        {
            for (int y = 0; y < 16; y++)
            {
                
                if (map[x][y].Update(car, x, y, allCheckpointValidate) == 2) 
                {
                    timer.Pause();
                }
                if (map[x][y].mCheckpoint == false) 
                {
                    nbCheckPoint += 1;
                }
                if (map[x][y].mValidateCheckpoint == true && x>0 && y>0) 
                {
                    map[x][y + 1].mCheckpoint = true;
                    map[x + 1][y].mCheckpoint = true;
                    map[x][y - 1].mCheckpoint = true;
                    map[x - 1][y].mCheckpoint = true;
                }
            }
        }
        if (nbCheckPoint == 0) 
        {
            allCheckpointValidate = true;
        }
        timer.Update();
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

        timer.Draw(ft);

        DrawTextEx(ft, TextFormat(" %01i ", nbCheckPoint), Vector2{ 200,50 }, 50, 5, WHITE);

        car.Draw();
        EndDrawing();
    }


    void End()
    {
        CloseWindow();
    }