#pragma once

#include "Lamp.hpp"
#include "Leds.hpp"
#include "ApiServer.hpp"


class Program {
private:
	Leds* leds;
	Lamp* lamp;
	ApiServer* server;


public:
	Program();
	void loop();
};