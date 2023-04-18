#include <iostream>

#include "raylib.h"

int main() {

  const int screenWidth = 512;
  const int screenHeight = 512;

  InitWindow(screenWidth, screenHeight, "Game");

  SetTargetFPS(60);

  Texture2D background = LoadTexture("assets/map.png");

  Texture2D ball = LoadTexture("assets/ball.png");

  int ballWidth = ball.width;
  int ballHeight = ball.height;

  // Source rectangle (part of the texture to use for drawing)
  Rectangle sourceRec = { 0.0f, 0.0f, (float)ballWidth, (float)ballHeight };

  // Destination rectangle (screen rectangle where drawing part of texture)
  Rectangle destRec = { screenWidth/2.0f, screenHeight/2.0f, ballWidth*2.0f, ballHeight*2.0f };

  // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
  Vector2 origin = { (float)ballWidth, (float)ballHeight };


  while(!WindowShouldClose()) {

    ClearBackground(WHITE);

    BeginDrawing();

    DrawTextureEx(background, (Vector2){ 0.0f, 0.0f }, 0.0f, 8.0f, WHITE);
    DrawTexturePro(ball, sourceRec, destRec, origin, 0.f, WHITE);

    EndDrawing();
  }

  UnloadTexture(background);

  CloseWindow();

  return 0;
}
