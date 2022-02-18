#include <WiFi.h>
#include <Arduino.h>

#include "Program.hpp"
#include "WifiConfiguration.hpp"
#include "LCD.hpp"

Program::Program() {
	if(IS_DEBUG)
		Serial.begin(BAUD_RATE);

	LCD* lcd = new LCD();
	textDisplay = lcd;
	textDisplay->show("Connecting...");

	WifiConfiguration::StartWifiConfiguration(IS_DEBUG);
	const char* localIP = WiFi.localIP().toString().c_str();
	textDisplay->show(localIP);


	leds = new Leds(LEDS_COUNT, LEDS_PIN, LEDS_BRIGHTNESS);
	lamp = new Lamp();

	lamp->subscribe(leds);
	lamp->subscribe(lcd);
	lamp->setRGB(127, 127, 127);

	server = new ApiServer(lamp);
}

void Program::loop() {
	server->tick();
}