#pragma once

#include "AbstractGradable.hpp"
#include "Lamp.hpp"
#include "Leds.hpp"
#include "ApiServer.hpp"
#include "ITextDisplay.hpp"


class Program {
private:
	AbstractGradable* hueGradiant;
	AbstractGradable* sound;
	Leds* leds;
	Lamp* lamp;
	ApiServer* server;
	ITextDisplay* textDisplay;

public:
	Program();
	void loop();
};