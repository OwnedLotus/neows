#include <iostream>
#include "Neo.hpp"
#include "NeosCurrier.hpp"
#include <cmath>
#include <raylib.h>

#include <nlohmann/json.hpp>

int main(void) {

  const int screenWidth = 800;
  const int screenHeigh = 450;
  InitWindow(screenWidth, screenHeigh, "NEOws Display");

  Camera3D camera = {0};
  camera.position = (Vector3){15.0f, 15.0f, 15.0f}; // Camera position
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};      // Camera looking at point
  camera.up = (Vector3){0.0f, 1.0f, 0.0f}; // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;             // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;
  Vector3 earthPosition = {0.0, 0.0, 0.0};
  float startTime = GetTime();

  Model asteroidModel = LoadModel("assets/Asteroid.glb");

  auto currier = new NeosCurrier(true, (Vector3) {15, 0, 0}, &asteroidModel);

  DisableCursor();

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // Update Cycle
    UpdateCamera(&camera, CAMERA_FREE);
    currier->UpdateNeosPosition(GetTime(), startTime, 0.5);

    // Draw Cycle
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(camera);

    //DrawModel(earthModel, earthPosition, 10.0, WHITE);
    DrawSphere(earthPosition, 5, GREEN);
    //DrawCubeWires(earth_position, 20.0f, 20.0f, 20.0f, MAROON);
    currier->DrawNeos();

    //DrawSphere((Vector3){-7,7,7}, 2.0, BROWN);
    DrawLine3D((Vector3) {0,0,0}, (Vector3) {20,0,0}, RED);
    DrawLine3D((Vector3) {0,0,0}, (Vector3) {0,20,0}, GREEN);
    DrawLine3D((Vector3) {0,0,0}, (Vector3) {0,0,20}, BLUE);

    //DrawGrid(20, 1.0f);

    EndMode3D();
/*
    DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(10, 10, 320, 93, BLUE);

    DrawText("Free camera default controls:", 20, 20, 10, BLACK);
    DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
    DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY);
    */

    EndDrawing();
  }

  CloseWindow();
  //UnloadModel(earthModel);
  UnloadModel(asteroidModel);

  delete currier;

  return 0;
}
