#pragma once
#include "Neo.hpp"
#include <ctime>
#include <memory>
#include <raylib.h>
#include <vector>

enum AsteroidState { Active, None };

class NeosCurrier {
public:
  NeosCurrier(bool isDebug, std::shared_ptr<Model> model);
  NeosCurrier(NeosCurrier &&) = default;
  NeosCurrier(const NeosCurrier &) = default;
  NeosCurrier &operator=(NeosCurrier &&) = default;
  NeosCurrier &operator=(const NeosCurrier &) = default;
  ~NeosCurrier();

  std::vector<std::shared_ptr<Neo>> GetNeoCollection();
  std::shared_ptr<Neo> GetSelectedNeo();

  void DeleteAllNeos();
  void DeleteSelectedNeo(std::string id);

  void InjestJsonDataOffline(nlohmann::json data);
  void InjestJsonData(nlohmann::json data);

  void DisplayNeos();
  void DrawNeos();
  void DrawSelectedNeoPointer();

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
  std::shared_ptr<Model> asteroid_model;
  int number_elements;
  int number_pages;
  int render_index = 0;
  AsteroidState state = AsteroidState::None;
};
