#pragma once
#include <string>

#include <nlohmann/json.hpp>

#include "../../Neo/Neo.hpp"
#include "../../Neo/Diameter.hpp"
#include "../../Neo/OrbitalData.hpp"

class NasaAPI {
public:
	NasaAPI();
	NasaAPI(std::string key);

	nlohmann::json GetAPI();
	std::vector<Neo> CreateNeos(nlohmann::json data);
	Diameter CreateDiameter(nlohmann::json data);
	CloseApproach CreateCloseApproach(nlohmann::json data);
	OrbitalData CreateOrbitalData(nlohmann::json data);

private:
	std::string key;
	std::string url = "https://api.nasa.gov/neo/rest/v1/feed?";
	nlohmann::json links;
	int element_count;
	std::vector<nlohmann::json> dates;
};
