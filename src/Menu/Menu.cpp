#include "Menu.hpp"
#include "../Neo/Neo.hpp"

#include <iostream>
#include <memory>
#include <raylib.h>
#include <string>

Menu::Menu(Vector2 windowSize) {
  std::cout << "Menu Created" << '\n';
  this->apiInputBox = (Rectangle){500, 500, 30, 30};
  this->windowSize = windowSize;
}

Menu::~Menu() {}

std::string Menu::GetTextBuffer() { return this->textInputBoxBuffer; }

// go through all parts of the menu
void Menu::DisplayMenu(std::shared_ptr<Neo> currentNeo) {
  this->DisplayAsteroidInfo(currentNeo);
}

void Menu::DisplayAsteroidInfo(std::shared_ptr<Neo> n) {
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
  // DrawText(approach.c_str(), 40, 40, 10, WHITE);
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
