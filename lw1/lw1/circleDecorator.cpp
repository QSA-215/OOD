#include "circleDecorator.h"
#define _USE_MATH_DEFINES
#include <math.h>

CircleDecorator::CircleDecorator(Circle* shape)
{
	m_shape = shape;
};
void CircleDecorator::Draw(sf::RenderWindow& window)
{
	return this->m_shape->Draw(window);
};
bool CircleDecorator::Contains(const sf::Vector2f& point) const
{
	return this->m_shape->Contains(point);
};
sf::Vector2f CircleDecorator::GetPosition() const
{
	return this->m_shape->GetPosition();
};
void CircleDecorator::Move(const sf::Vector2f& point)
{
	return this->m_shape->Move(point);
};
sf::Vector2f CircleDecorator::GetRightDownCorner() const
{
	return this->m_shape->GetRightDownCorner();
};
void CircleDecorator::Select(const bool select)
{
	return this->m_shape->Select(select);
};
bool CircleDecorator::IsSelected() const
{
	return this->m_shape->IsSelected();
};
bool CircleDecorator::IsGroup() const
{
	return this->m_shape->IsGroup();
};

std::string CircleDecorator::GetParams() const
{
	return "CIRCLE: P = " + std::to_string(GetPerimeter()) + "; S = " + std::to_string(GetArea());
};
float CircleDecorator::GetArea() const
{
	return M_PI * m_shape->GetRadius() * m_shape->GetRadius();
};
float CircleDecorator::GetPerimeter() const
{
	return M_PI * 2 * m_shape->GetRadius();
};