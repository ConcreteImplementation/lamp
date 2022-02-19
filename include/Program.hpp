#pragma once

#include "AbstractGradable.hpp"
#include "Lamp.hpp"
#include "Leds.hpp"
#include "LCD.hpp"
#include "ApiServer.hpp"
#include "ITextDisplay.hpp"


class Program {
private:
	AbstractGradable* hueGradiant;
	AbstractGradable* sound;
	Leds* leds;
	LCD* lcd;
	Lamp* lamp;
	ApiServer* server;
	ITextDisplay* textDisplay;

public:
	Program();
	void loop();
};