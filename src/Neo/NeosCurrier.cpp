#include "NeosCurrier.hpp"
#include "Neo.hpp"
#include <cmath>
#include <filesystem>
#include <fstream>
#include <httplib.h>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <raylib.h>
#include <vector>

NeosCurrier::NeosCurrier(bool isOffline, std::shared_ptr<Model> model) {
    std::cout << "Loading Currier" << '\n';
  this->offline = isOffline;
  if (this->offline) {
    this->GetNeosDebugOffline();
  }
  this->asteroid_model = model;
}

std::vector<std::shared_ptr<Neo>> NeosCurrier::GetNeoCollection() {
  return this->neos;
}

std::shared_ptr<Neo> NeosCurrier::GetSelectedNeo() {
  return this->neos[this->render_index];
}

void NeosCurrier::DisplayNeos() {
  for (const auto &neo : this->neos)
    neo->DisplayNeo();
}

void NeosCurrier::DrawNeos() {
  for (const auto &neo : this->neos)
    neo->Draw(this->asteroid_model);
}

void NeosCurrier::DrawSelectedNeoPointer() {
  if (this->state == AsteroidState::None)
    return;
  // Triangle above the position of the selected neo
  Vector3 selected_neo_position =
      this->neos[this->render_index]->GetRenderPosition();
  Vector3 arrow_position =
      (Vector3){selected_neo_position.x, selected_neo_position.y + 10,
                selected_neo_position.z};
  Vector3 arrow_bottom =
      (Vector3){arrow_position.x, arrow_position.y - 3, arrow_position.z};

  DrawCylinderEx(arrow_bottom, arrow_position, 0.0, 2.0, 100, RED);
}

void NeosCurrier::UpdateNeosPosition(double time, float startTime,
                                     double angleRadians) {
  int numObjects = this->neos.size();
  std::vector<double> angles = CalculateLineSpace(0, 2 * PI, numObjects);

  for (int i = 0; i < numObjects; i++) {
    float x = radius;
    float z = radius;

    // rotation
    x = x * cos(angles[i] + angleRadians * time) -
        z * sin(angles[i] + angleRadians * time);
    z = z * sin(angles[i] + angleRadians * time) +
        z * cos(angles[i] + angleRadians * time);
    float y = sin(time) * (z + x) / 2;

    this->neos[i]->SetRenderPosition((Vector3){x, y, z});
  }
}

std::vector<double> NeosCurrier::CalculateLineSpace(double start, double end,
                                                    int num) {
  std::vector<double> linespace;
  if (num == 0)
    return linespace;
  if (num == 1) {
    linespace.push_back(start);
    return linespace;
  }

  double delta = (end - start) / (num);
  for (int i = 0; i < num; i++) {
    linespace.emplace_back(start + delta * i);
  }

  return linespace;
}

void NeosCurrier::ReachAPI(std::string url, std::string req) {
  httplib::Client cli(url);
  auto res = cli.Get(req);
  if (res && res->status == 200) {
    NeosCurrier::InjestJsonData(res->body);
  } else {
    std::cerr << "Failed to make request!" << '\n';
  }
}

void NeosCurrier::GetNeosDebugOffline() {
    std::cout << "Loading Sample Data from File" << '\n';
    std::cout << std::filesystem::current_path() << '\n';
  std::ifstream f("./data/sample.json");
  nlohmann::json data = nlohmann::json::parse(f);
  return InjestJsonDataOffline(data);
}

void NeosCurrier::InjestJsonDataOffline(nlohmann::json data) {
  this->state = AsteroidState::Active;
  nlohmann::json links = data["links"];
  nlohmann::json pages = data["page"];
  nlohmann::json neos_data = data["near_earth_objects"];

  int json_size = pages["size"];
  this->number_elements = pages["total_elements"];
  this->number_pages = pages["total_pages"];
#ifdef DEBUG
  std::cout << "Size: " << json_size << '\n';
  std::cout << "Total Elements: " << elements << '\n';
  std::cout << "Total Pages: " << total_pages << '\n';
#endif

  for (int i = 0; i < json_size; i++) {
    nlohmann::json neo_data = neos_data[i];
    auto n = std::make_shared<Neo>();
    n->SetID(neo_data["id"]);
    n->SetNeoID(neo_data["neo_reference_id"]);

    std::string date_associated = "Unknown";

    n->SetDate(date_associated);
    n->SetName(neo_data["name"]);
    n->SetLimitedName(neo_data["name_limited"]);
    n->SetDesignation(neo_data["designation"]);
    n->SetLink(neo_data["nasa_jpl_url"]);

    n->SetDiameter(neo_data["estimated_diameter"]);
    n->SetCloseApproach(neo_data["close_approach_data"]);

    n->SetIsSentryObject(neo_data["is_sentry_object"]);

    n->SetRenderRadius(1);

    this->neos.emplace_back(n);
  }
}

void NeosCurrier::InjestJsonData(nlohmann::json data) {
  std::cout << data["links"] << '\n';
  this->state = AsteroidState::Active;
  auto element_count = data["element_count"];
  nlohmann::json neos_data = data["near_earth_objects"];

  for (int i = 0; i < element_count; i++) {
    nlohmann::json neo_data = neos_data[i];
    nlohmann::json date = neos_data["2015-09-08"];
    Neo *n = new Neo(date["id"], date["neo_reference_id"]);

    n->SetName(date["name"]);
    n->SetLimitedName(date["name_limited"]);
    n->SetDesignation(date["designation"]);
    n->SetLink(date["nasa_jpl_url"]);
    n->SetMagnitude(date["absolute_magniture_h"]);

    n->SetHazardous(date["is_potentially_hazardous_asteroid"]);
    n->SetDiameter(date["estimated_diameter"]);
    n->SetCloseApproach(date["close_approach_data"]);

    n->SetIsSentryObject(date["is_sentry_object"]);
    // default radius
    n->SetRenderRadius(1);

    this->neos.emplace_back(n);
  }
}

void NeosCurrier::DeleteAllNeos() {
  this->state = AsteroidState::None;
  this->neos.clear();
}

void NeosCurrier::DeleteSelectedNeo(std::string id) {
  std::shared_ptr<Neo> neoToBeDeleted = nullptr;

  for (auto neo : this->neos) {
    if (neo->GetID() == id) {
      neoToBeDeleted = neo;
    }
  }

  if (neoToBeDeleted != nullptr) {
#ifdef DEGUB
    std::cout << "Neo: " << id << " Successfully Deleted" << "\n";
#endif
    neoToBeDeleted.reset();
    return;
  }

  if (this->neos.size() == 0)
    this->state = AsteroidState::None;

#ifdef DEBUG
  std::cout << "Failed to Delete Neo: " << id;
#endif
}

void NeosCurrier::ChangeFocusAsteroid() {
  // Move up the list
  if (this->neos.size() == 0)
    return;
  if (IsKeyPressed(KEY_J)) {
    if (this->render_index == 0) {
      this->render_index = this->neos.size() - 1;
    } else {
      this->render_index -= 1;
    }
  }
  if (IsKeyPressed(KEY_K)) {
    if (this->render_index == (int)this->neos.size() - 1) {
      this->render_index = 0;
    } else {
      this->render_index += 1;
    }
  }
  if (IsKeyPressed(KEY_F)) {
    std::cout << "Try Deleting" << '\n';
    DeleteAllNeos();
  }
}

NeosCurrier::~NeosCurrier() { this->DeleteAllNeos(); }
