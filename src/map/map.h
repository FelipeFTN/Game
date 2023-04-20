#include "raylib.h"

class Map {
  public:
    Map();
    void Draw();

  private:
  Texture2D background = LoadTexture("assets/map.png");
};
