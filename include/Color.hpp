#pragma once

#include <Arduino.h>

#include "IColor.hpp"

class Color : public IColor{
private:
	int r;
	int g;
	int b;

public:
	Color();
	Color(Color* color);

	void setRGB(int r, int g, int b) override;
	void setHSV(int h, float s, float v) override;
	int getR() const override;
	int getG() const override;
	int getB() const override;
	uint32_t getAsNumber() const override;
};