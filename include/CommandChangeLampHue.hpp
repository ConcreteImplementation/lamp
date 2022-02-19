#pragma once

#include "ICommand.hpp"
#include "Lamp.hpp"
#include "AbstractGradable.hpp"

class CommandChangeLampHue : public ICommand {
private:
	Lamp* lamp;
	AbstractGradable* gradable;
	
public:
	CommandChangeLampHue(Lamp* lamp, 	AbstractGradable* gradable);

	void execute() override;
};