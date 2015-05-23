#include <obama.h>
Obama::Obama(RenderWindow &w){
	_alive = true;
	_score = 0;
	_factor_speed = 0;
	_texture.loadFromFile("Images/obama64.png");
	_texture.setSmooth(true);// Сглаживание
	sprite = new Sprite(_texture);
	sprite->setTextureRect(sf::IntRect(0,0,64,64));
	sprite->setPosition(w.getSize().x/2-64,w.getSize().y/2-32);
	_font.loadFromFile("Fonts/font.ttf");
	_text_score = new Text("0",_font,32);
	_text_score->setColor(Color(rand()%255,rand()%255,rand()%255));
	_text_score->setPosition(w.getSize().x-_text_score->getGlobalBounds().width*2,w.getSize().y-_text_score->getGlobalBounds().height*2);

}
Obama::~Obama(){
	delete sprite;
	delete _text_score;
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
	_score = 0;
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
void Obama::addScore(int ball){
	_score += ball;
	if(_score < 0)
		_score = 0;
	std::ostringstream score_stream;
	score_stream << _score;
	_text_score->setString(score_stream.str());

}

bool Obama::alive(){
	return _alive;
}
int Obama::getScore(){
	return _score;
}

void Obama::renderScore(RenderWindow &w){
		w.draw(*_text_score);
}
