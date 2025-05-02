#include "../Neo/Neo.hpp"

#include <raylib.h>
#include <string>

class Menu {
private:
  Rectangle apiInputBox;

public:
  Menu();
  Menu(Rectangle apiBox);
  ~Menu();

  void UpdateMenu();
  void DisplayMenu();
  std::string GetApi();
  void DisplayAsteroidInfo(Neo *n);
};
