#pragma once
#include "decorator.h"

class RectangleDecorator : public Decorator
{
public:
	RectangleDecorator(Shape* shape) : Decorator(shape) {};

	std::string GetParams() const override {
		return "RECTANGLE: " + Decorator::GetParams();
	}
};