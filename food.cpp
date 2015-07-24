#include "food.h"
Food::Food(FoodType type){
	_bitten = false;
	_rotation_factor = (rand()%100-55)/10;
	_speed_factor = (10+rand()%20)/10;
	_type = type;
	if(type == Gambyrger)
		texture.loadFromFile("Images/gamb.png");
		else
	if(type == Dollar)
		texture.loadFromFile("Images/dollar.png");
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
	else
	if(type == Nirvana)
		texture.loadFromFile("Images/Nirvana.png");
	else
	if(type == Rammstein)
		texture.loadFromFile("Images/Rammstein.png");
	else
	if(type == Pechka)
		texture.loadFromFile("Images/pechka.png");
	sprite = new Sprite(texture);
	sprite->setPosition(1024,rand()%426);
	sprite->setTextureRect(sf::IntRect(0,0,texture.getSize().x,texture.getSize().y));

	double randomScale = ((rand()%10)/double(500));
	if(type == Matryoshka)
		sprite->scale(0.27+randomScale*2,0.28+randomScale*2);
		else
	if(type == Balalaika)
		sprite->scale(0.42+randomScale,0.42+randomScale);
	if(type == Putin)
		_rotation_factor = (rand()%60-30)/10;else
	if(type == Kli4ko){
		_rotation_factor = (rand()%60-30)/10;sprite->scale(0.64+randomScale,0.64+randomScale);}else
	if(type == Vodka)
		sprite->scale(0.3+randomScale,0.3+randomScale);else
	if(type == Gambyrger)
		sprite->scale(0.35+randomScale,0.35+randomScale);else
	if(type == Dollar)
		sprite->scale(0.32+randomScale,0.32+randomScale);
	if(type == Nirvana)
		sprite->scale(0.25+randomScale,0.25+randomScale);
	if(type == Rammstein)
		sprite->scale(0.28+randomScale,0.28+randomScale);
	if(type == Pechka){
		sprite->scale(0.55+randomScale,0.6+randomScale);
		sprite->setPosition(1024,512-155); //512 = ширина окна, 128 - высота 'травы'
		_rotation_factor = 0;
		_speed_factor = 0.80+(rand()%100)/float(100);
	}
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
	_bitten = true;
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
