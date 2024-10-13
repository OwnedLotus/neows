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

  this->neos[0]->SetRenderPosition(initialPosition);
}

void NeosCurrier::DisplayNeos() {
  for (auto neo : this->neos) {
    neo->DisplayNeo();
  }
}

void NeosCurrier::DrawNeos() {
  for (auto neo : this->neos) {
    neo->DrawNeo();
  }
}

void NeosCurrier::UpdateNeosPosition(float deltaTime, float startTime) {
  int num_objects = this->neos.size();
  float z_coord = 0;
  std::vector<double> angles = CalculateLineSpace(0, 2 * PI, num_objects);
  //std::cout << num_objects << '\n';

  for (int i = 0; i < num_objects; i++) {
    float x = radius * cos(angles[i]);
    float y = radius * sin(angles[i]);
    float z = z_coord;
    //std::cout << "x: "<< x << " y: " << y << " z: " << z << '\n';
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
