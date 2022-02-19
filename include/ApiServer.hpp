
#pragma once

#include <WebServer.h>
#include <SPIFFS.h>

#include "IColor.hpp"


class ApiServer {
private:
	WebServer server;
	IColor* color;

	void ressourceNonTrouvee();
	void setHSV();
	void setRGB();
	
	void _printRequestInfo();

public:
	ApiServer(IColor* color);
	void tick();
};