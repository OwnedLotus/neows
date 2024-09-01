#include "Diameter.hpp"
#include "nlohmann/json.hpp"
#include <iostream>

using json = nlohmann::json;

Diameter::Diameter(json diameter_json) {
  std::cout << diameter_json << '\n';
  std::cout << "start Diameter" << '\n';
  auto kilometers = diameter_json["kilometers"];
  this->kilometer_min_max = std::tuple(kilometers["estimated_diameter_min"],
                                       kilometers["estimated_diameter_max"]);
  std::cout << "set kilo" << '\n';
  auto meters = diameter_json["meters"];
  this->meter_min_max = std::tuple(meters["estimated_diameter_min"],
                                   meters["estimated_diameter_max"]);
  std::cout << "set meter" << '\n';
  auto miles = diameter_json["miles"];
  this->miles_min_max = std::tuple(miles["estimated_diameter_min"],
                                   miles["estimated_diameter_max"]);
  std::cout << "set mile" << '\n';
  auto feet = diameter_json["feet"];
  this->feet_min_max = std::tuple(feet["estimated_diameter_min"],
                                  feet["estimated_diameter_max"]);
  std::cout << "set feet" << '\n';
}

void Diameter::DisplayDiameter() {
  std::cout << "Kilometer: min " << std::get<0>(this->kilometer_min_max)
            << ", max " << std::get<1>(this->kilometer_min_max) << '\n';
  std::cout << "Meter: min " << std::get<0>(this->kilometer_min_max) << ", max "
            << std::get<1>(this->kilometer_min_max) << '\n';
  std::cout << "Mile: min " << std::get<0>(this->kilometer_min_max) << ", max "
            << std::get<1>(this->kilometer_min_max) << '\n';
  std::cout << "Feet: min " << std::get<0>(this->kilometer_min_max) << ", max "
            << std::get<1>(this->kilometer_min_max) << '\n';
}

Diameter::~Diameter() {}
