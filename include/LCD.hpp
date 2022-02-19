#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "ITextDisplay.hpp"
#include "IColorObserver.hpp"
#include "ITickable.hpp"
#include "Timer.hpp"

class LCD : public IColorObserver, public ITextDisplay, public ITickable {
private:
	LiquidCrystal_I2C lcd;
	char colorInfo[17];
	char textInfo[17];
	Timer backlightTimeout;

	void _clearRow(int row);
	void _backlight();
	
public:
	LCD();
	
	void notify(const IColor* color) override;
	void show(const char* texte) override;
	void tick() override;
};