#include "NeosCurrier.hpp"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <raylib.h>

#include <nlohmann/json.hpp>
#include <httplib.h>
#include <string>

void get_api_keys(std::string& k, std::string& v);

int main(void) {
  std::string base_url = "https://api.nasa.gov";
  std::string path = "/neo/rest/v1/feed?start_date=2015-09-07&end_date=2015-09-08&api_key=";

  std::string key;
  std::string value;

  get_api_keys(key, value);

  const int screenWidth = 1280;
  const int screenHeigh = 720;
  InitWindow(screenWidth, screenHeigh, "NEOws Display");

  Camera3D camera = {0};
  camera.position = (Vector3){20.0f, 20.0f, 20.0f}; // Camera position
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};      // Camera looking at point
  camera.up = (Vector3){0.0f, 1.0f, 0.0f}; // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;             // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;
  Vector3 earthPosition = {0.0, 0.0, 0.0};
  float startTime = GetTime();
  
  std::cout << "start load asteroid" << '\n';
  Model asteroidModel = LoadModel("assets/Asteroid.glb");

  auto currier = new NeosCurrier(true, &asteroidModel);

  bool debug = true;
  if (debug)
    path += "DEMO_KEY";
  else
   path += value;

  // Hanging loading of program
  //currier->ReachAPI(base_url, path);
  
  DisableCursor();

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // Update Cycle
    UpdateCamera(&camera, CAMERA_FREE);
    currier->UpdateNeosPosition(GetTime(), startTime, 0.5);
    currier->ChangeFocusAsteroid();

    // Draw Cycle
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(camera);

    DrawSphere(earthPosition, 5, GREEN);
    currier->DrawNeos();
    currier->DrawSelectedNeoPointer();

    DrawLine3D((Vector3) {0,0,0}, (Vector3) {20,0,0}, RED);
    DrawLine3D((Vector3) {0,0,0}, (Vector3) {0,20,0}, GREEN);
    DrawLine3D((Vector3) {0,0,0}, (Vector3) {0,0,20}, BLUE);

    DrawGrid(20, 1.0f);

    EndMode3D();

    currier->DrawSelectedNeoInfo();

    EndDrawing();
  }

  CloseWindow();
  //UnloadModel(earthModel);
  UnloadModel(asteroidModel);

  delete currier;

  return 0;
}

void get_api_keys(std::string& k, std::string& v) {
  std::string outputstr;
  std::ifstream env_file(".env");
  if (env_file.is_open()) {
    env_file >> outputstr;
  }

  std::string delimiter = "=";
  k = outputstr.substr(0, outputstr.find(delimiter));
  v = outputstr.substr(outputstr.find(delimiter) + 1, outputstr.length());
}
