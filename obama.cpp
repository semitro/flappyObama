#include <obama.h>
Obama::Obama(){
	_y = 0;
	_alive = true;
	_factor_speed = 0;
	_texture.loadFromFile("Images/obama64.png");
	sprite = new Sprite(_texture);
}
Obama::~Obama(){
	delete sprite;
}

void Obama::render(RenderWindow &w){
	int getHeight();
	sprite->setPosition(w.getSize().x/2-64,_y);
	w.draw(*sprite);
}
void Obama::jump(){
	_y -= 64;
	sprite->setRotation(0);
	_factor_speed = -0.25;
}
void Obama::Update(Time time){
	if(_factor_speed <0.34)
	_factor_speed += 0.02;
	_y += (time.asMicroseconds()/200)+12*_factor_speed;
	sprite->rotate(_factor_speed*(time.asMicroseconds()));
}
