#include "ball.h"

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
