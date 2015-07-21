#ifndef MAP_H
#define MAP_H
// Фон
#include <SFML/Graphics.hpp>
using namespace sf;
class Map
{
public:
	Map();
	~Map();
	void render(RenderWindow &w);
	void update(Time time,bool obama_alive);
	float getGrassPosY();
private:
	Texture texture_grass;
	Texture background_image; // Трава и фон
	Sprite *sprite_grass, *sprite_city;
	float _anim_coeff; // Чтоб трава ехала)
};

#endif // MAP_H
