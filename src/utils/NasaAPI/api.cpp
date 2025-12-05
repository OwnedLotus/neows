#include "api.hpp"

NasaAPI::NasaAPI(std::string key) {
  this->key = key;
}

// void NeosCurrier::ReachAPI(std::string url, std::string req,
// std::shared_ptr<Model> neo_model) {
//   httplib::Client cli(url);
//   auto res = cli.Get(req);
//   if (res && res->status == 200) {
//     NeosCurrier::InjestJsonData(res->body, neo_model);
//   } else {
//     std::cerr << "Failed to make request!" << '\n';
//   }
// }
//
// void NeosCurrier::GetNeosDebugOffline(std::shared_ptr<Model> neo_model) {
//   std::cout << "Loading Sample Data from File" << '\n';
//   std::cout << std::filesystem::current_path() << '\n';
//   std::ifstream f("./data/sample.json");
//   nlohmann::json data = nlohmann::json::parse(f);
//   return InjestJsonDataOffline(data, neo_model);
// }
//
// void NeosCurrier::InjestJsonDataOffline(nlohmann::json data,
// std::shared_ptr<Model> neo_model) {
//   this->state = AsteroidState::Active;
//   nlohmann::json links = data["links"];
//   nlohmann::json pages = data["page"];
//   nlohmann::json neos_data = data["near_earth_objects"];
//
//   int json_size = pages["size"];
//   this->number_elements = pages["total_elements"];
//   this->number_pages = pages["total_pages"];
// #ifdef DEBUG
//   std::cout << "Size: " << json_size << '\n';
//   std::cout << "Total Elements: " << elements << '\n';
//   std::cout << "Total Pages: " << total_pages << '\n';
// #endif
//
//   for (int i = 0; i < json_size; i++) {
//     nlohmann::json neo_data = neos_data[i];
//     auto n = std::unique_ptr<Neo>(new Neo(neo_model, neo_data["id"],
//     neo_data["neo_reference_id"])); n->SetID(neo_data["id"]);
//     n->SetNeoID(neo_data["neo_reference_id"]);
//
//     std::string date_associated = "Unknown";
//
//     n->SetDate(date_associated);
//     n->SetName(neo_data["name"]);
//     n->SetLimitedName(neo_data["name_limited"]);
//     n->SetDesignation(neo_data["designation"]);
//     n->SetLink(neo_data["nasa_jpl_url"]);
//
//     n->SetDiameter(neo_data["estimated_diameter"]);
//     n->SetCloseApproach(neo_data["close_approach_data"]);
//
//     n->SetIsSentryObject(neo_data["is_sentry_object"]);
//
//     n->SetRenderRadius(1);
//
//     this->neos.emplace_back(std::move(n));
//   }
// }
//
// void NeosCurrier::InjestJsonData(nlohmann::json data, std::shared_ptr<Model>
// neo_model) {
//   std::cout << data["links"] << '\n';
//   this->state = AsteroidState::Active;
//   auto element_count = data["element_count"];
//   nlohmann::json neos_data = data["near_earth_objects"];
//
//   for (int i = 0; i < element_count; i++) {
//     nlohmann::json neo_data = neos_data[i];
//     nlohmann::json date = neos_data["2015-09-08"];
// 		auto n = std::unique_ptr<Neo>(new Neo(neo_model, date["id"],
// date["neo_reference_id"]));
//
//     n->SetName(date["name"]);
//     n->SetLimitedName(date["name_limited"]);
//     n->SetDesignation(date["designation"]);
//     n->SetLink(date["nasa_jpl_url"]);
//     n->SetMagnitude(date["absolute_magniture_h"]);
//
//     n->SetHazardous(date["is_potentially_hazardous_asteroid"]);
//     n->SetDiameter(date["estimated_diameter"]);
//     n->SetCloseApproach(date["close_approach_data"]);
//
//     n->SetIsSentryObject(date["is_sentry_object"]);
//     // default radius
//     n->SetRenderRadius(1);
//
//     this->neos.emplace_back(std::move(n));
//   }
// }


