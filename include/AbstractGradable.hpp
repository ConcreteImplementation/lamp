#pragma once

#include "ICommand.hpp"
#include "ITickable.hpp"

class AbstractGradable : public ITickable  {
protected:
	int resolution;
	float tolerance;
	float lastRead;
	ICommand* onChange;

	virtual float getRead() = 0;

public:
	AbstractGradable(int resolution, float tolerance);
	virtual float getGradation();
	virtual void setOnChange(ICommand* onChange);
	
	virtual void tick() override;
};