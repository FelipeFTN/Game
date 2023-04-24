#include "ball.h"

Ball::Ball(int sWidth, int sHeight) {
  screenWidth = sWidth;
  screenHeight = sHeight;
}

void Ball::Draw() {
  DrawTextureRec(ball, ballRec, ballPos, WHITE);
}

void Ball::Move() {
  // Movement
  ballPos.x += ballSpeed.x;
  ballPos.y += ballSpeed.y;

  // Key pressing
  if(IsKeyDown(KEY_W)) {
    ballSpeed.y -= 0.2f; 
  } else if(IsKeyDown(KEY_S)) {
    ballSpeed.y += 0.2f; 
  } else if(IsKeyDown(KEY_A)) {
    ballSpeed.x -= 0.2f; 
  } else if(IsKeyDown(KEY_D)) {
    ballSpeed.x += 0.2f; 
  }
}

void Ball::SetSpeed(Vector2 speed) {
  ballSpeed = {speed.x, speed.y};
}

void Ball::Collision() {
    float blockSpeed = 2.f;

    if(GetY() >= 110.f && GetY() <= screenHeight - 125.f) {
      canCollide = false;
    } else { canCollide = true; }

    if(GetX() >= screenWidth - 30 && canCollide) {
      SetSpeed(Vector2{GetSpeed().x - blockSpeed * GetSpeed().x, GetSpeed().y});
    }
    if(GetY() >= screenHeight - 30 && canCollide) {
      SetSpeed(Vector2{GetSpeed().x, GetSpeed().y - blockSpeed * GetSpeed().y});
    }
    if(GetY() <= 15 && canCollide) {
      SetSpeed(Vector2{GetSpeed().x, GetSpeed().y - blockSpeed * GetSpeed().y});
    }
    if(GetX() <= 15 && canCollide) {
      SetSpeed(Vector2{GetSpeed().x - blockSpeed * GetSpeed().x, GetSpeed().y});
    }

    if(GetX() > screenWidth || GetX() < -20) {
      SetPosition(GetInitialPosition());
      SetSpeed(Vector2{0.f, 0.f});
    }

    if(ballSpeed.x > 0.f && IsKeyUp(KEY_A) && IsKeyUp(KEY_D)) { ballSpeed.x -= 0.01f * ballSpeed.x; }
    if(ballSpeed.y > 0.f && IsKeyUp(KEY_W) && IsKeyUp(KEY_S)) { ballSpeed.y -= 0.01f * ballSpeed.y; }
}

void Ball::SetPosition(Vector2 position) {
  ballPos = {position.x, position.y};
}

float Ball::GetX() {
  return ballPos.x;
}

float Ball::GetY() {
  return ballPos.y;
}

Vector2 Ball::GetSpeed() {
  return ballSpeed;
}

Vector2 Ball::GetInitialPosition() {
  return ballInitialPos;
}
