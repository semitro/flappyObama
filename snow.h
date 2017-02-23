#ifndef SNOW_H
#define SNOW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>
using namespace sf;
class Particular
{
	CircleShape *point;
	float dx; // Чтобы полёт был плавным
	float du; // Ускорение
public:
	Particular(){
		this->dx = 5.5 + (rand()%4);
		point = new CircleShape(0.2*(rand()%20));
		point->setPosition(rand()%1024+1224,rand()%512);
		du = 0.002 * (rand()%3-1) ;
		point->setFillColor(Color(rand()%35+25,rand()%100+100,rand()%20+220));
	}
	~Particular(){
		delete point;
	}

	void update(){
		du += 0.0008 * (rand()%7-2);
		dx += du;
		point->setPosition(point->getPosition().x - abs(dx),
						   point->getPosition().y + 0.05* dx + 0.2*(rand()%2-1));
		if(point->getPosition().x < 0){
			this->du = 0.08*(rand()%3);
			this->dx = 9.5 + (rand()%4);
			point->setPosition(rand()%1024+1024,rand()%768);
		}
	}

	void render(RenderWindow &w){
		w.draw(*point);
	}
};
class Snow
{
public:
	Snow();
	~Snow();
	void update();
	void render(RenderWindow &w);
private:
	std::list<Particular*> snow;
};


#endif // SNOW_H
