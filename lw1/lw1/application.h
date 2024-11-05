#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "shapeFactory.h"

const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 800;
const std::string WINDOW_NAME = "";

class Application
{
public:
	Application();
	void Load(const std::string& INPUT_FILE_NAME, const std::string& OUTPUT_FILE_NAME);
	void Run();
	static std::shared_ptr<Application> GetInstance();

private:
	static std::shared_ptr<Application> m_instance;
	//sf::ContextSettings m_windowSettings;
	sf::RenderWindow m_window;
	std::vector<Shape*> m_shapes;
	bool m_isMove = false;
};