#include "NeosCurrier.hpp"
#include "Neo.hpp"
#include <vector>

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
    neo.DisplayNeo();
  }
}
