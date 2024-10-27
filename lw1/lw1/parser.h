#pragma once
#include "decorators.h"
#include "shapes.h"

std::vector<float> ParseParameters(const std::string& command);
Shape* ParseCircle(const std::vector<float>& parameters);
Shape* ParseRectangle(const std::vector<float>& parameters);
Shape* ParseTriangle(const std::vector<float>& parameters);
void ParseCommand(std::vector<Shape*>& shapes, const std::string& command);