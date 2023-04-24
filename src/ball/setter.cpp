#include "ball.h"

void Ball::SetPosition(Vector2 position) {
  ballPos = {position.x, position.y};
}

void Ball::SetSpeed(Vector2 speed) {
  ballSpeed = {speed.x, speed.y};
}

void Ball::SetAcceleration(float acceleration) {
  ballAcceleration = acceleration;
}
