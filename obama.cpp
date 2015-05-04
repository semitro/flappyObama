#include <obama.h>
Obama::Obama(RenderWindow &w){
	_alive = true;
	_factor_speed = 0;
	_texture.loadFromFile("Images/obama64.png");
	_texture.setSmooth(true);// Сглаживание
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
void Obama::kill(Food::FoodType killed_by){
	if(!_alive) // Смерть одна
		return;
	_alive = false;
	if(killed_by == Food::Balalaika){
		_alive = false;
		static Music music;
		music.openFromFile("Sounds/balalaika.ogg");
		music.play();
	}
		else
	if(killed_by == Food::Matryoshka){
		_alive = false;
		static Music music;
		music.openFromFile("Sounds/laught.ogg");
		music.play();
	}
	if(killed_by == Food::Putin){
		_alive = false;
	//r	static Music music;

	}

}
void Obama::kill_by_ground(){
	if(!_alive)
		return;
	_alive = false;

	static Music music;
	//music.openFromFile("Sounds/aaa.ogg");
	music.play();
}
void Obama::arise(){
	_alive = true;
	_factor_speed -= 0.2;
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
void Obama::checkIntersect(Food &food){
		if(Obama::intersect(food))
			Obama::kill(food.getType());
}
void Obama::checkIntersect(Map &map){
	if(sprite->getPosition().y+64 > map.getGrassPosY())
		kill_by_ground();
}

bool Obama::alive(){
	return _alive;
}
