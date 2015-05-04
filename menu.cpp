#include "menu.h"

Menu::Menu()
{
	_font.loadFromFile("Fonts/font.ttf");
	_text = Text(L"Обаму настигли беды!\n\t  Лети, Обама!",_font,32);
	_text.setColor(Color(128,2,12));

}
void Menu::render(RenderWindow &w){
	_text.setPosition(w.getSize().x/2-_text.getGlobalBounds().width/2,w.getSize().y/2-_text.getGlobalBounds().height);
	w.draw(_text);
}
void Menu::update(Obama &obama){
	if(Mouse::isButtonPressed(Mouse::Left))
			obama.arise();
}

Menu::~Menu()
{

}

