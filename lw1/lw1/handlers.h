#pragma once
#include "parser.h"

std::vector<Shape*> ReadShapesFromFile(const std::string inputFileName);
void WriteResultsInFile(const std::string& outputFileName, const std::vector<Shape*>& shapes);
void ShapesMoving(sf::RenderWindow& window, std::vector<Shape*>& shapes, std::vector<Group*>& groups, bool& isMove);
void ListenEvents(sf::RenderWindow& window, std::vector<Shape*>& shapes, std::vector<Group*>& groups, bool& isMove);
void DrawShapes(sf::RenderWindow& window, const std::vector<Shape*>& shapes, const std::vector<Group*>& groups);