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
