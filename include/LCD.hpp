#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "ITextDisplay.hpp"
#include "IObserver.hpp"

class LCD : public IObserver, public ITextDisplay {
private:
	LiquidCrystal_I2C lcd;
	char colorInfo[17];
	char textInfo[17];

	void _clearRow(int row);
	
public:
	LCD();
	
	void notify(const Color* color) override;
	void show(const char* texte) override;
};