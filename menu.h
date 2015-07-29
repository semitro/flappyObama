#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "obama.h"
using namespace sf;
class Menu // Меню смерти
{
public:
	Menu();
	void render(RenderWindow &w);
	void update(Obama &obama);
	~Menu();
private:
	Font _font;
	Text _text;
};

#endif // MENU_H
