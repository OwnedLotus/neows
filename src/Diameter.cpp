#include "Diameter.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

Diameter::Diameter(json diameter_json) {
  auto kilometers = diameter_json["kilometers"];
  this->kilometer_min_max = std::tuple(kilometers["estimated_diameter_min"],
                                       kilometers["estimated_diameter_max"]);
  auto meters = diameter_json["meters"];
  this->meter_min_max = std::tuple(meters["estimated_diameter_min"],
                                   meters["estimated_diameter_max"]);
  auto miles = diameter_json["miles"];
  this->miles_min_max = std::tuple(miles["estimated_diameter_min"],
                                   miles["estimated_diameter_max"]);
  auto feet = diameter_json["feet"];
  this->feet_min_max = std::tuple(feet["estimated_diameter_min"],
                                  feet["estimated_diameter_max"]);
}

void Diameter::DisplayDiameter() {}

Diameter::~Diameter() {}
