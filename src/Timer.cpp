#include <Arduino.h>

#include "Timer.hpp"



Timer::Timer(unsigned long delay)
	: delay(delay),
		start(millis())
	{;}


unsigned long Timer::getDelay() const {
	return delay;
}
void Timer::setDelay(unsigned long delay) {
	this->delay = delay;
}


bool Timer::isDone() const {
	return millis() - start > delay;
}
void Timer::restart() {
	start = millis();
}

unsigned long Timer::getElapsedTime() const {
	return millis() - start;
}