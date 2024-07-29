#include "Neo.hpp"
#include <nlohmann/json.hpp>
#include <vector>

int main() {
  std::vector<Neo> neos;
  Neo::GetNeosDebug(neos);

  for (auto neo : neos) {
    neo.DisplayNeo();
  }
}
