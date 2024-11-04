#include <SFML/Graphics.hpp>
#include "handlers.h"
#include "application.h"
const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 800;
const std::string WINDOW_NAME = "";

void Application(const std::string& INPUT_FILE_NAME, const std::string& OUTPUT_FILE_NAME)
{
	// window creating
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Default, settings);

	// some work
	std::vector<Shape*> shapes = ReadShapesFromFile(INPUT_FILE_NAME);
	WriteResultsInFile(OUTPUT_FILE_NAME, shapes);

	bool isMove = false;

	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		ListenEvents(window, shapes, isMove);
		DrawShapes(window, shapes);
		window.display();
	}
}