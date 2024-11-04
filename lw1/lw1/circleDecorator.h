#pragma once
#include "decoratorFactory.h"
#include "circleShape.h"

class CircleDecorator : public Decorator
{
public:
	CircleDecorator(Circle* shape);
	std::string GetParams() const override;
	void Draw(sf::RenderWindow& window) override;
	float GetArea() const override;
	float GetPerimeter() const override;
	bool Contains(const sf::Vector2f& point) const override;
	sf::Vector2f GetPosition() const override;
	void Move(const sf::Vector2f& point) override;
	sf::Vector2f GetRightDownCorner() const override;
	void Select(const bool select) override;
	bool IsSelected() const override;
	bool IsGroup() const override;
private:
	Circle* m_shape;
};