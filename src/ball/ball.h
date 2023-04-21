#include "raylib.h"

class Ball {
  public:
    Ball(int sWidth, int sHeight);
    void Draw();

  private:
    Texture2D ball = LoadTexture("assets/ball.png");
    int screenWidth = 512;
    int screenHeight = 512;
    int ballWidth = ball.width;
    int ballHeight = ball.height;
    Vector2 ballPos { 50, 50 };
    Rectangle ballRec {  0, 0, (float)ballWidth, (float)ballHeight };
};
