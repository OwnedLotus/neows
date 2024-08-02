#include "Neo.hpp"
#include "raylib.h"
#include <nlohmann/json.hpp>
#include <vector>

int main() {
  std::vector<Neo> neos;
  Neo::GetNeosDebug(neos);

  for (auto neo : neos) {
    neo.DisplayNeo();
  }

  const int screenWidth = 800;
  const int screenHeigh = 450;

  InitWindow(screenWidth, screenHeigh, "Neows");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // Update Cycle

    // Draw Cycle
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20,
             LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
