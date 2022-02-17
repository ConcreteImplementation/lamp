
#pragma once

#include <WebServer.h>
#include <SPIFFS.h>

#include "Lamp.hpp"


class ApiServer {
private:
	WebServer server;
	Lamp* lamp;

	void ressourceNonTrouvee();
	void setHSV();
	void setRGB();
	
	void _printRequestInfo();

public:
	ApiServer(Lamp* lamp);
	void tick();
};