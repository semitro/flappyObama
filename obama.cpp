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
	flap_sound.openFromFile("Sounds/flap.ogg");
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

	if(killed_by == Food::Gambyrger){
		addScore(5); // Гамбургег прибавляет очки
		return;	} // И посему выходим из функции
	if(killed_by == Food::Kli4ko && ){
		addScore(rand()%15-7); // К сожалению, сегодня мы не можем никто знать,
		return;				  // Сколько баллов прибавит или отнимет столкновенике с #Кличко
	}
	//Убиваем обаму
	_alive = false;
	static Music sound;

	switch (killed_by) {
	case Food::Balalaika:{
		int select = rand()%2;
		if(select == 0)
			sound.openFromFile("Sounds/Balalaika/balalaika.ogg");
		else
			sound.openFromFile("Sounds/Balalaika/balalaika2.ogg");
		}
		break;
	case Food::Matryoshka:
		sound.openFromFile("Sounds/laught.ogg");
		break;
	case Food::Vodka:
		int select = rand()%3;
			if(select == 0)
				sound.openFromFile("Sounds/Vodka/Vodka1.ogg");
					else
			if(select == 1)
				sound.openFromFile("Sounds/Vodka/Vodka2.ogg");
					else
				sound.openFromFile("Sounds/Vodka/Vodka3.ogg");
		break;
	}
	sound.play();

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
	_text_score->setColor(Color(rand()%255,rand()%255,rand()%255));
}

void Obama::jump(){
	flap_sound.play();
	sprite->setRotation(0);
	if(sprite->getPosition().y > - 32)
		_factor_speed = -0.47;
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
		if(Obama::intersect(food) && food.getType() == Food::Gambyrger)
			food.eat();

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
