#include "MenuItem.hpp"
#include <vector>
#include <string>

class Menu {
	Menu();
	~Menu();

	std::vector<MenuItem> uiItems;
	void UpdateMenu();

	std::string GetKey();
};
