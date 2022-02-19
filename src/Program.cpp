#include <WiFi.h>
#include <Arduino.h>

#include "Program.hpp"
#include "WifiConfiguration.hpp"
#include "Potentiometer.hpp"
#include "CommandChangeHue.hpp"
#include "LCD.hpp"



Program::Program() {
	if(IS_DEBUG)
		Serial.begin(BAUD_RATE);

	lcd = new LCD();
	textDisplay = lcd;
	textDisplay->show("Connecting...");

	WifiConfiguration::StartWifiConfiguration(IS_DEBUG);
	const char* localIP = WiFi.localIP().toString().c_str();
	textDisplay->show(localIP);


	lamp = new Lamp();

	leds = new Leds(LEDS_COUNT, LEDS_PIN, LEDS_BRIGHTNESS);

	int resolution = (1 << ANALOG_READ_RESOLUTION) - 1;
	hueGradiant = new Potentiometer(POTENTIOMETER_PIN, resolution, POTENTIOMETER_TOLERANCE);
	CommandChangeHue* changeHue = new CommandChangeHue(lamp, hueGradiant);
	hueGradiant->setOnChange(changeHue);
	

	lamp->subscribe(leds);
	lamp->subscribe(lcd);
	lamp->setRGB(127, 127, 127);

	server = new ApiServer(lamp);
}

void Program::loop() {
	hueGradiant->tick();
	server->tick();
	lcd->tick();
}