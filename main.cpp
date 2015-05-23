#include "mainwindow.h"
#include <QApplication>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "obama.h"
#include "map.h"
#include "food.h"
#include <vector>
#include <qdebug.h>
#include <list>
#include "menu.h"
using std::vector;
using namespace sf;
int main(int argc, char *argv[])
{
	std::srand(std::time(NULL));
	Map map;
	Menu menu;
	std::list<Food*> balalaikes;
	std::list<Food*>::iterator it_balala;
	sf::RenderWindow w(VideoMode(64*16,64*9),"FlappyObama, v 0.2",Style::Close);
	w.setPosition(sf::Vector2i(128,0));
	w.setFramerateLimit(65);
	Image img;
	img.loadFromFile("Images/icon.png");
	w.setIcon(64,64,img.getPixelsPtr());
	Obama obama(w);
	Event event;
	Clock clock;
	Clock nextFoodSpawnTimer;
	nextFoodSpawnTimer.restart();
	Time currentTime;
	//main loop
	while (w.isOpen()) {
		currentTime = clock.getElapsedTime();
			clock.restart();

		static int nextFoodSpawnTime = rand()%5;
		if(int(nextFoodSpawnTimer.getElapsedTime().asSeconds()) == nextFoodSpawnTime ){
			// Спауним 'еду'
			if(balalaikes.size() < 7){
				if(rand()%40 == 0) // Путин бывает редко
					balalaikes.push_back(new Food(Food::Putin));
				else
					balalaikes.push_back(new Food(Food::FoodType(rand()%3)));
			}
			nextFoodSpawnTime = rand()%5;
			nextFoodSpawnTimer.restart();
		}
		while(w.pollEvent(event))
		{
			if(event.type == Event::Closed)
					w.close();
			if(event.type == Event::MouseButtonPressed)
					if(Mouse::isButtonPressed(Mouse::Left))
						obama.jump();
			if(event.type == Event::KeyPressed)
				if(Keyboard::isKeyPressed(Keyboard::Space))
				obama.jump();
		}


		obama.Update(currentTime);
		map.update(currentTime,obama.alive());
		map.render(w);

		for(it_balala=balalaikes.begin();it_balala!=balalaikes.end();it_balala++){
			obama.checkIntersect(*(*it_balala)); // Проверяем столкновение Обамы с едой
			(*it_balala)->update(currentTime);// Рисуем и апдейтим балалайки и не только
			(*it_balala)->draw(w);
		}
		for(it_balala=balalaikes.begin();it_balala!=balalaikes.end(); )
		{

			// Уничтожение вылетевших балалаек
			Food *tempFood = *it_balala;
			if(tempFood->getSprite().getPosition().x < -128){ // Если еда вылетела
				it_balala = balalaikes.erase(it_balala);
				delete tempFood;
				obama.addScore();

			}
			else
				it_balala++;

		}
		obama.checkIntersect(map);

		if(!obama.alive()){
				menu.update(obama);

			static RectangleShape lens(Vector2f(w.getSize().x,w.getSize().y));
			lens.setFillColor(Color(2,4,8,128));
			lens.setPosition(0,0);
			w.draw(lens);
			menu.render(w);

		}
		obama.render(w);
		obama.renderScore(w);
		w.display();
		w.clear();
		qDebug()<<obama.getScore();

	}
	return 0;
}
