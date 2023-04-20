#include "map.h"

Map::Map() { }

void Map::Draw() {
  DrawTextureEx(background, (Vector2){ 0.0f, 0.0f }, 0.0f, 8.0f, WHITE);
}
