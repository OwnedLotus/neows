#include <tuple>

class Diameter {
public:
  Diameter();
  Diameter(Diameter &&) = default;
  Diameter(const Diameter &) = default;
  Diameter &operator=(Diameter &&) = default;
  Diameter &operator=(const Diameter &) = default;
  ~Diameter();

private:
  std::tuple kilometer_min_max;
  std::tuple meter_min_max;
  std::tuple miles_min_max;
  std::tuple feet_min_max;
};

Diameter::Diameter() {
}

Diameter::~Diameter() {
}
