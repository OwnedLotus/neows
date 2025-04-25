#pragma once
#include "Neo.hpp"
#include <cmath>
#include <ctime>
#include <memory>
#include <raylib.h>
#include <vector>

using json = nlohmann::json;

enum AsteroidState { Active, None };

class NeosCurrier {
public:
  NeosCurrier(bool isDebug, Model *model);
  NeosCurrier(NeosCurrier &&) = default;
  NeosCurrier(const NeosCurrier &) = default;
  NeosCurrier &operator=(NeosCurrier &&) = default;
  NeosCurrier &operator=(const NeosCurrier &) = default;
  ~NeosCurrier();

  void DeleteAllNeos();
  void DeleteSelectedNeo(std::string id);

  void InjestJsonDataOffline(json data);
  void InjestJsonData(json data);

  void DisplayNeos();
  void DrawNeos();
  void DrawSelectedNeoPointer();
  void DrawSelectedNeoInfo();

  void UpdateNeosPosition(double time, float startTime, double angleRadians);
  std::vector<double> CalculateLineSpace(double start, double end, int num);
  void ReachAPI(std::string url, std::string req);
  void GetNeosDebugOffline();

  void ChangeFocusAsteroid();

private:
  std::string links;
  std::string pages;
  std::tuple<std::time_t, std::time_t> timespan;
  std::vector<std::shared_ptr<Neo>> neos;
  bool offline;
  int radius = 15;
  Model *asteroid_model;
  int number_elements;
  int number_pages;
  int render_index = 0;
  AsteroidState state = AsteroidState::None;
};
