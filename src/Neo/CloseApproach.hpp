#include <nlohmann/json.hpp>
#include <string>

struct CloseApproach {
public:
  CloseApproach(nlohmann::json close_approach_json);
  ~CloseApproach();

  std::string GetApproachDate() { return close_approach_date; }
  std::string GetApproachDateFull() { return close_approach_date_full; }
  unsigned long long GetEpochDate() { return epoch_date_close_approach; }
  std::string GetRelativeKPS() { return relative_vel_kps; }
  std::string GetRelativeKPH() { return relative_vel_kph; }
  std::string getRelativeMPH() { return relative_vel_mph; }

  std::string GetMissAstro() { return miss_dist_astronomical; }
  std::string GetMissLunar() { return miss_dist_lunar; }
  std::string GetMissKilo() { return miss_dist_kilometer; }
  std::string GetMissMiles() { return miss_dist_miles; }
  std::string GetOrbitBody() { return orbiting_body; }


  void PrintCloseApproach();

private:
  std::string close_approach_date;
  std::string close_approach_date_full;
  unsigned long long epoch_date_close_approach;
  std::string relative_vel_kps;
  std::string relative_vel_kph;
  std::string relative_vel_mph;

  std::string miss_dist_astronomical;
  std::string miss_dist_lunar;
  std::string miss_dist_kilometer;
  std::string miss_dist_miles;
  std::string orbiting_body;
};
