#include <obama.h>
Obama::Obama(RenderWindow &w){
	_alive = true;
	_score = 0;
	_factor_speed = 0;
	_streak_best = false;
	_texture.loadFromFile("Images/obama64.png");
	_texture.setSmooth(true);// Сглаживание
	sprite = new Sprite(_texture);
	sprite->setTextureRect(sf::IntRect(0,0,64,64));
	sprite->setPosition(w.getSize().x/2-64,w.getSize().y/2-32);
	_font.loadFromFile("Fonts/font.ttf");
	_text_score = new Text("0",_font,32);
	_text_score->setColor(Color(rand()%255,rand()%255,rand()%255));
	_text_score->setPosition(w.getSize().x-_text_score->getGlobalBounds().width*4,w.getSize().y-_text_score->getGlobalBounds().height*2-4);
	flap_sound.openFromFile("Sounds/flap.ogg");
}
Obama::~Obama(){
	delete sprite;
	delete _text_score;
}
void Obama::render(RenderWindow &w){
	w.draw(*sprite);
}
void Obama::kill(Food &food){
	Food::FoodType killed_by = food.getType();
	if(!_alive) // Смерть одна
		return;
	static Music sound; // Озвучка столкновений

	if(killed_by == Food::Gambyrger){
		sound.openFromFile("Sounds/xroom.ogg");
		sound.play();
		food.eat();
		addScore(5); // Гамбургег прибавляет очки
		return;	} // И посему выходим из
	if(killed_by == Food::Dollar){
		sound.openFromFile("Sounds/money.ogg");
		sound.play();
		addScore(2);
		food.eat();
		return;
	}
	if(killed_by == Food::Kli4ko){
		static Music what_does_kli4ko_say; // Для Кличко отдельный объектик
	 // Bitten нужен для того, чтобы очки с одного Кличко не начислялись fps раз за секунду
		if(!food.bitten()){
			int select = rand()%5; // Вариантов озвучки Кличко целых пять
			if(select == 0)
				what_does_kli4ko_say.openFromFile("Sounds/Kli4ko/Kli4ko1.ogg");else
			if(select == 1)
				what_does_kli4ko_say.openFromFile("Sounds/Kli4ko/Kli4ko2.ogg");else
			if(select == 2)
				what_does_kli4ko_say.openFromFile("Sounds/Kli4ko/Kli4ko3.ogg");else
			if(select == 3)
				what_does_kli4ko_say.openFromFile("Sounds/Kli4ko/Kli4ko4.ogg");else
			if(select == 4)
				what_does_kli4ko_say.openFromFile("Sounds/Kli4ko/Kli4ko5.ogg");
			what_does_kli4ko_say.play();
			food.bite();			// К сожалению, сегодня мы не можем никто знать,
			addScore(rand()%15-7); // Сколько баллов прибавит или отнимет столкновенике с #Кличко

		}
		return;
	}
	//Убиваем обаму
	_alive = false;
	//Обнищаем стрик
	_streak_best = false;
	switch (killed_by) {
	case Food::Balalaika:
		if(rand()%2 == 0)
			sound.openFromFile("Sounds/Balalaika/balalaika.ogg");
		else
			sound.openFromFile("Sounds/Balalaika/balalaika2.ogg");
		break;
	case Food::Matryoshka:
		sound.openFromFile("Sounds/laught.ogg");
		break;
	case Food::Vodka:{
		int select = rand()%3;
			if(select == 0)
				sound.openFromFile("Sounds/Vodka/Vodka1.ogg");
					else
				if(select == 1)
					sound.openFromFile("Sounds/Vodka/Vodka2.ogg");
						else
					sound.openFromFile("Sounds/Vodka/Vodka3.ogg");}
		break;
	case Food::Putin:
		sound.openFromFile("Sounds/Putin.ogg");
		break;
	}
	sound.play();
}
void Obama::kill_by_ground(){
	if(!_alive)
		return;

	_alive = false;

	static Music sound;
	if(rand()%2 == 0)
		sound.openFromFile("Sounds/Obama/kill_by_ground1.ogg");
	else
		sound.openFromFile("Sounds/Obama/kill_by_ground2.ogg");
	sound.play();
}
void Obama::arise(){
	static Music sound;
	sound.openFromFile("Sounds/Obama/arise.ogg");
	sound.play();
	_score = 0;
	_alive = true;
	_factor_speed -= 0.1;
	jump();
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
void Obama::checkIntersect(Food &food,Music &background){
		if(Obama::intersect(food)){
			if(food.getType() == Food::Nirvana){
				food.eat();
				background.pause();
				background.openFromFile("Sounds/SmellsLikeTeenSpirit.ogg");
				background.setVolume(35);
				background.play();
			}else
				if(food.getType() == Food::Rammstein){
					food.eat();
					background.pause();
					background.openFromFile("Sounds/America.ogg");
					background.setVolume(32);
					background.play();
				}
			else
			Obama::kill(food);
		}
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
	static BestScore bestScore;
	if(bestScore.isBest(getScore())){
		static bool streak = false; //Чтоб цать раз подряд музычка играла
		static Music music;
		music.openFromFile("Sounds/record.ogg");
		if(!streak){
			music.play();
			streak = true;
		}
	}
	bestScore.saveIfBest(getScore());
}
void Obama::renderScore(RenderWindow &w){
		w.draw(*_text_score);
}
bool Obama::intersect(Food &food){
	return sprite->getGlobalBounds().intersects(food.getSprite().getGlobalBounds());
}
bool Obama::alive(){
	return _alive;
}
int Obama::getScore(){
	return _score;
}
Sprite Obama::getSrite(){
	return *sprite;
}
