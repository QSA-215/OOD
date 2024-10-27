#pragma once
#include "shape.h"

class Decorator : public Shape
{
public:
	Decorator(Shape* shape)
	{
		m_shape = shape;
	};
	void Draw(sf::RenderWindow& window) override
	{
		return this->m_shape->Draw(window);
	};
	float GetArea() const override
	{
		return this->m_shape->GetArea();
	};
	float GetPerimeter() const override
	{
		return this->m_shape->GetPerimeter();
	};
	std::string GetParams() const override
	{
		return this->m_shape->GetParams();
	};
	bool Contains(const sf::Vector2f& point) const override
	{
		return this->m_shape->Contains(point);
	};
	sf::Vector2f GetPosition() const override
	{
		return this->m_shape->GetPosition();
	};
	void Move(const sf::Vector2f& point) override
	{
		return this->m_shape->Move(point);
	};
	sf::Vector2f GetRightDownCorner() const override
	{
		return this->m_shape->GetRightDownCorner();
	};
	void Select(const bool select) override
	{
		return this->m_shape->Select(select);
	};
	bool IsSelected() const override
	{
		return this->m_shape->IsSelected();
	};

protected:
	Shape* m_shape;
};