#ifndef OBAMA_H
#define OBAMA_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <food.h>
using namespace sf;

class Obama{
public:
	Obama(RenderWindow &w);
	~Obama();
	float getHeight();
	void jump(); // Прыгай, Обама!
	void render(RenderWindow &w);
	void Update(sf::Time time);
	void kill();
	Sprite getSrite();
	bool intersect(Food &food);
	bool alive();
private:
	bool _alive; // Жив ли Обама?
	float _y; // Высота птички
	float _factor_speed; // Ускорение падения
	Texture _texture; // Лицо Обамы
	Sprite *sprite;
};

#endif // OBAMA_H

