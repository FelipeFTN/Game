#include "raylib.h"

class Ball {
  public:
    Ball(int sWidth, int sHeight);
    void Draw();

  private:
    Texture2D ball = LoadTexture("assets/ball.png");
    int screenWidth = 0;
    int screenHeight = 0;
    int ballWidth = ball.width;
    int ballHeight = ball.height;
    Rectangle sourceRec = { 0.0f, 0.0f, (float)ballWidth, (float)ballHeight };
    Rectangle destRec = { screenWidth/2.0f, screenHeight/2.0f, ballWidth*2.0f, ballHeight*2.0f };
    Vector2 origin = { (float)ballWidth, (float)ballHeight };
};
