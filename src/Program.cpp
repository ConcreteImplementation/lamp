#include <WiFi.h>
#include <Arduino.h>

#include "Program.hpp"
#include "WifiConfiguration.hpp"


Program::Program() {
	Serial.begin(BAUD_RATE);

	WifiConfiguration::StartWifiConfiguration(IS_DEBUG);

	leds = new Leds(LEDS_COUNT, LEDS_PIN, LEDS_BRIGHTNESS);
	lamp = new Lamp();
	lamp->subscribe(leds);
	server = new ApiServer(lamp);
}

void Program::loop() {
	server->tick();
}