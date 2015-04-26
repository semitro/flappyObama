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
	Food(char *filenameOfTexture,bool friendly);
   ~Food();
	void draw(RenderWindow &w);
	void update(Time time);
protected:
	bool _firendly; // Ест Обама или не ест?
	Texture texture;
	Sprite *sprite;
};


#endif // FOOD_H
