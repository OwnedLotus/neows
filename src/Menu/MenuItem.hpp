#include <raylib.h>

class MenuItem {
public:
	MenuItem();
	~MenuItem();

	virtual void DisplayItem() = 0;
private:
	Vector2 position;
};
