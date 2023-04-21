#include "ball.h"

Ball::Ball(int sWidth, int sHeight) {
  screenWidth = sWidth;
  screenHeight = sHeight;
}

void Ball::Draw() {
  DrawTextureRec(ball, ballRec, ballPos, WHITE);
}
