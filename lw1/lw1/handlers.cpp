#include <fstream>
#include "handlers.h"

std::vector<Shape*> ReadShapesFromFile(const std::string inputFileName)
{
	std::ifstream input(inputFileName);
	std::vector<Shape*> shapes;
	std::string command;
	while (std::getline(input, command))
		ParseCommand(shapes, command);
	input.close();
	return shapes;
};

void WriteResultsInFile(const std::string& outputFileName, const std::vector<Shape*>& shapes)
{
	std::ofstream output(outputFileName);
	for (auto shape : shapes)
		output << shape->GetParams() << std::endl;
	output.close();
};

void ShapesMoving(sf::RenderWindow& window, std::vector<Shape*>& shapes, std::vector<Group*>& groups, bool& isMove)
{
	static sf::Vector2i lastMousePosition;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!isMove)
		{
			isMove = true;
			lastMousePosition = sf::Mouse::getPosition(window);
		}
		sf::Vector2i currentPosition = sf::Mouse::getPosition(window);
		for (auto shape : shapes)
			if (shape->IsSelected())
				shape->Move(sf::Vector2f(currentPosition - lastMousePosition));
		for (auto group : groups)
			if (group->IsSelected())
				group->Move(sf::Vector2f(currentPosition - lastMousePosition));
		lastMousePosition = currentPosition;
	}
	else
		isMove = false;
};

void ListenEvents(sf::RenderWindow& window, std::vector<Shape*>& shapes, std::vector<Group*>& groups, bool& isMove)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			for (auto shape : shapes)
			{
				if (shape->Contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					shape->Select(true);
				}
				else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				{
					shape->Select(false);
				}
			}
			for (auto group : groups)
			{
				if (group->Contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					group->Select(true);
				}
				else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				{
					group->Select(false);
				}
			}
		}

		if (event.type == sf::Event::KeyPressed && event.key.control && event.key.code == sf::Keyboard::G)
		{
			Group* group = new Group;
			std::vector<int> tempShapes;
			for (int i = 0; i < shapes.size(); i++)
			{
				if (shapes[i]->IsSelected())
				{
					group->AddShape(shapes[i]);
					tempShapes.push_back(i);
				}
			}
			for (int i = tempShapes.size(); i-- > 0; )
			{
				shapes[tempShapes[i]]->Select(false);
				shapes.erase(shapes.begin() + tempShapes[i]);
			}
			if (!group->IsEmpty())
			{
				group->MakeFrame();
				groups.push_back(group);
			}
		}

		if (event.type == sf::Event::KeyPressed && event.key.control && event.key.code == sf::Keyboard::U)
		{
			if (!groups.empty())
			{
				Group* lastGroup = groups.back();
				if (!lastGroup->IsEmpty())
				{
					auto shapesFromGroup = lastGroup->GetShapes();
					shapes.push_back(shapesFromGroup.back());
					lastGroup->DeleteShape(shapesFromGroup.back());
				}
				else
				{
					groups.pop_back();
				}
			}
		}

		ShapesMoving(window, shapes, groups, isMove);
	}
};

void DrawShapes(sf::RenderWindow& window, const std::vector<Shape*>& shapes, const std::vector<Group*>& groups)
{
	for (auto shape : shapes)
		shape->Draw(window);

	for (auto group : groups)
		group->Draw(window);
};