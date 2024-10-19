#include "NeosCurrier.hpp"
#include "Neo.hpp"
#include <cmath>
#include <iostream>
#include <raylib.h>
#include <vector>

NeosCurrier::NeosCurrier(bool isDebug, Vector3 initialPosition) {
  this->debug = isDebug;
  if (this->debug) {
    Neo::GetNeosDebug(this->neos);
  } else {
    Neo::GetNeos(this->neos);
  }
}

void NeosCurrier::DisplayNeos() {
  for (auto neo : this->neos) {
    neo->DisplayNeo();
  }
}

void NeosCurrier::DrawNeos() {
  for (auto neo : this->neos) {
    neo->Draw();
  }
}

void NeosCurrier::UpdateNeosPosition(float deltaTime, float startTime) {
  int num_objects = this->neos.size();
  float y_coord = 0;
  std::vector<double> angles = CalculateLineSpace(0, 2 * PI, num_objects);
  std::cout << deltaTime << '\n';

  for (int i = 0; i < num_objects; i++) {
    float x = radius * cos(angles[i]);
    float z = radius * sin(angles[i]);
    float y = y_coord;
   this->neos[i]->SetRenderPosition((Vector3){x,y,z}); 
  }
}

std::vector<double> NeosCurrier::CalculateLineSpace(double start, double end, int num) {
  std::vector<double> linespace;
  if (num == 0) return linespace;
  if (num == 1) {
    linespace.push_back(start);
    return linespace;
  }

  double delta = (end - start) / (num - 1);
  for (int i = 0; i < num; i++) {
    linespace.push_back(start + delta * i);
  }

  return linespace;
}

NeosCurrier::~NeosCurrier() {
  for (auto neo : this->neos) {
    delete neo;
  }
}
