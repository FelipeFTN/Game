#include "ball.h"
#include <string>

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
  ballPos.x += GetSpeed().x * deltaTime;
  ballPos.y += GetSpeed().y * deltaTime;

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

void Ball::Collision(Ball *ball, bool wall_0, bool wall_1) {
  // Collisions againt walls (oppened or closed)
  if (GetY() >= 110.f && GetY() <= screenHeight - 125.f) {
    canCollide = true;
    if (GetX() < screenWidth/2.f && !wall_0) {
      canCollide = false;
    } else if (GetX() > screenWidth/2.f && !wall_1) {
      canCollide = false;
    }
  } else { canCollide = true; }

  if (GetX() >= screenWidth - GetWidth() - GetWidth()/2.f && canCollide) {
    SetSpeed(Vector2{GetSpeed().x * - 1, GetSpeed().y});
  }
  if (GetY() >= screenHeight - GetHeight() - GetHeight()/2.f && canCollide) {
    SetSpeed(Vector2{GetSpeed().x, GetSpeed().y * - 1});
  }
  if (GetY() <= 15 && canCollide) {
    SetSpeed(Vector2{GetSpeed().x, GetSpeed().y * - 1});
  }
  if (GetX() <= 15 && canCollide) {
    SetSpeed(Vector2{GetSpeed().x * - 1, GetSpeed().y});
  }

  if (GetX() > screenWidth || GetX() < - 20) {
    SetPosition(GetInitialPosition());
    SetSpeed(Vector2{0.f, 0.f});
  }
  if (GetY() > screenHeight || GetY() < - 20) {
    SetPosition(GetInitialPosition());
    SetSpeed(Vector2{0.f, 0.f});
  }

  if (GetSpeed().x > 0.f || GetSpeed().x < 0.f && IsKeyUp(KEY_A) && IsKeyUp(KEY_D)) { ballSpeed.x -= stopDragSpeed * GetSpeed().x; }
  if (GetSpeed().y > 0.f || GetSpeed().y < 0.f && IsKeyUp(KEY_W) && IsKeyUp(KEY_S)) { ballSpeed.y -= stopDragSpeed * GetSpeed().y; }

  // Collisons again ball
  if (CheckCollisionRecs(GetCollisionRec(), ball->GetCollisionRec())) {
    if (GetY() + GetHeight() >= ball->GetY()) {
      ball->SetSpeed(Vector2{ball->GetSpeed().x, GetSpeed().y - ball->GetSpeed().y});
    } 
    if (GetX() + GetWidth() >= ball->GetX()) {
      ball->SetSpeed(Vector2{GetSpeed().x - ball->GetSpeed().x, ball->GetSpeed().y});
    }
  }
}
