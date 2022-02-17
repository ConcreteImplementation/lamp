#pragma once

#include <list>

#include "IObserver.hpp"
#include "ISubject.hpp"
#include "Color.hpp"

#define ON true
#define OFF false

class Lamp : public ISubject {
private:
	Color color;
	std::list<IObserver*> observers;

	void _notifyOberservers();

public:
	Lamp();
	
	void setHSV(uint32_t h, int s, int v);
	void setRGB(int r, int g, int b);

	void subscribe(IObserver* observer);
	Color getColor() override;
};