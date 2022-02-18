#pragma once

#include "Color.hpp"
#include "ISubject.hpp"

class IObserver {
public:
	virtual void notify(const Color* color) = 0;
};