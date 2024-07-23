#include <string>
#include "Diameter.hpp"

class Neo {
public:
  Neo();
  Neo(Neo &&) = default;
  Neo(const Neo &) = default;
  Neo &operator=(Neo &&) = default;
  Neo &operator=(const Neo &) = default;
  ~Neo();

private:
  unsigned int id;
  unsigned int neo_ref_id;
  std::string name;
  std::string link;
  float absolute_magnitude_h;
  Diameter diameter;
  bool is_hazardous;

};

Neo::Neo() {
}

Neo::~Neo() {
}
