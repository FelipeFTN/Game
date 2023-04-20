#include "ball.h"

Ball::Ball(int sWidth, int sHeight) {
  screenWidth = sWidth;
  screenHeight = sHeight;
}

void Ball::Draw() {
  DrawTexturePro(ball, sourceRec, destRec, origin, 0.f, WHITE);
}
