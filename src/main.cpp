#include "NeosCurrier.hpp"
#include <cmath>
#include <iostream>
#include <raylib.h>

#include <nlohmann/json.hpp>

int main(void) {
  SetTraceLogLevel(LOG_DEBUG);
  auto currier = new NeosCurrier(true, (Vector3) {15, 0, 0});
  // currier->DisplayNeos();

  const int screenWidth = 800;
  const int screenHeigh = 450;
  InitWindow(screenWidth, screenHeigh, "Neows");

  std::cout << "Loading Earth Model" << '\n';
  Model earthModel = LoadModel("assets/low_poly_earth.glb");
  std::cout << "Finished Loading Model" << '\n';

  Camera3D camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f}; // Camera position
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};      // Camera looking at point
  camera.up =
      (Vector3){0.0f, 1.0f, 0.0f}; // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;             // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE; // Camera projection type
  Vector3 cube_position = {0.0, 0.0, 0.0};
  float startTime = GetTime();

  currier->InitNeoPositions();

  DisableCursor();

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // Update Cycle
    UpdateCamera(&camera, CAMERA_FREE);
    currier->UpdateNeosPosition(GetFrameTime(), startTime);

    if (IsKeyPressed('z'))
      camera.target = (Vector3){0.0, 0.0, 0.0};

    // Draw Cycle
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    // DrawModel(earthModel, cube_position, 10.0, WHITE);
    DrawSphere(cube_position, 10, GREEN);
    //DrawSphere((Vector3){15, 0, 0}, 1, BROWN);
    DrawCubeWires(cube_position, 20.0f, 20.0f, 20.0f, MAROON);
    currier->RenderNeos();

    DrawGrid(20, 1.0f);

    EndMode3D();

    DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(10, 10, 320, 93, BLUE);

    DrawText("Free camera default controls:", 20, 20, 10, BLACK);
    DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
    DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();
  UnloadModel(earthModel);

  delete currier;

  return 0;
}
