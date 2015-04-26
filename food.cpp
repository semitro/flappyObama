#include "food.h"
Food::Food(char* filename,bool friendly){
	std::srand(std::time(NULL));
	texture.loadFromFile(filename); // Покатит ли char* ?
	sprite = new Sprite(texture);
	sprite->setPosition(1024,rand()%512);

}
Food::~Food(){
	delete sprite;
}

void Food::draw(RenderWindow &w){
	w.draw(*sprite);
}

void Food::update(sf::Time time){
	sprite->move(-time.asMicroseconds()/2,0);
}
