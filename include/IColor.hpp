#pragma once

#include <stdint.h>

class IColor {
public:
	virtual void setRGB(int r, int g, int b) = 0;
	virtual void setHSV(int h, float s, float v) = 0;
	virtual int getR() const = 0;
	virtual int getG() const = 0;
	virtual int getB() const = 0;
	virtual uint32_t getAsNumber() const = 0;
};