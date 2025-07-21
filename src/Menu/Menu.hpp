#include "../Neo/Neo.hpp"

#include <memory>
#include <raylib.h>
#include <string>

enum MenuState { Minimal = 0, Full = 1 };

class Menu {
private:
  Rectangle apiInputBox;
  std::string textInputBoxBuffer;
  Vector2 windowSize;
  MenuState state;

public:
  Menu(Vector2 windowSize);
  ~Menu();

  std::string GetTextBuffer();

  void DisplayMinimalMenu(std::shared_ptr<Neo> currentNeo);
  void DisplayFullMenu(std::shared_ptr<Neo> currentNeo);

  void DisplayMenu(std::shared_ptr<Neo> currentNeo);
  void DisplayAsteroidInfo(std::shared_ptr<Neo> n);
  void ClickIntoApiTextBox(Vector2 mousePos);
  void ApiButton(Vector2 mousePos);
};
