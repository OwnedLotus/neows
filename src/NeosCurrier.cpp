#include "raylib.h"
#include <iostream>

#include "NeosCurrier.hpp"
#include "Neo.hpp"

NeosCurrier::NeosCurrier(bool isDebug) {
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

void NeosCurrier::RenderNeos() {
}

NeosCurrier::~NeosCurrier() {
  for (auto neo : this->neos) {
    std::cout << "Deleted Neo: " << neo->GetID() << '\n';
    delete neo;
  
  }
}
