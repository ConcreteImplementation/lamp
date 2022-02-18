#include "Lamp.hpp"


Lamp::Lamp()
{ ; }


void Lamp::_notifyOberservers() {
	std::list<IObserver*>::iterator i = observers.begin();
	while(i != observers.end()) {
		(*i)->notify( &color );
		++i;
	}
}


Color Lamp::getColor() {
	return Color(color);
}
void Lamp::setHSV(uint32_t h, int s, int v) {
	Serial.println("Lamp setHSV()");
	color.setHSV(h, s, v);
	_notifyOberservers();
}
void Lamp::setRGB(int r, int g, int b) {
	color.setRGB(r, g, b);
	_notifyOberservers();
}

void Lamp::subscribe(IObserver* observer) {
	observers.push_back(observer);
}

