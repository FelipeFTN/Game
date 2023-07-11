#include "map.h"

#include <string>

Map::Map() { }

void Map::DrawMap(int screenWidth, int screenHeight) {
  sw = screenWidth;
  sh = screenHeight;
  DrawTextureEx(background, (Vector2){ 0.0f, 0.0f }, 0.0f, 8.0f, WHITE);
}

void Map::WallControl(int *wallTime, bool *show_wall_0, bool *show_wall_1) {
  *wallTime += 1;
  if (*wallTime == 600) {
    *show_wall_0 = *show_wall_0 ? false : true;
    *show_wall_1 = *show_wall_1 ? false : true;
    *wallTime = 0;
  }
}

void Map::Wall(Rectangle *wall, bool active) {
  if (wall->x < sw / 2.f) { wall_index = 0; } else { wall_index = 1; }
  if (!active) { Map::HideWall(wall); } else { Map::ShowWall(wall); }
  DrawRectangleRec(*wall, DARKGRAY);
}

void Map::HideWall(Rectangle *wall) {
  // sw = Screen Width
  if (wall_index == 0 && wall->x > -100.f) {
    wall->x += -.1;
  } else if (wall_index == 1 && wall->x < sw) {
    wall->x += .1;
  }
}

void Map::ShowWall(Rectangle *wall) {
  // sw = Screen Width
  if (wall_index == 0 && wall->x <= -84.f) {
    wall->x += .1;
  } else if (wall_index == 1 && wall->x > sw - 16) {
    wall->x += -.1;
  }
}
