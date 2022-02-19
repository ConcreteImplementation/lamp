#include "Color.hpp"

Color::Color()
{ ; }

Color::Color(Color* color) {
	r = color->r;
	g = color->g;
	b = color->b;
}
void Color::setRGB(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}



void Color::setHSV(int h, float s, float v) {
	
	// preconditions >
	h = abs(h) % 360;
	s = s > 1 ? 1 : s < 0 ? 0 : s;
	v = v > 1 ? 1 : v < 0 ? 0 : v;
	// <

	int max = v * 255;
	float range = v * s;
	int min = (v - range) * 255;
		
	float point = h / 60.0;
	int phase = point;
	point -= phase;

	int x = point * range * 255 + min;
	if(phase % 2)
		x = 255 - x;
		
	switch(phase) {
		case 0:  r = max; g =   x; b = min;	break;
		case 1:  r =   x; g = max; b = min;	break;
		case 2:  r = min; g = max; b =   x;	break;
		case 3:  r = min; g =   x; b = max;	break;
		case 4:  r =   x; g = min; b = max;	break;
		default: r = max; g = min; b =   x;	break;
	}
}

int Color::getR() const {
	return r;
}
int Color::getG() const {
	return g;
}
int Color::getB() const {
	return b;
}
uint32_t Color::getAsNumber() const {
	return (r << 16) | (g << 8) | (b);
}
