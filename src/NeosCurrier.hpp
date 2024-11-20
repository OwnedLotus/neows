#pragma once
#include "Neo.hpp"
#include <raylib.h>
#include <vector>

using json = nlohmann::json;

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
  std::vector<Neo *> neos;
  bool offline;
  int radius = 15;
  Model *asteroid_model;
  int number_elements;
  int number_pages;
  int render_index = 0;
};
