#pragma once
#include <nlohmann/json.hpp>
#include <raylib.h>
#include <raymath.h>
#include <string>
#include <vector>

#include "CloseApproach.hpp"
#include "Diameter.hpp"

using json = nlohmann::json;

class Neo {
public:
  Neo(std::string _id, std::string _neo_id);
  Neo(Neo &&) = default;
  Neo(const Neo &) = default;
  Neo &operator=(Neo &&) = default;
  Neo &operator=(const Neo &) = default;
  ~Neo();

  static std::vector<Neo> &GetNeos(std::vector<Neo> &neos);
  static std::vector<Neo> &GetNeosDebug(std::vector<Neo> &neos);
  static std::vector<Neo> &InjestJsonData(json data, std::vector<Neo> &neos);

  // getters setters //

  void SetName(std::string n);
  void SetLimitedName(std::string n);
  void SetDesignation(std::string d);
  void SetLink(std::string l);
  void SetMagnitude(float m);
  void SetDiameter();
  void SetHazardous(bool h);
  void SetDiameter(json diameter_json);
  void SetCloseApproach(json close_approach_json);

  std::string GetID();
  std::string GetNeoID();
  std::string GetName();
  std::string GetLimitedName();
  std::string GetDesignation();
  std::string GetLink();
  float GetMagnitude();
  bool GetHazardous();
  Diameter &GetDiameter();
  std::vector<CloseApproach *> GetCloseApproach();

  void SplitStringData(std::vector<std::string> &parsed_data, json data,
                       std::string delimiter);
  void DisplayNeo();

  void RenderNeo(Vector2 position);

private:
  std::string id;
  std::string neo_ref_id;
  std::string name;
  std::string name_lim;
  std::string designation;
  std::string link;
  float absolute_magnitude_h;
  bool is_hazardous;
  Diameter *diameter = nullptr;
  std::vector<CloseApproach *> close_approach;
  bool is_sentry_oject;
};
