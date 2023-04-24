#include "ball/ball.h"
#include "map/map.h"
#include "raylib.h"
#include <string>

int main() {
  const int screenWidth = 512;
  const int screenHeight = 512;

  InitWindow(screenWidth, screenHeight, "Game");

  Map map{};
  Ball ball{screenWidth, screenHeight};

  SetTargetFPS(60);

  ClearBackground(BLACK);

  while (!WindowShouldClose()) {

    ball.Collision();

    BeginDrawing();

    map.Draw();
    ball.Draw();
    ball.Move();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
/* DEBUGGING TEST */
/* DrawText(std::to_string(ball.GetX()).c_str(), 190, 200, 20, LIGHTGRAY); */
