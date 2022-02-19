#pragma once

#include <list>

#include "IColorObserver.hpp"
#include "IColor.hpp"
#include "Color.hpp"



class Lamp : public IColor {
private:
	Color color;
	std::list<IColorObserver*> observers;

	void _notifyOberservers();

public:
	Lamp();

	void subscribe(IColorObserver* observer);
	
	void setRGB(int r, int g, int b) override;
	void setHSV(int h, float s, float v) override;
	int getR() const override;
	int getG() const override;
	int getB() const override;
	uint32_t getAsNumber() const override;
};