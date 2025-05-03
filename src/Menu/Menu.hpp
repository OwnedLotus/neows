#include "../Neo/Neo.hpp"

#include <memory>
#include <raylib.h>
#include <string>

class Menu {
private:
  Rectangle apiInputBox;
  std::string textInputBoxBuffer;
  Vector2 windowSize;

public:
  Menu(Vector2 windowSize);
  ~Menu();

  std::string GetTextBuffer();

  void DisplayMenu(std::shared_ptr<Neo> currentNeo);
  void DisplayAsteroidInfo(std::shared_ptr<Neo> n);
  void ClickIntoApiTextBox(Vector2 mousePos);
  void ApiButton(Vector2 mousePos);
};
