#include "LCD.hpp"

#define CLEAR_ROW "                "


LCD::LCD()
	: lcd(0x27, 16, 2),
		backlightTimeout(TEN_SECONDS)
{ 
	lcd.init();
	lcd.clear();
	lcd.backlight();
}


void LCD::_clearRow(int row) {
	lcd.setCursor(0, row);
	lcd.print(CLEAR_ROW);
}
void LCD::_backlight() {
	lcd.backlight();
	backlightTimeout.restart();
}

void LCD::notify(const IColor* color) {
	snprintf(colorInfo, sizeof(colorInfo), " R%3d G%3d B%3d",
		color->getR(), color->getG(), color->getB());
	
	_clearRow(0);
	lcd.setCursor(0, 0);
	lcd.print(colorInfo);
	
	_backlight();
}

void LCD::show(const char* text) {
	strncpy(textInfo, text, sizeof(textInfo));

	_clearRow(1);
	int col = (16 - strlen(textInfo) ) / 2;
	lcd.setCursor(col, 1);
	lcd.print(textInfo);
	
	_backlight();
}

void LCD::tick() {
	if(backlightTimeout.isDone())
		lcd.noBacklight();
}