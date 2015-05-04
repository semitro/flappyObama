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
using std::vector;
using namespace sf;
int main(int argc, char *argv[])
{
	std::srand(std::time(NULL));

	Map map;
	std::list<Food*> balalaikes;
	std::list<Food*>::iterator it_balala;
	sf::RenderWindow w(VideoMode(64*16,64*9),"FlappyObama, v 0.2",Style::Close);
	w.setPosition(sf::Vector2i(128,0));
	Obama obama(w);

	Event event;
	Clock clock;
	Clock nextFoodSpawnTimer;
	nextFoodSpawnTimer.restart();
	Time currentTime;
	while (w.isOpen()) {
		currentTime = clock.getElapsedTime();
		if(obama.alive())
			clock.restart();

		static int nextFoodSpawnTime = rand()%5;
		if(int(nextFoodSpawnTimer.getElapsedTime().asSeconds()) == nextFoodSpawnTime ){
			// Спауним 'еду'
			if(balalaikes.size() < 3){
				if(rand()%4 == 0) // Путин бывает редко
					balalaikes.push_back(new Food(Food::Putin));
				else
					balalaikes.push_back(new Food(Food::FoodType(rand()%2)));
			}
			nextFoodSpawnTime = rand()%7;
			nextFoodSpawnTimer.restart();
		}

		while(w.pollEvent(event))
		{
			if(event.type == Event::Closed)
					w.close();
			if(event.type == Event::MouseButtonPressed)
					if(Mouse::isButtonPressed(Mouse::Left))
						obama.jump();
		}


		obama.Update(currentTime);
		map.update(currentTime);
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
			if(tempFood->getSprite().getPosition().x < -128){
				it_balala = balalaikes.erase(it_balala);
				delete tempFood;
			}
			else
				it_balala++;

		}
		obama.checkIntersect(map);
		obama.render(w);
		w.display();
		w.clear();



	}
	return 0;
}
