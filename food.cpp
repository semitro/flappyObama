#include "food.h"
Food::Food(FoodType type){
	_bitten = true;
	_rotation_factor = (rand()%100-55)/10;
	_speed_factor = (10+rand()%20)/10;
	_type = type;
	if(type == Gambyrger)
		texture.loadFromFile("Images/gamb.png");
	if(type == Balalaika)
		texture.loadFromFile("Images/balalaika.png");
		else
	if(type == Matryoshka)	{
		texture.loadFromFile("Images/matreshka.png");
		texture.setSmooth(true);
	}else
	if(type == Putin){
		texture.loadFromFile("Images/Putin.png");
	}else
	if(type == Vodka)
		texture.loadFromFile("Images/vodka.png");
	else
	  if(type == Kli4ko)
		  texture.loadFromFile("Images/kli4ko.png");
	sprite = new Sprite(texture);
	sprite->setPosition(1024,rand()%426);
	sprite->setTextureRect(sf::IntRect(0,0,texture.getSize().x,texture.getSize().y));

	float randomScale = (rand()%27)/100;
	if(type == Matryoshka)
		sprite->scale(0.32+randomScale/1.5,0.32+randomScale/1.5);
		else
	if(type == Balalaika)
		sprite->scale(0.42+randomScale,0.42+randomScale);
	if(type == Putin)
		_rotation_factor = (rand()%60-30)/10;else
	if(type == Kli4ko){
		_rotation_factor = (rand()%60-30)/10;sprite->scale(0.64+randomScale,0.64+randomScale);}else
	if(type == Vodka)
		sprite->scale(0.3+randomScale,0.3+randomScale);
	if(type == Gambyrger)
		sprite->scale(0.35+randomScale,0.35+randomScale);
}
Food::~Food(){
	delete sprite;
}

void Food::draw(RenderWindow &w){
	w.draw(*sprite);
}

void Food::update(sf::Time time){
	sprite->move(-(time.asMicroseconds()/4800*_speed_factor),0);
	sprite->rotate(_rotation_factor);
}
void Food::eat(){
	sprite->move(-800,0);
}
void Food::bite(){
	_bitten = false;
}
bool Food::bitten(){
	return _bitten;
}

Sprite Food::getSprite(){
	return *sprite;
}
Food::FoodType Food::getType(){
	return _type;
}
