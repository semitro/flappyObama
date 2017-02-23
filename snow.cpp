#include "snow.h"

Snow::Snow()
{
	for(int i(0);i<40;i++)
		Snow::snow.push_back(new Particular());
}
void Snow::render(RenderWindow &w){
	std::list<Particular*>::iterator it;
	for(it = Snow::snow.begin();
		it != Snow::snow.end();it++){
		(*it)->render(w);
	}
}
void Snow::update(){
	std::list<Particular*>::iterator it;
	for(it = snow.begin();it != snow.end();it++){
		(*it)->update();
	}
	// delta y = Ax + o(x)
}

Snow::~Snow()
{

}

