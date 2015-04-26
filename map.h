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
	void update(Time time);
private:
	Texture texture_grass;
	Sprite *sprite_grass;
	float _anim_coeff; // Чтоб трава ехала)
};

#endif // MAP_H
