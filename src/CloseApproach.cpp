#include "CloseApproach.hpp"
#include "nlohmann/json.hpp"
#include <iostream>

using json = nlohmann::json;

CloseApproach::CloseApproach(json close_approach_json) {
  std::cout << close_approach_json << '\n';
  auto date = close_approach_json[0];
  this->close_approach_date = date["close_approach_date"];
  this->close_approach_date_full = date["close_approach_date_full"];
  this->epoch_date_close_approach = date["epoch_date_close_approach"];
  std::cout << "set date" << '\n';

  auto relative_velocity = date["relative_velocity"];
  this->relative_vel_kps = relative_velocity["kilometers_per_second"];
  this->relative_vel_kph = relative_velocity["kilometers_per_hour"];
  this->relative_vel_mph = relative_velocity["miles_per_hour"];
  std::cout << "set vel" << '\n';

  auto miss_distance = date["miss_distance"];
  this->miss_dist_astronomical = miss_distance["astronomical"];
  this->miss_dist_lunar = miss_distance["lunar"];
  this->miss_dist_kilometer = miss_distance["kilometers"];
  this->miss_dist_miles = miss_distance["miles"];
  std::cout << "set miss" << '\n';

  this->is_sentry_object = close_approach_json["is_sentry_object"];
  std::cout << "set sentry" << '\n';
}

CloseApproach::~CloseApproach() {}
