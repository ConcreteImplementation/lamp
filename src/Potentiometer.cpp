#include <Arduino.h>

#include "Potentiometer.hpp"


Potentiometer::Potentiometer(const int pin, int resolution, float tolerance)
	: AbstractGradable(resolution, tolerance),
		pin(pin)
{ ; }


float Potentiometer::getRead() {
	return analogRead(pin);
}