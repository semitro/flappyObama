#ifndef FOOD_H
#define FOOD_H
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
using sf::Texture;
using sf::Sprite;
using sf::RenderWindow;
using sf::Time;
class Food
{
public:
	enum FoodType{
		Balalaika,
		Matryoshka,
		Vodka,
		Putin
	};
	Food(FoodType type);
   ~Food();

	void draw(RenderWindow &w);
	void update(Time time);
	sf::Sprite getSprite();
	FoodType getType();
protected:
	float _speed_factor; // Чтоб летели с разной скоростью
	float _rotation_factor; // Чтоб объекты крутились
	FoodType _type;
	Texture texture;
	Sprite *sprite;
};


#endif // FOOD_H
