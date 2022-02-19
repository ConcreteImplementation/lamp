#include "CommandChangeLampHue.hpp"

CommandChangeLampHue::CommandChangeLampHue(Lamp* lamp, 	AbstractGradable* gradable)
	: lamp(lamp),
		gradable(gradable)
{ ; }

void CommandChangeLampHue::execute() {
	int hue = gradable->getGradation() * 360;

	Serial.print("in CommandChangeLampHue::execute() -- hue: ");
	Serial.println(hue);

	     if(hue ==   0) lamp->setRGB(  0,   0,   0);
	else if(hue == 360) lamp->setRGB(255, 255, 255);
	else                lamp->setHSV(hue, 1, 1);

	// int grade = gradable->getGradation() * 100 * 14 / 100;
	// switch(grade) {
	// 	case  0: lamp->setRGB(  0,   0,   0); break;
	// 	case  1: lamp->setRGB(127,   0,   0); break;
	// 	case  2: lamp->setRGB(255,   0,   0); break;
	// 	case  3: lamp->setRGB(255, 127,   0); break;
	// 	case  4: lamp->setRGB(255, 255,   0); break;
	// 	case  5: lamp->setRGB(127, 255,   0); break;
	// 	case  6: lamp->setRGB(  0, 255,   0); break;
	// 	case  7: lamp->setRGB(  0, 255, 127); break;
	// 	case  8: lamp->setRGB(  0, 255, 255); break;
	// 	case  9: lamp->setRGB(  0, 127, 255); break;
	// 	case 10: lamp->setRGB(  0,   0, 255); break;
	// 	case 11: lamp->setRGB(127,   0, 255); break;
	// 	case 12: lamp->setRGB(255,   0, 255); break;
	// 	case 13: lamp->setRGB(255, 255, 255); break;
	// }
}
