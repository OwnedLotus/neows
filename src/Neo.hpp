#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

class Neo {
public:
  Neo(std::string _id, std::string _neo_id);
  Neo(Neo &&) = default;
  Neo(const Neo &) = default;
  Neo &operator=(Neo &&) = default;
  Neo &operator=(const Neo &) = default;
  ~Neo();

  // getters setters //
  void SetName(std::string n);
  void SetLimitedName(std::string n);
  void SetDesignation(std::string d);
  void SetLink(std::string l);
  void SetMagnitude(float m);
  void SetDiameter();
  void SetHazardous(bool h);

  std::string GetID();
  std::string GetNeoID();
  std::string GetName();
  std::string GetLimitedName();
  std::string GetDesignation();
  std::string GetLink();
  float GetMagnitude();
  bool GetHazardous();

  static std::vector<Neo> &GetNeos(std::vector<Neo> &neos);
  static std::vector<Neo> &GetNeosDebug(std::vector<Neo> &neos);
  static std::vector<Neo> &InjestJsonData(json data, std::vector<Neo> &neos);
  void DisplayNeo();

private:
  std::string id;
  std::string neo_ref_id;
  std::string name;
  std::string name_lim;
  std::string designation;
  std::string link;
  float absolute_magnitude_h;
  bool is_hazardous;
};
