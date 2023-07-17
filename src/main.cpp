#include "ball/ball.h"
#include "map/map.h"
#include "raylib.h"
#include <string>

int main() {
  const int screenWidth = 512;
  const int screenHeight = 512;

  InitWindow(screenWidth, screenHeight, "Game");

  Map map{};
  int wallTime = 0;
  bool show_wall_0 = true;
  bool show_wall_1 = false;
  Rectangle wall_0{-84, 111, 100, screenHeight / 1.8f};
  Rectangle wall_1{screenWidth - 16, 111, 100, screenHeight / 1.8f};
  Ball ball_0{screenWidth, screenHeight, 50, 50, 0};
  Ball ball_1{screenWidth, screenHeight, screenWidth - 75, screenHeight - 75, 1};

  SetTargetFPS(60);

  ClearBackground(BLACK);

  while (!WindowShouldClose()) {

    map.WallControl(&wallTime, &show_wall_0, &show_wall_1);

    ball_0.Collision(&ball_1, show_wall_0, show_wall_1);
    ball_1.Collision(&ball_0, show_wall_0, show_wall_1);

    BeginDrawing();

    map.DrawMap(screenWidth, screenHeight);
    map.Wall(&wall_0, show_wall_0);
    map.Wall(&wall_1, show_wall_1);

    ball_0.DrawScore(screenWidth - 75, 50);
    ball_1.DrawScore(50, screenHeight - 75);

    if (ball_0.GetScore() > 0) {
      ball_0.Draw();
      ball_0.Move(GetFrameTime());
    } else { DrawText("Player 2 Won!", (screenWidth / 2) - 60, screenHeight / 2, 20, LIGHTGRAY); }

    if (ball_1.GetScore() > 0) {
      ball_1.Draw();
      ball_1.Move(GetFrameTime());
    } else { DrawText("Player 1 Won!", (screenWidth / 2) - 60, screenHeight / 2, 20, LIGHTGRAY); }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
/* DEBUGGING TEST */
/* DrawText(std::to_string(ball.GetX()).c_str(), 190, 200, 20, LIGHTGRAY); */
