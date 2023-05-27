#include "raylib.h"

class Map {
public:
  Map();

public:
  void Draw();
  void Wall(Rectangle *wall, bool active);
  void HideWall(Rectangle *wall);

private:
  Texture2D background = LoadTexture("assets/map.png");
  int wall_index;
};
