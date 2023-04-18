#include <iostream>
#include <string>

#include "raylib.h"

int main() {

  const int screenWidth = 512;
  const int screenHeigt = 512;

  InitWindow(screenWidth, screenHeigt, "Game");

  SetTargetFPS(60);

  Texture2D background = LoadTexture("assets/map.png");

  while(!WindowShouldClose()) {

    ClearBackground(WHITE);

    BeginDrawing();

    DrawTextureEx(background, (Vector2){ 0.0f, 0.0f }, 0.0f, 8.0f, WHITE);

    EndDrawing();
  }

  UnloadTexture(background);

  CloseWindow();

  return 0;
}
