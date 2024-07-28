#include "Neo.hpp"
#include <string>

Neo::Neo(std::string _id, std::string _neo_id) {
  id = _id;
  neo_ref_id = _neo_id;
}

Neo::~Neo() {}

void Neo::SetName(std::string n) { name = n; }
void Neo::SetLink(std::string l) { link = l; }
void Neo::SetMagnitude(float m) { absolute_magnitude_h = m; }
void Neo::SetDiameter() {}
void Neo::SetHazardous(bool h) { is_hazardous = h; }

std::string Neo::GetID() { return id; }
std::string Neo::GetNeoID() { return neo_ref_id; }
std::string Neo::GetName() { return name; }
std::string Neo::GetLink() { return link; }
float Neo::GetMagnitude() { return absolute_magnitude_h; }
bool Neo::GetHazardous() { return is_hazardous; }
