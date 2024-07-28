#include "Neo.hpp"
#include "httplib.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using json = nlohmann::json;

Neo::Neo(std::string _id, std::string _neo_id) {
  id = _id;
  neo_ref_id = _neo_id;
}

Neo::~Neo() {}

void Neo::SetName(std::string n) { name = n; }
void Neo::SetLimitedName(std::string n) { name_lim = n; }
void Neo::SetDesignation(std::string d) { designation = d; }
void Neo::SetLink(std::string l) { link = l; }
void Neo::SetMagnitude(float m) { absolute_magnitude_h = m; }
void Neo::SetDiameter() {}
void Neo::SetHazardous(bool h) { is_hazardous = h; }

std::vector<Neo> Neo::GetNeosDebug() {
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

    n.SetName(neo_data["name"]);
    n.SetLimitedName(neo_data["name_limited"]);
    n.SetDesignation(neo_data["designation"]);
    n.SetLink(neo_data["nasa_jpl_url"]);

    n.DisplayNeo();
    neo_collection.push_back(n);
  }
  return neo_collection;
}

void Neo::DisplayNeo() {
  std::cout << "Id: " << this->GetID() << '\n';
  std::cout << "Referenced Id: " << this->GetNeoID() << '\n';
  std::cout << "Name: " << this->GetName() << '\n';
  std::cout << "Limited Name: " << this->GetLimitedName() << '\n';
  std::cout << "Link: " << this->GetLink() << '\n';
}

std::string Neo::GetID() { return id; }
std::string Neo::GetNeoID() { return neo_ref_id; }
std::string Neo::GetName() { return name; }
std::string Neo::GetLimitedName() { return name_lim; }
std::string Neo::GetDesignation() { return designation; }
std::string Neo::GetLink() { return link; }
float Neo::GetMagnitude() { return absolute_magnitude_h; }
bool Neo::GetHazardous() { return is_hazardous; }
