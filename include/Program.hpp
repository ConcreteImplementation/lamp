#pragma once

#include "Lamp.hpp"
#include "Leds.hpp"
#include "ApiServer.hpp"
#include "ITextDisplay.hpp"


class Program {
private:
	Leds* leds;
	Lamp* lamp;
	ApiServer* server;
	ITextDisplay* textDisplay;

public:
	Program();
	void loop();
};