#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "map.h"
#include "food.h"
#include <list>
#include "menu.h"
#include "bestscore.h"
#include "pause.h"
#include "obama.h"
#include "gameMode.h"
class Game
{
public:
	Game(GameMode mode=one_shot_one_kill, bool soundsOn=true);
	~Game();
	void start();
private:
	GameMode _mode;
	bool _soundsOn;
};

#endif // GAME_H
