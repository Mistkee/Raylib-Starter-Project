#include "raylib.h"
#include <iostream>

using namespace std;

const char* windowName;
int width, length;

float ballX, ballY;
Vector2 ball;
float speedBX, speedBY;
int ballRadius;

int paddleWidth, paddleLength;
float paddlePos1, paddlePos2, paddleSpeed;

void PlayersMovements();
Vector2 BallPosition();
bool Collision();
int main() {

    windowName = "Super !";

    width = 720;
    length = 900;
    
    paddleLength = 20;
    paddleWidth = 100;
    paddlePos1 = width / 2;
    paddlePos2 = width / 2;
    paddleSpeed = 8;

    speedBX = 5;
    speedBY = 5;

    ballRadius = 15;
    ballX = width / 2;
    ballY = length / 2;

    InitWindow(length,width , windowName);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
  
        ball = BallPosition();
        PlayersMovements();
        bool Collision();

        BeginDrawing();
        ClearBackground(BLUE);
        DrawCircle(ball.x, ball.y, ballRadius, WHITE);
        DrawRectangle(length / 6, paddlePos1, paddleLength, paddleWidth, WHITE);
        DrawRectangle(length - length / 6, paddlePos2, paddleLength, paddleWidth, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

Vector2 BallPosition()
{
    ballX += speedBX;
    ballY += speedBY;

    if (ballX > length || ballX < 0 || Collision())
    {
        speedBX *= -1;
    }

    if (ballY > width || ballY < 0)
    {
        speedBY *= -1;
    }

    return { ballX,ballY };
}

void PlayersMovements()
{
    if (IsKeyDown(KEY_S))
    {
        paddlePos1 += paddleSpeed;
    }
    if (IsKeyDown(KEY_W))
    {
        paddlePos1 -= paddleSpeed;
    }
    
    if (paddlePos1 > width - paddleWidth)
    {
        paddlePos1 = width - paddleWidth;
    }
    else if (paddlePos1 < 0)
    {
        paddlePos1 = 0;
    }

    if (IsKeyDown(KEY_DOWN))
    {
        paddlePos2 += paddleSpeed;
    }
    if (IsKeyDown(KEY_UP))
    {
        paddlePos2 -= paddleSpeed;
    }

    if (paddlePos2 > width - paddleWidth)
    {
        paddlePos2 = width - paddleWidth;
    }
    else if (paddlePos2 < 0)
    {
        paddlePos2 = 0;
    }
}

bool Collision()
{
    if (ball.y > paddlePos1 && ball.y < paddlePos1 + paddleWidth && ball.x == length / 6 + paddleLength + ballRadius)
    {
        return true;
    }
    else false;
}
