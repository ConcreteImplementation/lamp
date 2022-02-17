#pragma once

#include "Color.hpp"

class ISubject {
public:
	virtual Color getColor() = 0;
};