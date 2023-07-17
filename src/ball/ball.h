#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball {
  public:
    Ball(int sWidth, int sHeight, int x, int y, int id);
    void Draw();
    void Move(float deltaTime);
    void Collision(Ball *ball, bool wall_0, bool wall_1);
    void DrawScore(int x, int y);

    Vector2 GetInitialPosition();
    Rectangle GetCollisionRec();
    Vector2 GetSpeed();
    float GetHeight();
    float GetWidth();
    int GetScore();
    float GetX();
    float GetY();

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
    float ballAcceleration = 13.0f;
    float stopDragSpeed = 0.01f;
    Vector2 ballPos { 50, 50 };
    Rectangle ballRec { 0, 0, GetWidth(), GetHeight() };
    bool enabled = true;
    int score = 3;
};
#endif
