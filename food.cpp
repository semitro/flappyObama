#include "food.h"
Food::Food(FoodType type){
	_rotation_factor = (rand()%100-55)/10;
	_type = type;

	if(type == Balalaika)
		texture.loadFromFile("Images/balalaika.png");
		else
	if(type == Matryoshka)	{
		texture.loadFromFile("Images/matreshka.png");
		texture.setSmooth(true);
	}
	if(type == Putin){
		texture.loadFromFile("Images/Putin.png");
	}
	sprite = new Sprite(texture);
	sprite->setPosition(1024,rand()%426);
	sprite->setTextureRect(sf::IntRect(0,0,texture.getSize().x,texture.getSize().y));

	float randomScale = (rand()%21)/100;
	if(type == Matryoshka)
		sprite->scale(0.32+randomScale/1.5,0.32+randomScale/1.5);
		else
	if(type == Balalaika)
		sprite->scale(0.42+randomScale,0.42+randomScale);
	if(type == Putin)
		_rotation_factor = (rand()%60-30)/10;

}
Food::~Food(){
	delete sprite;
}

void Food::draw(RenderWindow &w){
	w.draw(*sprite);
}

void Food::update(sf::Time time){
	sprite->move(-(time.asMicroseconds()/2400),0);
	sprite->rotate(_rotation_factor);
}
Sprite Food::getSprite(){
	return *sprite;
}
Food::FoodType Food::getType(){
	return _type;
}
