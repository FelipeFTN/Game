#include "ball.h"

Ball::Ball(int sWidth, int sHeight, int x, int y, int instanceId) {
  screenWidth = sWidth;
  screenHeight = sHeight;
  ballPos = {(float)x, (float)y};
  ballInitialPos = {(float)x, (float)y};
  id = instanceId;
}

void Ball::Draw() {
  DrawTextureRec(ball, ballRec, ballPos, WHITE);
}

void Ball::Move(float deltaTime) {
  // Movement
  ballPos.x += ballSpeed.x * deltaTime;
  ballPos.y += ballSpeed.y * deltaTime;

  // Key pressing
  if(id == 0){
    if(IsKeyDown(KEY_W)) {
      ballSpeed.y -= ballAcceleration; 
    } else if(IsKeyDown(KEY_S)) {
      ballSpeed.y += ballAcceleration; 
    } else if(IsKeyDown(KEY_A)) {
      ballSpeed.x -= ballAcceleration; 
    } else if(IsKeyDown(KEY_D)) {
      ballSpeed.x += ballAcceleration; 
    }
  } else if(id == 1){
    if(IsKeyDown(KEY_UP)) {
      ballSpeed.y -= ballAcceleration; 
    } else if(IsKeyDown(KEY_DOWN)) {
      ballSpeed.y += ballAcceleration; 
    } else if(IsKeyDown(KEY_LEFT)) {
      ballSpeed.x -= ballAcceleration; 
    } else if(IsKeyDown(KEY_RIGHT)) {
      ballSpeed.x += ballAcceleration; 
    }
  } 
}

void Ball::Collision(Ball ball) {
  // Collisions againt walls
  float blockSpeed = 2.f;

  if(GetY() >= 110.f && GetY() <= screenHeight - 125.f) {
    canCollide = false;
  } else { canCollide = true; }

  if(GetX() >= screenWidth - GetWidth() - GetWidth()/2.f && canCollide) {
    SetSpeed(Vector2{GetSpeed().x - blockSpeed * GetSpeed().x, GetSpeed().y});
  }                                         // change to Width if u have any error
  if(GetY() >= screenHeight - GetHeight() - GetHeight()/2.f && canCollide) {
    SetSpeed(Vector2{GetSpeed().x, GetSpeed().y - blockSpeed * GetSpeed().y});
  }
  if(GetY() <= 15 && canCollide) {
    SetSpeed(Vector2{GetSpeed().x, GetSpeed().y - blockSpeed * GetSpeed().y});
  }
  if(GetX() <= 15 && canCollide) {
    SetSpeed(Vector2{GetSpeed().x - blockSpeed * GetSpeed().x, GetSpeed().y});
  }

  if(GetX() > screenWidth || GetX() < - 20) {
    SetPosition(GetInitialPosition());
    SetSpeed(Vector2{0.f, 0.f});
  }

  if(ballSpeed.x > 0.f && IsKeyUp(KEY_A) && IsKeyUp(KEY_D)) { ballSpeed.x -= 0.01f * ballSpeed.x; }
  if(ballSpeed.y > 0.f && IsKeyUp(KEY_W) && IsKeyUp(KEY_S)) { ballSpeed.y -= 0.01f * ballSpeed.y; }

  // Collisons again ball
}
