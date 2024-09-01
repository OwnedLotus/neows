#include "Diameter.hpp"
#include "nlohmann/json.hpp"
#include <iomanip>
#include <iostream>

using json = nlohmann::json;

Diameter::Diameter(json diameter_json) {
  auto kilometers = diameter_json["kilometers"];
  auto meters = diameter_json["meters"];
  auto miles = diameter_json["miles"];
  auto feet = diameter_json["feet"];

  this->kilometer_min_max = std::tuple(kilometers["estimated_diameter_min"],
                                       kilometers["estimated_diameter_max"]);
  this->meter_min_max = std::tuple(meters["estimated_diameter_min"],
                                   meters["estimated_diameter_max"]);
  this->miles_min_max = std::tuple(miles["estimated_diameter_min"],
                                   miles["estimated_diameter_max"]);
  this->feet_min_max = std::tuple(feet["estimated_diameter_min"],
                                  feet["estimated_diameter_max"]);
}

void Diameter::DisplayDiameter() {
  std::cout << std::setprecision(15);
  std::cout << "Kilometer: min " << std::get<0>(this->kilometer_min_max)
            << ", max " << std::get<1>(this->kilometer_min_max) << '\n';
  std::cout << "Meter: min " << std::get<0>(this->meter_min_max) << ", max "
            << std::get<1>(this->meter_min_max) << '\n';
  std::cout << "Mile: min " << std::get<0>(this->miles_min_max) << ", max "
            << std::get<1>(this->miles_min_max) << '\n';
  std::cout << "Feet: min " << std::get<0>(this->feet_min_max) << ", max "
            << std::get<1>(this->feet_min_max) << '\n';
}

Diameter::~Diameter() {}
