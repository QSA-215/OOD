#include "rectangleDecorator.h"

RectangleDecorator::RectangleDecorator(Rectangle* shape)
{
	m_shape = shape;
};
void RectangleDecorator::Draw(sf::RenderWindow& window)
{
	return this->m_shape->Draw(window);
};
bool RectangleDecorator::Contains(const sf::Vector2f& point) const
{
	return this->m_shape->Contains(point);
};
sf::Vector2f RectangleDecorator::GetPosition() const
{
	return this->m_shape->GetPosition();
};
void RectangleDecorator::Move(const sf::Vector2f& point)
{
	return this->m_shape->Move(point);
};
sf::Vector2f RectangleDecorator::GetRightDownCorner() const
{
	return this->m_shape->GetRightDownCorner();
};
void RectangleDecorator::Select(const bool select)
{
	return this->m_shape->Select(select);
};
bool RectangleDecorator::IsSelected() const
{
	return this->m_shape->IsSelected();
};
bool RectangleDecorator::IsGroup() const
{
	return this->m_shape->IsGroup();
};

std::string RectangleDecorator::GetParams() const
{
	return "RECTANGLE: P = " + std::to_string(GetPerimeter()) + "; S = " + std::to_string(GetArea());
};
float RectangleDecorator::GetPerimeter() const
{
	return 2 * (m_shape->GetSides().x + m_shape->GetSides().y);
};
float RectangleDecorator::GetArea() const
{
	return m_shape->GetSides().x * m_shape->GetSides().y;
};