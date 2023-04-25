#include "ball/ball.h"
#include "map/map.h"
#include "raylib.h"
#include <string>

int main() {
  const int screenWidth = 512;
  const int screenHeight = 512;

  InitWindow(screenWidth, screenHeight, "Game");

  Map map{};
  Ball ball_0{screenWidth, screenHeight, 50, 50, 0};
  Ball ball_1{screenWidth, screenHeight, screenWidth - 75, screenHeight - 75, 1};

  SetTargetFPS(60);

  ClearBackground(BLACK);

  while (!WindowShouldClose()) {

    ball_0.Collision(&ball_1);
    ball_1.Collision(&ball_0);

    BeginDrawing();

    map.Draw();
    ball_0.Draw();
    ball_0.Move(GetFrameTime());

    ball_1.Draw();
    ball_1.Move(GetFrameTime());

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
/* DEBUGGING TEST */
/* DrawText(std::to_string(ball.GetX()).c_str(), 190, 200, 20, LIGHTGRAY); */
