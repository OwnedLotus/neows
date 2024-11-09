#include "NeosCurrier.hpp"
#include "Neo.hpp"
#include <cmath>
#include <raylib.h>
#include <tuple>
#include <vector>
#include <iostream>

NeosCurrier::NeosCurrier(bool isDebug, Vector3 initialPosition, Model* model) {
  this->debug = isDebug;
  if (this->debug) {
    Neo::GetNeosDebug(this->neos);
  } else {
    Neo::GetNeos(this->neos);
  }

  this->asteroid_model = model;
}

void NeosCurrier::DisplayNeos() {
  for (auto neo : this->neos) {
    neo->DisplayNeo();
  }
}

void NeosCurrier::DrawNeos() {
  for (auto neo : this->neos) {
    neo->Draw(this->asteroid_model);
  }
}

void NeosCurrier::UpdateNeosPosition(double time, float startTime, double angleRadians) {
  int numObjects = this->neos.size();
  std::vector<double> angles = CalculateLineSpace(0, 2 * PI, numObjects);

  for (int i = 0; i < numObjects; i++) {
    float x = radius;
    float z = radius;

    // rotation
    x = x * cos(angles[i] + angleRadians * time) - z * sin(angles[i] + angleRadians * time);
    z = z * sin(angles[i] + angleRadians * time) + z * cos(angles[i] + angleRadians * time);
    float y = sin(time) * (z + x) / 2;

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

void NeosCurrier::DeleteAllNeos() {
  for (auto neo : this->neos) {
    delete neo;
  }
}

void NeosCurrier::DeleteSelectedNeo(std::string id) {
  Neo* neoToBeDeleted = nullptr;

  for (auto neo: this->neos) {
    if(neo->GetID() == id) {
      neoToBeDeleted = neo;
    }
  }

  if(neoToBeDeleted != nullptr) {
    std::cout << "Neo: " << id << " Successfully Deleted" << "\n";
    delete neoToBeDeleted;
    return;
  }

    std::cout << "Failed to Delete Neo: " << id;
}

NeosCurrier::~NeosCurrier() {
  this->DeleteAllNeos();
}
