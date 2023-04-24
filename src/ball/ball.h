#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball {
  public:
    Ball(int sWidth, int sHeight, int x, int y, int id);
    void Draw();
    void Move();
    void Collision();


    Vector2 GetInitialPosition();
    float GetX();
    float GetY();

    Vector2 GetSpeed();
    void SetSpeed(Vector2 speed);
    void SetPosition(Vector2 position);

  private:
    Texture2D ball = LoadTexture("assets/ball.png");
    int id = 0;
    int screenWidth = 512;
    int screenHeight = 512;
    bool canCollide = true;
    int ballWidth = ball.width;
    int ballHeight = ball.height;
    Vector2 ballInitialPos { 50, 50 };
    Vector2 ballSpeed { 0.f, 0.f };
    Vector2 ballPos { 50, 50 };
    Rectangle ballRec {  0, 0, (float)ballWidth, (float)ballHeight };
};
#endif
