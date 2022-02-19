#include "Lamp.hpp"


Lamp::Lamp()
{ ; }


void Lamp::subscribe(IColorObserver* observer) {
	observers.push_back(observer);
}

void Lamp::_notifyOberservers() {
	std::list<IColorObserver*>::iterator i = observers.begin();
	while(i != observers.end()) {
		(*i)->notify( &color );
		++i;
	}
}



void Lamp::setRGB(int r, int g, int b) {
	color.setRGB(r, g, b);
	_notifyOberservers();
}

void Lamp::setHSV(int h, float s, float v) {
	color.setHSV(h, s, v);
	_notifyOberservers();
}


int Lamp::getR() const { return color.getR(); }
int Lamp::getG() const { return color.getG(); }
int Lamp::getB() const { return color.getB(); }
uint32_t Lamp::getAsNumber() const { return color.getAsNumber(); }