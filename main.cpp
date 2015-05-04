#include "mainwindow.h"
#include <QApplication>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "obama.h"
#include "map.h"
#include "food.h"
#include <vector>
#include <qdebug.h>
using std::vector;
using namespace sf;
int main(int argc, char *argv[])
{
	Map map;
	Food balalaika("Images/balalaika.png",false);
	vector<Food> balalaikes;// Летящие балалайки

	sf::RenderWindow w(VideoMode(64*16,64*8),"FlappyObama, v 0.2",Style::Close);
	Obama obama(w);

	Event event;
	//Mouse mouse;
	sf::Clock clock;
	Time currentTime;

	while (w.isOpen()) {

		currentTime = clock.getElapsedTime();
		if(obama.alive())
			clock.restart();


		while(w.pollEvent(event))
		{
			if(event.type == Event::Closed)
					w.close();
			if(event.type == Event::MouseButtonPressed)
					if(Mouse::isButtonPressed(Mouse::Left))
						obama.jump();
		}

		if(
			obama.intersect(balalaika)				)
		{
			obama.kill();
		}
		obama.Update(currentTime);
		map.update(currentTime);
		map.render(w);


		balalaika.update(currentTime);
		balalaika.draw(w);
		obama.render(w);
		w.display();
		w.clear();



	}
	return 0;
}
