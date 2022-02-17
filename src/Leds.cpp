#include "Leds.hpp"


Leds::Leds(const int led_count, const int pin, const int bightness)
	: ring(led_count, pin, NEO_GRB + NEO_KHZ800),
		numPixels(led_count)
{
	ring.begin();
  ring.show();
  ring.setBrightness(bightness);
	
	setRGB(255, 255, 255);
	delay(1000);
	setRGB(0, 0, 0);
}

void Leds::setPixels(uint32_t color) {
		ring.fill(color);
		ring.show();
}

uint32_t Leds::getColor() {
	return ring.getPixelColor(0);
}
uint32_t Leds::setHSV(uint32_t h, int s, int v) {
	uint32_t color = ring.ColorHSV(h, s, v);
	uint32_t gamma = ring.gamma32(color);
	setPixels(gamma);
	return gamma;
}
uint32_t Leds::setRGB(int r, int g, int b) {
	Serial.println("Leds setRGB()");
	Serial.println(r);
	Serial.println(g);
	Serial.println(b);

	uint32_t color = ring.Color(r, g, b);
	uint32_t gamma = ring.gamma32(color);
	setPixels(gamma);
	
	return gamma;
}

bool Leds::getState() {
	uint32_t color = ring.getPixelColor(0);
	return color > 0;
}
void Leds::setState(bool state) {
	if(state == OFF)
		ring.clear();
	else
		setRGB(255, 255, 255);
}


void Leds::notify(Color color) {
	Serial.println("Leds notify()");
	setRGB(color.getR(), color.getG(), color.getB());
}