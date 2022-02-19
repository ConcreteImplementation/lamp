#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "ITextDisplay.hpp"
#include "IColorObserver.hpp"

class LCD : public IColorObserver, public ITextDisplay {
private:
	LiquidCrystal_I2C lcd;
	char colorInfo[17];
	char textInfo[17];

	void _clearRow(int row);
	
public:
	LCD();
	
	void notify(const IColor* color) override;
	void show(const char* texte) override;
};