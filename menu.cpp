#include "menu.h"

Menu::Menu()
{
	_font.loadFromFile("Fonts/font.ttf");
	_text = Text(L"Обаму настигли беды!\n\t  Лети, Обама!\nКликните правой кнопкой мыши",_font,32);
	_text.setColor(Color(128,2,12));

}
Menu::~Menu()
{

}
void Menu::render(RenderWindow &w){
	_text.setPosition(w.getSize().x/2-_text.getGlobalBounds().width/2,w.getSize().y/2-_text.getGlobalBounds().height);
	w.draw(_text);
}
void Menu::update(Obama &obama){
	//static std::ostringstream score_stream;
	//score_stream << obama.getScore();
	//_text.setString(_text.getString()+score_stream.str());
	if(Mouse::isButtonPressed(Mouse::Right))// || clock.getElapsedTime().asSeconds()>2)
			obama.arise();
}

