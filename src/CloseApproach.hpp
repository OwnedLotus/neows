#include <string>

struct CloseApproach {
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

  bool is_sentry_object;

  CloseApproach() {
    close_approach_date = "";
    close_approach_date_full = "";
    epoch_date_close_approach = 0;
    relative_vel_kps = "";
    relative_vel_kph = "";
    relative_vel_mph = "";

    miss_dist_astronomical = "";
    miss_dist_lunar = "";
    miss_dist_kilometer = "";
    miss_dist_miles = "";
    orbiting_body = "";
    is_sentry_object = false;
  }
};
