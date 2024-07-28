#pragma once
#include <string>

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
  void SetLink(std::string l);
  void SetMagnitude(float m);
  void SetDiameter();
  void SetHazardous(bool h);

  std::string GetID();
  std::string GetNeoID();
  std::string GetName();
  std::string GetLink();
  float GetMagnitude();
  bool GetHazardous();

private:
  std::string id;
  std::string neo_ref_id;
  std::string name;
  std::string link;
  float absolute_magnitude_h;
  bool is_hazardous;
};
