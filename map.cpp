#include "map.h"

Map::Map()

{
	texture_grass.loadFromFile("Images/grass.png");
	background_image.loadFromFile("Images/city.png");
	sprite_grass = new Sprite(texture_grass);
	sprite_grass->setPosition(0,0);
	sprite_city = new Sprite(background_image);
	sprite_city->setPosition(0,0);
}
Map::~Map()
{
	delete sprite_grass;
	delete sprite_city;
}
void Map::update(Time time,bool obama_alive){
	if(!obama_alive)
		return;

	_anim_coeff -= time.asMicroseconds()/6236;
	if(_anim_coeff < -16)
		_anim_coeff = 0;
}

void Map::render(RenderWindow &w){
	w.draw(*sprite_city);
	sprite_grass->setPosition(_anim_coeff,w.getSize().y-w.getSize().y/8);


	w.draw(*sprite_grass);
	for(int i(0);i<w.getSize().x/sprite_grass->getTextureRect().width +1;i++){
			sprite_grass->move(sprite_grass->getTextureRect().width,0);
		w.draw(*sprite_grass);
	}

}
float Map::getGrassPosY(){
	return sprite_grass->getPosition().y;
}
