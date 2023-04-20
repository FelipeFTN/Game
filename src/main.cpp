#include "raylib.h"
#include "ball/ball.h"
#include "map/map.h"

int main() {

  const int screenWidth = 512;
  const int screenHeight = 512;

  InitWindow(screenWidth, screenHeight, "Game");

  Map map{ };
  Ball ball{ screenWidth, screenHeight };

  SetTargetFPS(60);

  while(!WindowShouldClose()) {

    ClearBackground(BLACK);

    BeginDrawing();

    map.Draw();
    ball.Draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
