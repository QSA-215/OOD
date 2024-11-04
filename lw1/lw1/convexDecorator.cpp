#include "convexDecorator.h"

ConvexDecorator::ConvexDecorator(Convex* shape)
{
	m_shape = shape;
};
void ConvexDecorator::Draw(sf::RenderWindow& window)
{
	return this->m_shape->Draw(window);
};
bool ConvexDecorator::Contains(const sf::Vector2f& point) const
{
	return this->m_shape->Contains(point);
};
sf::Vector2f ConvexDecorator::GetPosition() const
{
	return this->m_shape->GetPosition();
};
void ConvexDecorator::Move(const sf::Vector2f& point)
{
	return this->m_shape->Move(point);
};
sf::Vector2f ConvexDecorator::GetRightDownCorner() const
{
	return this->m_shape->GetRightDownCorner();
};
void ConvexDecorator::Select(const bool select)
{
	return this->m_shape->Select(select);
};
bool ConvexDecorator::IsSelected() const
{
	return this->m_shape->IsSelected();
};
bool ConvexDecorator::IsGroup() const
{
	return this->m_shape->IsGroup();
};

std::string ConvexDecorator::GetParams() const
{
	return "TRIANGLE: P = " + std::to_string(GetPerimeter()) + "; S = " + std::to_string(GetArea());
};
float ConvexDecorator::GetPerimeter() const
{
	float perimeter = 0;
	perimeter += std::sqrt(std::pow(m_shape->GetPoint(1).x - m_shape->GetPoint(0).x, 2) + std::pow(m_shape->GetPoint(1).y - m_shape->GetPoint(0).y, 2));
	perimeter += std::sqrt(std::pow(m_shape->GetPoint(2).x - m_shape->GetPoint(1).x, 2) + std::pow(m_shape->GetPoint(2).y - m_shape->GetPoint(1).y, 2));
	perimeter += std::sqrt(std::pow(m_shape->GetPoint(0).x - m_shape->GetPoint(2).x, 2) + std::pow(m_shape->GetPoint(0).y - m_shape->GetPoint(2).y, 2));
	return perimeter;
};
float ConvexDecorator::GetArea() const
{
	const sf::Vector2f& p1 = m_shape->GetPoint(0);
	const sf::Vector2f& p2 = m_shape->GetPoint(1);
	const sf::Vector2f& p3 = m_shape->GetPoint(2);
	float line1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
	float line2 = std::sqrt(std::pow(p3.x - p2.x, 2) + std::pow(p3.y - p2.y, 2));
	float line3 = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));
	float semiperimeter = (line1 + line2 + line3) / 2;
	return std::sqrt(semiperimeter * (semiperimeter - line1) * (semiperimeter - line2) * (semiperimeter - line3));
};