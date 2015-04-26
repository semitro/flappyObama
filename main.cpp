#include "mainwindow.h"
#include <QApplication>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "obama.h"
#include "map.h"
using namespace sf;
int main(int argc, char *argv[])
{
	Obama obama;
	Map map;

	sf::RenderWindow w(VideoMode(64*16,64*8),"FlappyObama, v 0.1",Style::Close);
	Event event;
	//Mouse mouse;
	sf::Clock clock;
	while (w.isOpen()) {
		while(w.pollEvent(event))
		{
			if(event.type == Event::Closed)
					w.close();
			if(event.type == Event::MouseButtonPressed)
					if(Mouse::isButtonPressed(Mouse::Left))
						obama.jump();
		}
		clock.restart();
		obama.Update(clock.getElapsedTime());
		map.update(clock.getElapsedTime());
		map.render(w);
		obama.render(w);
		w.display();
		w.clear();
		clock.restart();
	}
	return 0;
}
