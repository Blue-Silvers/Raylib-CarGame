#include "raylib.h"
#include <iostream>
#include "Car.h"
#include "Tile.h"
#include "Timer.h"
#include "LoadAllTextureAtStart.h"
#include "Menus.h"


using namespace std;

    void Start();
    void StartRace();
    void Update();
    void Draw();
    void End();

    Font ft;
    Car car;
    Tile map[24][16];
    Timer timer;
    LoadAllTextureAtStart loadAllTexture;
    Menus menus;

    int nbCheckPoint;
    bool allCheckpointValidate = false;
    float speedMultiply = 1;

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
        loadAllTexture.Start();
        menus.Start(ft);
    }

    void StartRace()
    {
        int speedMultiply = 1;
        car.Start();
        for (int x = 0; x < 24; x++)
        {
            for (int y = 0; y < 16; y++)
            {
                map[x][y].Start(x, y, loadAllTexture.loadGrass, loadAllTexture.loadRoad, loadAllTexture.loadCheckpoint, loadAllTexture.loadStartLine1, loadAllTexture.loadStartLine2, loadAllTexture.loadStartPos, loadAllTexture.loadObstacle, loadAllTexture.loadTribune);
            }
        }
        allCheckpointValidate = false;
        timer.Start();
    }

    void Update()
    {
        if (menus.Update() == 1) 
        {
            StartRace();
        }
        else if (menus.Update() == 2)
        {
            End();
        }
        nbCheckPoint = 0;
        car.Update(GetFrameTime(), speedMultiply);
        speedMultiply = 1;
        for (int x = 0; x < 24; x++)
        {
            for (int y = 0; y < 16; y++)
            {
                
                if (map[x][y].Update(car, x, y, allCheckpointValidate) == 2) 
                {
                    timer.Pause();
                    menus.GameOver();
                }
                else if (map[x][y].Update(car, x, y, allCheckpointValidate) == 3)
                {
                    speedMultiply = 0.5;
                }
                else if (map[x][y].Update(car, x, y, allCheckpointValidate) == 4)
                {
                    speedMultiply = 0;
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

        car.Draw();

        menus.Draw(timer.mGetMinute, timer.mGetSecond);
        EndDrawing();
    }


    void End()
    {
        CloseWindow();
    }