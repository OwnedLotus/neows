#pragma once
#include <nlohmann/json.hpp>
#include <tuple>

using json = nlohmann::json;

class Diameter {
public:
  Diameter(json diameter_json);
  Diameter(Diameter &&) = default;
  Diameter(const Diameter &) = default;
  Diameter &operator=(Diameter &&) = default;
  Diameter &operator=(const Diameter &) = default;
  ~Diameter();

  std::tuple<double, double> GetKilo() { return kilometer_min_max; }
  std::tuple<double, double> GetMeter() { return meter_min_max; }
  std::tuple<double, double> GetMiles() { return miles_min_max; }
  std::tuple<double, double> GetFeet() { return feet_min_max; }

  void SetKilo(double min, double max) {
    this->kilometer_min_max = std::make_tuple(min, max);
  }
  void SetMeter(double min, double max) {
    this->meter_min_max = std::make_tuple(min, max);
  }
  void SetMiles(double min, double max) {
    this->miles_min_max = std::make_tuple(min, max);
  }
  void SetFeet(double min, double max) {
    this->feet_min_max = std::make_tuple(min, max);
  }

  void DisplayDiameter();

private:
  std::tuple<double, double> kilometer_min_max;
  std::tuple<double, double> meter_min_max;
  std::tuple<double, double> miles_min_max;
  std::tuple<double, double> feet_min_max;
};
