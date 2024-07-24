#include "Neo.hpp"
#include "raylib.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

int main() {
  std::ifstream f("data/sample.json");
  json data = json::parse(f);

  json links = data["links"];
  json pages = data["page"];
  json neos_data = data["near_earth_objects"];

  std::cout << links << '\n';

  int json_size = pages["size"];
  std::cout << "Size: " << json_size << '\n';
  int elements = pages["total_elements"];
  std::cout << "Total Elements: " << elements << '\n';
  int total_pages = pages["total_pages"];
  std::cout << "Total Pages: " << total_pages << '\n';

  std::vector<Neo> neo_collection;

  for (int i = 0; i < json_size; i++) {
    json neo_data = neos_data[i];
    Neo n(neo_data["id"], neo_data["neo_reference_id"]);
  }
}
