#include "raylib.h"

class Map {
public:
  Map();

public:
  void DrawMap(int screenWidth, int screenHeight);
  void Wall(Rectangle *wall, bool active);
  void WallControl(int *wallTime, bool *show_wall_0, bool *show_wall_1, bool gameover);
  void HideWall(Rectangle *wall);
  void ShowWall(Rectangle *wall);

private:
  Texture2D background = LoadTexture("assets/map.png");
  int wall_index;
  int sw;
  int sh;
};
