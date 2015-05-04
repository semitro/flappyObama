#include <obama.h>
Obama::Obama(RenderWindow &w){
	_y = 0;
	_alive = true;
	_factor_speed = 0;
	_texture.loadFromFile("Images/obama64.png");

	sprite = new Sprite(_texture);
	sprite->setTextureRect(sf::IntRect(0,0,64,64));
	sprite->setPosition(w.getSize().x/2-64,w.getSize().y/2-32);
}
Obama::~Obama(){
	delete sprite;
}

void Obama::render(RenderWindow &w){
	w.draw(*sprite);
}
void Obama::kill(){
	if(!_alive) // Смерть одна
		return;
	_alive = false;
	static Music music;
	music.openFromFile("Sounds/balalaika.ogg");
	music.play();
}

void Obama::jump(){
	sprite->setRotation(0);
	_factor_speed = -0.52;
}
void Obama::Update(Time time){
	if(!_alive)
		return;
	if(_factor_speed <0.34)
		_factor_speed += 0.02;
	sprite->move(0,time.asMicroseconds()/800*_factor_speed);
	sprite->rotate(_factor_speed*(time.asMicroseconds()/4536));

}
Sprite Obama::getSrite(){
	return *sprite;
}
bool Obama::intersect(Food &food){
	return sprite->getGlobalBounds().intersects(food.getSprite().getGlobalBounds());
}
bool Obama::alive(){
	return _alive;
}
