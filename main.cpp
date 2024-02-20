#include "raylib.h"
#include <iostream>

using namespace std;

int windowWidht, windowHeight;

float ballX, ballY, ballSpeedX,ballSpeedY;

int main() {

    windowWidht = 500;
    windowHeight = 750;
    cout << "Hello World" << endl;

    void Ball(void);

    InitWindow(windowHeight, windowWidht, "Dat window");
    SetTargetFPS(60);
    
    ballX = windowHeight/2;
    ballY = windowWidht / 2;
    ballSpeedX = 1;
    ballSpeedY = 1;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        Ball();
        DrawCircle(ballX, ballY, 8, WHITE);
       
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void Ball()
{
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    if (ballX < 0)
    {
        ballSpeedX = -ballSpeedX;
        
    }
    else if (ballX > 750)
    {
        ballSpeedX = -ballSpeedX;
    }

    if (ballY < 0)
    {
        ballSpeedY = -ballSpeedY;
    }
    else if (ballY > 500)
    {
        ballSpeedY = -ballSpeedY;
    }
}