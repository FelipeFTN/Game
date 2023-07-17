#include "ball.h"

float Ball::GetX() {
  return ballPos.x;
}

float Ball::GetY() {
  return ballPos.y;
}

float Ball::GetWidth() {
  return ball.width;
}

float Ball::GetHeight() {
  return ball.height;
}

Vector2 Ball::GetSpeed() {
  return ballSpeed;
}

int Ball::GetScore() {
  return score;
}

Vector2 Ball::GetInitialPosition() {
  return ballInitialPos;
}

Rectangle Ball::GetCollisionRec() {
  return Rectangle{GetX(), GetY(), GetWidth(), GetHeight()};
}
