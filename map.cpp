#include "map.h"

Map::Map()
{
	texture_grass.loadFromFile("Images/grass.png");
	sprite_grass = new Sprite(texture_grass);
	sprite_grass->setPosition(0,0);
}
Map::~Map()
{
	delete sprite_grass;
}
void Map::update(Time time){
	_anim_coeff -= time.asMicroseconds()/5;
//	if(_anim_coeff < 16)
	//	_anim_coeff = -1;
}

void Map::render(RenderWindow &w){

	sprite_grass->setPosition(_anim_coeff,w.getSize().y-w.getSize().y/8);


	w.draw(*sprite_grass);
	for(int i(0);i<w.getSize().x/sprite_grass->getTextureRect().width +1;i++){
			sprite_grass->move(sprite_grass->getTextureRect().width,0);
		w.draw(*sprite_grass);
	}

}
