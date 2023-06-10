#include "map.h"

#include <string>

Map::Map() { }

void Map::DrawMap() {
  DrawTextureEx(background, (Vector2){ 0.0f, 0.0f }, 0.0f, 8.0f, WHITE);
}

void Map::Wall(Rectangle *wall, bool active) {
  if (!active) { Map::HideWall(wall); }
  DrawRectangleRec(*wall, DARKGRAY);
}

void Map::HideWall(Rectangle *wall) {
  if (wall->x < background.width / 2.f) { wall_index = 0; } else { wall_index = 1; }

  if (wall_index == 0 && wall->x > -100.f) {
    wall->x += -.1;
  } else if (wall_index == 1 && wall->x > background.width) {
    wall->x += .1;
  }
}
