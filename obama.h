#ifndef OBAMA_H
#define OBAMA_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "food.h"
#include "map.h"
using namespace sf;

class Obama{
public:
	Obama(RenderWindow &w);
	~Obama();
	void jump(); // Прыгай, Обама!
	void render(RenderWindow &w);
	void Update(sf::Time time);
	void checkIntersect(Food &food);
	void checkIntersect(Map& map);
	Sprite getSrite();
	bool intersect(Food &food);
	bool alive();
private:
	Food::FoodType _killed_by; // Запоминаем, от чего погиб Обама?
	void kill(Food::FoodType); // На самом деле, Обаму мы не убиваем, а выполняем это действие при пересечении с едой
	void kill_by_ground(); // Погиб от падения
	bool _alive; // Жив ли Обама?
	float _factor_speed; // Ускорение падения
	Texture _texture; // Лицо Обамы
	Sprite *sprite;
};

#endif // OBAMA_H

