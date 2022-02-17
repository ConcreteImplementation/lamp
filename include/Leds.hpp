#pragma once

#include <Adafruit_NeoPixel.h>

#include "Lamp.hpp"
#include "IObserver.hpp"

#define ON true
#define OFF false

class Leds : public IObserver {
private:
	Adafruit_NeoPixel ring;
	int numPixels;



	void setPixels(uint32_t color);

public:
	Leds(const int pin, const int led_count, const int bightness);
	
	uint32_t getColor();
	uint32_t setHSV(uint32_t h, int s, int v);
	uint32_t setRGB(int r, int g, int b);
	
	bool getState();
	void setState(bool state);

	void notify(Color color) override;
};