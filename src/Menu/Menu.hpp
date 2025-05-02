#include "../Neo/Neo.hpp"

#include <raylib.h>
#include <string>

class Menu {
private:
  Rectangle apiInputBox;
  std::string textInputBoxBuffer;

public:
  Menu();
  Menu(Rectangle apiBox);
  ~Menu();

  std::string GetTextBuffer();

  void DisplayMenu(Neo *currentNeo);
  void DisplayAsteroidInfo(Neo *n);
  void DisplayTextInputBox(Vector2 mousePos);
  void Button(Vector2 mousePos);
};
