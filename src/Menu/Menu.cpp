#include "Menu.hpp"
#include "../Neo/Neo.hpp"

#include <iostream>
#include <memory>
#include <raylib.h>
#include <string>
#include <vector>

Menu::Menu(Vector2 windowSize) {
  std::cout << "Menu Created" << '\n';
  this->apiInputBox = (Rectangle){500, 500, 30, 30};
  this->windowSize = windowSize;
}

Menu::~Menu() {}

std::string Menu::GetTextBuffer() { return this->textInputBoxBuffer; }

// go through all parts of the menu
void Menu::DisplayMenu(std::shared_ptr<Neo> currentNeo) {

	if (IsKeyDown(KeyboardKey::KEY_F)) {
		this->state = this->state ? MenuState::Full:MenuState::Minimal;
	}


  if (this->state) {
    this->DisplayMinimalMenu(currentNeo);
  } else {
    this->DisplayFullMenu(currentNeo);
  }
}

void Menu::DisplayMinimalMenu(std::shared_ptr<Neo> n) {
  std::string kilo_max =
      std::to_string(std::get<1>(n->GetDiameter().GetKilo()));
  std::string meter_max =
      std::to_string(std::get<1>(n->GetDiameter().GetMeter()));
  std::string miles_max =
      std::to_string(std::get<1>(n->GetDiameter().GetMiles()));
  std::string feet_max =
      std::to_string(std::get<1>(n->GetDiameter().GetFeet()));

  std::string ids = "Neo Id: " + n->GetID() + " Ref Id: " + n->GetNeoID();
  std::string size = "Size (KM) " + kilo_max + " Size (M): " + meter_max;
  std::string altSize = "Size (Mi) " + miles_max + " Size (ft): " + feet_max;
  // std::string approach = "Approach Distance (KM) " + n->

  DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
  DrawRectangleLines(10, 10, 320, 93, BLUE);

  DrawText("Asteroid Info", 20, 20, 10, BLACK);
  DrawText(ids.c_str(), 40, 40, 10, WHITE);
  DrawText(size.c_str(), 40, 60, 10, WHITE);
}

void Menu::DisplayFullMenu(std::shared_ptr<Neo> neo) {
  std::string kilo_max =
      std::to_string(std::get<1>(neo->GetDiameter().GetKilo()));
  std::string meter_max =
      std::to_string(std::get<1>(neo->GetDiameter().GetMeter()));
  std::string miles_max =
      std::to_string(std::get<1>(neo->GetDiameter().GetMiles()));
  std::string feet_max =
      std::to_string(std::get<1>(neo->GetDiameter().GetFeet()));

  std::string neo_name = neo->GetName();
  std::string neo_limited_name = neo->GetLimitedName();

  std::string neo_designation = neo->GetDesignation();
  std::string neo_hazard = std::to_string(neo->GetHazardous());

  std::vector<CloseApproach *> &neo_approach = neo->GetCloseApproach();

  std::string ids = "Neo Id: " + neo->GetID() + " Ref Id: " + neo->GetNeoID();
  std::string name = "Name: " + neo_name + " Limited Name: " + neo_limited_name;

  std::string designation =
      "Neo Designation: " + neo_designation + " Hazardous: " + neo_hazard;
  std::string size = "Size (KM) " + kilo_max + " Size (M): " + meter_max;
  std::string altSize = "Size (Mi) " + miles_max + " Size (ft): " + feet_max;

  std::string kps = "First Approach KPH: " + neo_approach[0]->GetRelativeKPH() +
                    " KPS: " + neo_approach[0]->GetRelativeKPS();
  std::string mps = "First Approach MPH: " + neo_approach[0]->getRelativeMPH();
  std::string miss_miles =
      "First Approach Miss KM: " + neo_approach[0]->GetMissKilo() +
      "Approach Miss Mi: " + neo_approach[0]->GetMissMiles();

  DrawRectangle(10, 10, 320, 210, Fade(SKYBLUE, 0.5f));
  DrawRectangleLines(10, 10, 320, 210, BLUE);

  DrawText("Asteroid Info", 20, 20, 10, BLACK);
  DrawText(ids.c_str(), 40, 40, 10, WHITE);
  DrawText(name.c_str(), 40, 60, 10, WHITE);
  DrawText(size.c_str(), 40, 80, 10, WHITE);
  DrawText(altSize.c_str(), 40, 100, 10, WHITE);
  DrawText(designation.c_str(), 40, 120, 10, WHITE);
  DrawText(kps.c_str(), 40, 140, 10, WHITE);
  DrawText(mps.c_str(), 40, 160, 10, WHITE);
  DrawText(miss_miles.c_str(), 40, 180, 10, WHITE);
}

void Menu::ClickIntoApiTextBox(Vector2 mousePos) {
  // Change color of menu if mouse hover
  if (CheckCollisionPointRec(mousePos, this->apiInputBox)) {
    return;
  }
}

void Menu::ApiButton(Vector2 mousePos) {
  // Button not clicked
  if (!IsKeyDown(MOUSE_BUTTON_LEFT) &&
      CheckCollisionPointRec(mousePos, this->apiInputBox))
    return;
}
