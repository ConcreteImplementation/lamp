#pragma once

#include "IColor.hpp"

class IColorObserver {
public:
	virtual void notify(const IColor* color) = 0;
};