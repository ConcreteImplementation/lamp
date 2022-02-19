#include "CommandChangeHue.hpp"

CommandChangeHue::CommandChangeHue(IColor* color, AbstractGradable* gradable)
	: color(color),
		gradable(gradable)
{ ; }

void CommandChangeHue::execute() {
	int hue = gradable->getGradation() * 360;

	     if(hue ==   0) color->setRGB(  0,   0,   0);
	else if(hue == 360) color->setRGB(255, 255, 255);
	else                color->setHSV(hue, 1, 1);
}
