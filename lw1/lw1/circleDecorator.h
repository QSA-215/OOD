#pragma once
#include "decorator.h"

class CircleDecorator : public Decorator
{
public:
	CircleDecorator(Shape* shape) : Decorator(shape) {};

	std::string GetParams() const override {
		return "CIRCLE: " + Decorator::GetParams();
	}
};