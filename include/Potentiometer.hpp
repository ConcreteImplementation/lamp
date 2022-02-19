#pragma once

#include "AbstractGradable.hpp"

class Potentiometer : public AbstractGradable {
private:
	const int pin;
	
public:
	Potentiometer(const int pin, int resolution, float tolerance);

	float getRead() override;
};