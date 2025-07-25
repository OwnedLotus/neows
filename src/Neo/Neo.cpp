#include "Neo.hpp"
#include "Diameter.hpp"
#include "raylib.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

Neo::Neo(std::string _id, std::string _neo_id) {
  id = _id;
  neo_ref_id = _neo_id;
}

Neo::~Neo() {
#ifdef DEBUG
  std::cout << "Deleted Neo: " << this->GetID() << '\n';
#endif
  this->diameter.reset();
  for (auto approach : this->close_approach) {
    approach.reset();
  }
}

void Neo::SetName(std::string n) { this->name = n; }
void Neo::SetNeoID(std::string id) { this->neo_ref_id = id; }
void Neo::SetID(std::string id) { this->id = id; }
void Neo::SetLimitedName(std::string n) { this->name_lim = n; }
void Neo::SetDesignation(std::string d) { this->designation = d; }
void Neo::SetLink(std::string l) { this->link = l; }
void Neo::SetMagnitude(float m) { this->absolute_magnitude_h = m; }
void Neo::SetHazardous(bool h) { this->is_hazardous = h; }
void Neo::SetRenderPosition(Vector3 position) { this->position = position; }
void Neo::SetRenderRadius(float r) { this->render_radius = r; }
void Neo::SetDate(std::string date) { this->date = date; }
void Neo::SetIsSentryObject(bool is_sentry) {
  this->is_sentry_oject = is_sentry;
}

void Neo::SetDiameter(nlohmann::json diameter_json) {
  if (this->diameter == nullptr) {
    this->diameter = std::make_shared<Diameter>(Diameter(diameter_json));
    return;
  }

  this->diameter.reset();
  this->diameter = std::make_shared<Diameter>(Diameter(diameter_json));
}

void Neo::SetCloseApproach(nlohmann::json close_approach_json) {
  for (nlohmann::json::iterator it = close_approach_json.begin();
       it != close_approach_json.end(); it++) {
    this->close_approach.push_back(std::make_shared<CloseApproach>(CloseApproach(*it)));
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
std::shared_ptr<Diameter> Neo::GetDiameter() { return this->diameter; }
float Neo::GetRenderRadius() { return this->render_radius; }
Vector3 Neo::GetRenderPosition() { return this->position; }
bool Neo::GetIsSentryObject() { return this->is_sentry_oject; }
std::string Neo::GetDate() { return this->date; }
std::vector<std::shared_ptr<CloseApproach>> &Neo::GetCloseApproach() {
  return this->close_approach;
}

// implement httplib get query when I have obtained the key from
std::vector<std::shared_ptr<Neo>> &Neo::GetNeos(std::vector<std::shared_ptr<Neo>> &neos) { return neos; }

std::vector<std::shared_ptr<Neo>> &Neo::GetNeosDebugOffline(std::vector<std::shared_ptr<Neo>> &neos) {
    std::cout << "Start load Sample Data" << '\n';
  std::ifstream f("data/sample.json");
  nlohmann::json data = nlohmann::json::parse(f);
  return InjestJsonDataOffline(data, neos);
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

std::vector<std::shared_ptr<Neo>> &Neo::InjestJsonDataOffline(nlohmann::json data,
                                               std::vector<std::shared_ptr<Neo>> &neos) {
                                                  std::cout <<("Start Injest Json Data offline") << '\n';
  auto links = data["links"];
  auto pages = data["page"];
  auto neos_data = data["near_earth_objects"];

  int json_size = pages["size"];
  std::cout << "Size: " << json_size << '\n';
  int elements = pages["total_elements"];
  std::cout << "Total Elements: " << elements << '\n';
  int total_pages = pages["total_pages"];
  std::cout << "Total Pages: " << total_pages << '\n';

  for (int i = 0; i < json_size; i++) {
    nlohmann::json neo_data = neos_data[i];
    Neo *n = new Neo(neo_data["id"], neo_data["neo_reference_id"]);

    n->date = "";
    n->SetName(neo_data["name"]);
    n->SetLimitedName(neo_data["name_limited"]);
    n->SetDesignation(neo_data["designation"]);
    n->SetLink(neo_data["nasa_jpl_url"]);

    n->SetDiameter(neo_data["estimated_diameter"]);
    n->SetCloseApproach(neo_data["close_approach_data"]);

    n->SetIsSentryObject(neo_data["is_sentry_object"]);

    n->SetRenderRadius(1);

    neos.emplace_back(n);
  }

  return neos;
}

std::vector<std::shared_ptr<Neo>> &InjestJsonData(nlohmann::json data,
                                   std::vector<std::shared_ptr<Neo>> &neos) {
  auto links = data["links"];
  auto pages = data["page"];
  auto neos_data = data["near_earth_objects"];

  int json_size = pages["size"];
  std::cout << "Size: " << json_size << '\n';
  int elements = pages["total_elements"];
  std::cout << "Total Elements: " << elements << '\n';
  int total_pages = pages["total_pages"];
  std::cout << "Total Pages: " << total_pages << '\n';

  for (int i = 0; i < json_size; i++) {
    nlohmann::json neo_data = neos_data[i];
    auto n = std::make_shared<Neo>(Neo(neo_data["id"], neo_data["neo_reference_id"]));

    n->SetName(neo_data["name"]);
    n->SetLimitedName(neo_data["name_limited"]);
    n->SetDesignation(neo_data["designation"]);
    n->SetLink(neo_data["nasa_jpl_url"]);

    n->SetDiameter(neo_data["estimated_diameter"]);
    n->SetCloseApproach(neo_data["close_approach_data"]);

    n->SetIsSentryObject(neo_data["is_sentry_object"]);

    // default radius
    n->SetRenderRadius(1);

    neos.push_back(n);
  }

  return neos;
}

// TODO!
// the render radius should be based on the diameter that is recieved from
// the query from the api
void Neo::Draw(std::shared_ptr<Model> model) {
    std::cout << std::to_string(this->position.x) + " " + std::to_string(this->position.y) + " " + std::to_string(this->position.z) << '\n';
 DrawModel(*model, this->position, 1, BROWN);
}
