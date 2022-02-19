#include "AbstractGradable.hpp"



AbstractGradable::AbstractGradable(int resolution, float tolerance)
	: resolution(resolution),
		tolerance(tolerance),
		lastRead(0),
		onChange(nullptr)
{ ; }



float AbstractGradable::getGradation() {
	return lastRead;
}

void AbstractGradable::setOnChange(ICommand* onChange) {
	this->onChange = onChange;
}


#define ABS(x) ( x >= 0 ? x : -(x) )

void AbstractGradable::tick() {
	float read = getRead() / resolution;

	float diff = ABS(read - lastRead);
	if(diff > tolerance) {
		lastRead = read;
		if(onChange)
			 onChange->execute();
	}
}