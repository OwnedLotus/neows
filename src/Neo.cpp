#include "Neo.hpp"
#include "Diameter.hpp"
#include "nlohmann/json.hpp"
#include "raylib.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json_fwd.hpp>
#include <raylib.h>
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
void Neo::SetHazardous(bool h) { is_hazardous = h; }
void Neo::SetDiameter(json diameter_json) {
  if (this->diameter == nullptr) {
    this->diameter = new Diameter(diameter_json);
  } else {
    delete this->diameter;
    this->diameter = new Diameter(diameter_json);
  }
}
void Neo::SetCloseApproach(json close_approach_json) {
  std::cout << "-----Next Asteroid-----" << '\n';
  for (json::iterator it = close_approach_json.begin();
       it != close_approach_json.end(); it++) {
    // this->close_approach.push_back(new CloseApproach(*it));
  }
}

std::string Neo::GetID() { return id; }
std::string Neo::GetNeoID() { return neo_ref_id; }
std::string Neo::GetName() { return name; }
std::string Neo::GetLimitedName() { return name_lim; }
std::string Neo::GetDesignation() { return designation; }
std::string Neo::GetLink() { return link; }
float Neo::GetMagnitude() { return absolute_magnitude_h; }
bool Neo::GetHazardous() { return is_hazardous; }
Diameter &Neo::GetDiameter() { return *this->diameter; }

// implement httplib get query when I have obtained the key from
std::vector<Neo> &Neo::GetNeos(std::vector<Neo> &neos) { return neos; }

std::vector<Neo> &Neo::GetNeosDebug(std::vector<Neo> &neos) {
  std::ifstream f("data/sample.json");
  json data = json::parse(f);
  return InjestJsonData(data, neos);
}

void Neo::DisplayNeo() {
  std::cout << "Id: " << this->GetID() << '\n';
  std::cout << "Referenced Id: " << this->GetNeoID() << '\n';
  std::cout << "Name: " << this->GetName() << '\n';
  std::cout << "Limited Name: " << this->GetLimitedName() << '\n';
  std::cout << "Link: " << this->GetLink() << '\n';
  this->diameter->DisplayDiameter();

  for (auto n : this->close_approach) {
    n->PrintCloseApproach();
  }

  std::cout << "Sentry Object: " << (this->is_sentry_oject ? "True" : "False")
            << '\n';

  std::cout << '\n';
}

std::vector<Neo> &Neo::InjestJsonData(json data, std::vector<Neo> &neos) {
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

  for (int i = 0; i < json_size; i++) {
    json neo_data = neos_data[i];
    Neo n(neo_data["id"], neo_data["neo_reference_id"]);

    n.SetName(neo_data["name"]);
    n.SetLimitedName(neo_data["name_limited"]);
    n.SetDesignation(neo_data["designation"]);
    n.SetLink(neo_data["nasa_jpl_url"]);

    n.SetDiameter(neo_data["estimated_diameter"]);
    n.SetCloseApproach(neo_data["close_approach_data"]);

    n.is_sentry_oject = neo_data["is_sentry_object"];

    neos.push_back(n);
  }

  return neos;
}

// the render radius should be based on the diameter that is recieved from
// the query from the api
void Neo::DrawNeo() { DrawCircleV(this->position, this->render_radius, BROWN); }

void Neo::SplitStringData(std::vector<std::string> &parsed_data, json data,
                          std::string delimiter) {}
