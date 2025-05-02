#include "../Neo/Neo.hpp"

#include <raylib.h>
#include <string>

class Menu {
private:
  Rectangle apiInputBox;
  std::string textInputBoxBuffer;
  Vector2 windowSize;

public:
  Menu(Vector2 windowSize);
  Menu(Rectangle apiBox, Vector2 windowSize);
  ~Menu();

  std::string GetTextBuffer();

  void DisplayMenu(Neo *currentNeo);
  void DisplayAsteroidInfo(Neo *n);
  void DisplayTextInputBox(Vector2 mousePos);
  void Button(Vector2 mousePos);
};
