#include "Color.hpp"

Color::Color() {

}
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
void Color::setHSV(uint32_t h, int s, int v) {

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
