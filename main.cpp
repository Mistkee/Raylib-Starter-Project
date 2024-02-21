#include "raylib.h"
#include <iostream>
#include <string>

using namespace std;

int windowWidht, windowHeight, scoreOne, scoreTwo;

float ballX, ballY, ballSpeedX,ballSpeedY, playerOneY, playerTwoY, playerSpeed, iaSpeed;

bool iaMode;
//Font ft = LoadFont("resources/fonts/alagard.png");

int main() {

    windowWidht = 500;
    windowHeight = 750;
    cout << "Hello World" << endl;

    void Ball(void);
    void MovePlayer(void);

    InitWindow(windowHeight, windowWidht, "Dat window");
    SetTargetFPS(60);
    
    ballX = windowHeight/2;
    ballY = windowWidht / 2;
    ballSpeedX = 2;
    ballSpeedY = 2;
    playerOneY = windowWidht / 2 ;
    playerTwoY = windowWidht / 2 ;
    playerSpeed = 3.5;
    iaSpeed = 1;
    scoreOne = 0;
    scoreTwo = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawRectangle(windowHeight / 2, 0, 10, windowWidht, SKYBLUE);
        DrawText("Press E to play against IA", windowWidht / 2 - 30, 470, 20, WHITE);
        DrawText(TextFormat("%i", scoreOne), windowHeight / 2 - 50, 10, 40, WHITE);
        DrawText(TextFormat("%i", scoreTwo), windowHeight / 2 + 40, 10, 40, WHITE);
        DrawRectangle(30, playerOneY, 15, 100, WHITE);
        DrawRectangle(windowHeight - 50, playerTwoY, 15, 100, WHITE);
        MovePlayer();
        Ball();
        DrawCircle(ballX, ballY, 10, WHITE);
       
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void Ball()
{
    ballX += ballSpeedX;
    ballY += ballSpeedY;
    
    if (ballX < 45 + 10 && playerOneY < ballY && playerOneY + 100 > ballY)
    {
        ballSpeedX -= 0.7;
        ballSpeedX = -ballSpeedX;
    }

    if (ballX > windowHeight - 50 && playerTwoY < ballY && playerTwoY + 100 > ballY)
    {
        ballSpeedX += 0.7;
        ballSpeedX = -ballSpeedX;
    }

    if (ballX -10 < 0)
    {
        scoreTwo++;
        iaSpeed = 1;
        ballSpeedX = 2;
        ballX = windowHeight / 2;
        ballY = windowWidht / 2;
    }
    else if (ballX +10 > 750)
    {
        scoreOne++;
        ballSpeedX = 2;
        iaSpeed += 0.7;
        ballSpeedX = -ballSpeedX;
        ballX = windowHeight / 2;
        ballY = windowWidht / 2;
    }

    if (ballY- 10 < 0)
    {
        ballSpeedY = -ballSpeedY;
    }
    else if (ballY +10 > 500)
    {
        ballSpeedY = -ballSpeedY;
    }
}

void MovePlayer()
{
    if (IsKeyDown(KEY_S) && playerOneY < windowWidht - 100)
    {
        playerOneY += playerSpeed;
    }
    else if (IsKeyDown(KEY_W) && playerOneY > 0)
    {
        playerOneY -= playerSpeed;
    }

    if (IsKeyPressed(KEY_E))
    {
        iaMode = !iaMode;
    }

    if (iaMode)
    {
        if (ballY > playerTwoY)
        {
            playerTwoY += iaSpeed;
        }
        else if (ballY < playerTwoY)
        {
            playerTwoY -= playerSpeed;
        }
    }
    else {
        if (IsKeyDown(KEY_DOWN) && playerTwoY < windowWidht - 100)
        {
            playerTwoY += playerSpeed;
        }
        else if (IsKeyDown(KEY_UP) && playerTwoY > 0)
        {
            playerTwoY -= playerSpeed;
        }
    }
    

   

}