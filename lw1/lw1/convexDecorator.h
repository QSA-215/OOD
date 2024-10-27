#pragma once
#include "decorator.h"

class ConvexDecorator : public Decorator
{
public:
	ConvexDecorator(Shape* shape) : Decorator(shape) {};

	std::string GetParams() const override {
		return "TRIANGLE: " + Decorator::GetParams();
	}
};