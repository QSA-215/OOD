#include "parser.h"

std::vector<float> ParseParameters(const std::string& command)
{
	std::vector<float> parameters;
	std::string temp = command.substr(command.find("=") + 1, command.find(";") - command.find("=") - 1);
	parameters.push_back(std::stof(temp.substr(0, temp.find(","))));
	parameters.push_back(std::stof(temp.substr(temp.find(",") + 1)));
	temp = command.substr(command.find(";") + 2);
	if (temp.find(",") == std::string::npos)
	{
		parameters.push_back(std::stof(temp.substr(2)));
	}
	else if (temp.find(";") == std::string::npos)
	{
		parameters.push_back(std::stof(temp.substr(3, temp.find(","))));
		parameters.push_back(std::stof(temp.substr(temp.find(",") + 1)));
	}
	else
	{
		parameters.push_back(std::stof(temp.substr(3, temp.find(","))));
		parameters.push_back(std::stof(temp.substr(temp.find(",") + 1, temp.find(";") - temp.find(",") - 1)));
		temp = temp.substr(temp.find(";") + 2);
		parameters.push_back(std::stof(temp.substr(3, temp.find(","))));
		parameters.push_back(std::stof(temp.substr(temp.find(",") + 1)));
	}
	return parameters;
};

Shape* ParseCircle(const std::vector<float>& parameters)
{
	return new Circle(parameters[2], sf::Vector2f(parameters[0], parameters[1]));
};

Shape* ParseRectangle(const std::vector<float>& parameters)
{
	return new Rectangle(sf::Vector2f(parameters[2] - parameters[0], parameters[3] - parameters[1]), sf::Vector2f(parameters[0], parameters[1]));
};

Shape* ParseTriangle(const std::vector<float>& parameters)
{
	return new Convex(3, std::vector<sf::Vector2f> {sf::Vector2f(parameters[0], parameters[1]), sf::Vector2f(parameters[2], parameters[3]), sf::Vector2f(parameters[4], parameters[5])});
};

void ParseCommand(std::vector<Shape*>& shapes, const std::string& command)
{
	std::string figureName = command.substr(0, command.find(" "));
	if (figureName == "CIRCLE:")
	{
		Shape* circle = ParseCircle(ParseParameters(command));
		Shape* circleDecorator = new CircleDecorator(circle);
		shapes.push_back(circleDecorator);
	}
	else if (figureName == "RECTANGLE:")
	{
		Shape* rectangle = ParseRectangle(ParseParameters(command));
		Shape* rectangleDecorator = new RectangleDecorator(rectangle);
		shapes.push_back(rectangleDecorator);
	}
	else if (figureName == "TRIANGLE:")
	{
		Shape* triangle = ParseTriangle(ParseParameters(command));
		Shape* triangleDecorator = new ConvexDecorator(triangle);
		shapes.push_back(triangleDecorator);
	}
};