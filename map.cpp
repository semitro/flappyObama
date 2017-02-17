#include "map.h"

Map::Map()
{
	texture_grass.loadFromFile("Images/grass.png");
	background_image.loadFromFile("Images/stars.jpg");
	sprite_grass = new Sprite(texture_grass);
	sprite_grass->setPosition(0,0);
	sprite_city = new Sprite(background_image);
	sprite_city->setPosition(0,0);

	sf::CircleShape snowik(1);
	snowik.setOutlineColor(Color::Black);
	snowik.setRotation(0.2);
	for(int i(0);i<40;i++){
		snowik.setRadius(2*(rand()%4));
		snowik.setFillColor(Color(rand()%80+20,rand()%8+10, rand()%150+100));
		snowik.setPosition(rand()%1280+1048, rand()%1024);
		snow.push_back(snowik);
	}
}
Map::~Map()
{
	delete sprite_grass;
	delete sprite_city;
}
void Map::update(Time time,bool obama_alive){
	if(!obama_alive) // Мёртвый Обама не летает
		return;
	_anim_coeff -= time.asMicroseconds()/6236;
	if(_anim_coeff < -16)
		_anim_coeff = 0;
}
void Map::render(RenderWindow &w){
	w.draw(*sprite_city);
	sprite_grass->setPosition(_anim_coeff,w.getSize().y-w.getSize().y/8);
	w.draw(*sprite_grass);
	for(int i(0);i<w.getSize().x/sprite_grass->getTextureRect().width+1;i++){
			sprite_grass->move(sprite_grass->getTextureRect().width,0); // Движение травы создаёт иллюзию движения Обамы
		w.draw(*sprite_grass);
	}
	std::list<CircleShape>::iterator it;
	for(it = snow.begin();it != snow.end();it++){
		it->setPosition(it->getPosition().x-10, it->getPosition().y + rand()%4 - 2);
		if(it->getPosition().x < 0) it->setPosition(rand()%2500,rand()%1024);
		w.draw(*it);
	}
}
float Map::getGrassPosY(){
	return sprite_grass->getPosition().y;
}
