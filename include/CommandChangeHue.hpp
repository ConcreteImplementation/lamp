#pragma once

#include "ICommand.hpp"
#include "IColor.hpp"
#include "AbstractGradable.hpp"

class CommandChangeHue : public ICommand {
private:
	IColor* color;
	AbstractGradable* gradable;
	
public:
	CommandChangeHue(IColor* color, 	AbstractGradable* gradable);

	void execute() override;
};