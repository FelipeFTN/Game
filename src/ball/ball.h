#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball {
  public:
    Ball(int sWidth, int sHeight, int x, int y, int id);
    void Draw();
    void Move(float deltaTime);
    void Collision(Ball ball);

    Vector2 GetInitialPosition();
    Rectangle GetCollisionRec();
    float GetWidth();
    float GetHeight();
    float GetX();
    float GetY();

    Vector2 GetSpeed();
    void SetSpeed(Vector2 speed);
    void SetPosition(Vector2 position);
    void SetAcceleration(float acceleration);

  private:
    Texture2D ball = LoadTexture("assets/ball_medium.png");
    int id = 0;
    int screenWidth = 512;
    int screenHeight = 512;
    bool canCollide = true;
    Vector2 ballInitialPos { 50, 50 };
    Vector2 ballSpeed { 0.f, 0.f };
    float ballAcceleration = 10.0f;
    Vector2 ballPos { 50, 50 };
    Rectangle ballRec { 0, 0, GetWidth(), GetHeight() };
};
#endif
