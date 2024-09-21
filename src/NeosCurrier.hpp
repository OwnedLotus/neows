#pragma once
#include "Neo.hpp"
#include <vector>

class NeosCurrier {
public:
  NeosCurrier(bool isDebug);
  NeosCurrier(NeosCurrier &&) = default;
  NeosCurrier(const NeosCurrier &) = default;
  NeosCurrier &operator=(NeosCurrier &&) = default;
  NeosCurrier &operator=(const NeosCurrier &) = default;
  ~NeosCurrier();

  void DisplayNeos();
  void RenderNeos();

private:
  std::vector<Neo *> neos;
  bool debug;
};
