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
		Gambyrger,
		Kli4ko,
		Putin
	};
	Food(FoodType type);
   ~Food();

	void draw(RenderWindow &w);
	void update(Time time);
	void eat(); // 'Съесть' объект (объект исчезнет)
	void bite(); // 'Укусить объект' (объект не исчезнет, но с Обамой перестанет взаимодействовать)
	bool bitten(); // Укушен ли объект?
	sf::Sprite getSprite();
	FoodType getType();
protected:
	float _speed_factor; // Чтоб летели с разной скоростью
	float _rotation_factor; // Чтоб объекты крутились
	FoodType _type;
	Texture texture;
	Sprite *sprite;
	bool _bitten; //Не укущена ли уже еда? (Частично костыль, частично грамотная штука)
};


#endif // FOOD_H
