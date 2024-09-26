#include "NeosCurrier.hpp"
#include "Neo.hpp"
#include <cmath>
#include <raylib.h>

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

void NeosCurrier::RenderNeos() {
  for (auto neo : this->neos) {
    neo->DrawNeo();
  }
}

void NeosCurrier::InitNeoPositions() {
  for (unsigned int i = 0; i < this->neos.size(); i++) {
    float t = (float) i / this->neos.size();
    float theta = t * 2 * PI;
    float phi = PI / 4;

    this->neos[i]->SetRenderPosition(CalculateNewPosition(phi, theta));
  
  }
}

void NeosCurrier::UpdateNeosPosition(float deltaTime, float startTime) {
  float currentTime = GetTime();
  float t = fmod((currentTime - startTime) / this->neos.size(), 1);

  for (unsigned int i = 0; i < this->neos.size(); i++) {
    float theta = (t * 2.0f * PI) * 2 * PI;
    float phi = PI / 4;

    this->neos[i]->SetRenderPosition(CalculateNewPosition(phi, theta));
  }
}

Vector3 NeosCurrier::CalculateNewPosition(float phi, float theta) {
   Vector3 newPos = {
      this->radius * sinf(phi) * cosf(theta),
      this->radius * cosf(phi),
      this->radius * sinf(phi) * sinf(theta)
    };

  return newPos;
}

NeosCurrier::~NeosCurrier() {
  for (auto neo : this->neos) {
    delete neo;
  }
}
