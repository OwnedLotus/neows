#pragma once
#include "Neo.hpp"
#include <raylib.h>
#include <vector>

class NeosCurrier {
public:
  NeosCurrier(bool isDebug, Vector3 initialPosition);
  NeosCurrier(NeosCurrier &&) = default;
  NeosCurrier(const NeosCurrier &) = default;
  NeosCurrier &operator=(NeosCurrier &&) = default;
  NeosCurrier &operator=(const NeosCurrier &) = default;
  ~NeosCurrier();

  void DisplayNeos();
  void DrawNeos();
  void UpdateNeosPosition(float deltaTime, float startTime);
  std::vector<double> CalculateLineSpace(double start, double end, int num);

private:
  std::vector<Neo *> neos;
  bool debug;
  int radius = 15;
};
