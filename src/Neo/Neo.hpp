#pragma once
#include <memory>
#include <raylib.h>
#include <raymath.h>
#include <string>
#include <vector>

#include "CloseApproach.hpp"
#include "Diameter.hpp"

class Neo {
public:
  Neo(std::shared_ptr<Model> neo_model, std::string _id, std::string _neo_id);

  static std::vector<std::unique_ptr<Neo>> &
  GetNeos(std::vector<std::unique_ptr<Neo>> &neos);

  static std::vector<std::unique_ptr<Neo>> &
  GetNeosDebug(std::vector<std::unique_ptr<Neo>> &neos);

  static std::vector<std::unique_ptr<Neo>> &
  GetNeosDebugOffline(std::vector<std::unique_ptr<Neo>> &neos,
                      std::shared_ptr<Model> neo_model);

  static std::vector<std::unique_ptr<Neo>> &
  InjestJsonDataOffline(nlohmann::json data,
                        std::vector<std::unique_ptr<Neo>> &neos,
                        std::shared_ptr<Model> neo_model);

  static std::vector<std::unique_ptr<Neo>> &
  InjestJsonData(nlohmann::json data, std::vector<std::unique_ptr<Neo>> &neos,
                 std::shared_ptr<Model> neo_model);

  // getters setters //

  void SetName(std::string n);
  void SetNeoID(std::string id);
  void SetID(std::string id);
  void SetLimitedName(std::string n);
  void SetDesignation(std::string d);
  void SetLink(std::string l);
  void SetMagnitude(float m);
  void SetDiameter();
  void SetHazardous(bool h);
  void SetDiameter(nlohmann::json diameter_json);
  void SetCloseApproach(nlohmann::json close_approach_json);
  void SetRenderPosition(Vector3 position);
  void SetRenderRadius(float r);
  void SetIsSentryObject(bool is_sentry);
  void SetDate(std::string date);

  std::string GetID();
  std::string GetNeoID();
  std::string GetName();
  std::string GetLimitedName();
  std::string GetDesignation();
  std::string GetLink();
  float GetMagnitude();
  bool GetHazardous();
  std::unique_ptr<Diameter> &GetDiameter();
  Vector3 GetRenderPosition();
  float GetRenderRadius();
  bool GetIsSentryObject();
  std::string GetDate();
  std::vector<std::unique_ptr<CloseApproach>> &GetCloseApproach();

  void DisplayNeo();
  void Draw();

private:
  Vector3 position;
  float render_radius;

  std::string date;
  std::string id;
  std::string neo_ref_id;
  std::string name;
  std::string name_lim;
  std::string designation;
  std::string link;
  float absolute_magnitude_h;
  bool is_hazardous;
  std::unique_ptr<Diameter> diameter;
  std::vector<std::unique_ptr<CloseApproach>> close_approach;
  bool is_sentry_oject;
  std::shared_ptr<Model> model;
};
