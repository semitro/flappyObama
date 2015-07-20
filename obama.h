#ifndef OBAMA_H
#define OBAMA_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "food.h"
#include "map.h"
#include <sstream>
using namespace sf;

class Obama{
public:
	Obama(RenderWindow &w);
	~Obama();
	void jump(); // Прыгай, Обама!
	void render(RenderWindow &w);
	void renderScore(RenderWindow &w);
	void Update(sf::Time time);
	void checkIntersect(Food &food);
	void checkIntersect(Map& map);
	void arise(); // Воскресни!
	void addScore(int ball=1);
	int getScore();
	Sprite getSrite();
	bool intersect(Food &food);
	bool alive();
private:
	Food::FoodType _killed_by; // Запоминаем, от чего погиб Обама?
	void kill(Food &); // На самом деле, Обаму мы не убиваем, а выполняем это действие при пересечении с едой
	void kill_by_ground(); // Погиб от падения
	bool _alive; // Жив ли Обама?
	float _factor_speed; // Ускорение падения
	int _score; // Счёт
	Texture _texture; // Лицо Обамы
	Sprite *sprite;
	Font _font; // Шрифт для текста
	Text *_text_score; // Вывод счёта
	Music flap_sound; // Звук подлёта
};
#endif // OBAMA_H

