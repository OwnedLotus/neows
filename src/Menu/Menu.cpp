#include "Menu.hpp"

#include <iostream>
#include <string>

Menu::Menu() {
  std::cout << "Menu Created" << '\n';
  this->apiInputBox = (Rectangle){ 500, 500, 30, 30};
}

Menu::Menu(Rectangle apiBox) {
  this->apiInputBox = apiBox;
}

Menu::~Menu() {

}

void Menu::UpdateMenu() {

}

void Menu::DisplayMenu() {
}

std::string Menu::GetApi() {
  return "Hello";
}
