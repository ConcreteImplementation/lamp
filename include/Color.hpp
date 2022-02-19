#pragma once

#include <Arduino.h>

class Color {
private:
	int r;
	int g;
	int b;

public:
	Color();
	Color(Color* color);;

	void setRGB(int r, int g, int b);
	void setHue(float hue);
	void setHSV(int h, float s, float v);
	int getR() const;
	int getG() const;
	int getB() const;
	uint32_t getAsNumber() const;
};