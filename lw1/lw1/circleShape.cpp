#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "circleShape.h"

Circle::Circle(float radius, sf::Vector2f position)
{
    m_circle.setRadius(radius);
    m_circle.setPosition(position);
    m_circle.setFillColor(sf::Color::Black);
    m_circle.setOutlineThickness(2);
    m_circle.setOutlineColor(sf::Color::Red);

    m_frame.setPosition(m_circle.getGlobalBounds().getPosition());
    m_frame.setSize(sf::Vector2f(m_circle.getGlobalBounds().width, m_circle.getGlobalBounds().height));
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineThickness(2);
    m_frame.setOutlineColor(sf::Color::Magenta);
};
void Circle::Draw(sf::RenderWindow& window)
{
    window.draw(m_circle);
    if (m_isSelected)
        window.draw(m_frame);
};
std::string Circle::GetParams() const
{
    return "";
};
float Circle::GetRadius() const
{
    return m_circle.getRadius();
};
bool Circle::Contains(const sf::Vector2f& point) const
{
    return m_circle.getGlobalBounds().contains(point);
}
sf::Vector2f Circle::GetPosition() const
{
    return m_circle.getGlobalBounds().getPosition();
};
sf::Vector2f Circle::GetRightDownCorner() const
{
    return sf::Vector2f(m_circle.getGlobalBounds().getPosition().x + m_circle.getGlobalBounds().width, m_circle.getGlobalBounds().getPosition().y + m_circle.getGlobalBounds().height);
};
void Circle::Move(const sf::Vector2f& point)
{
    m_circle.move(point);
    m_frame.move(point);
};
void Circle::Select(const bool select)
{
    m_isSelected = select;
};
bool Circle::IsSelected() const
{
    return m_isSelected;
};
bool Circle::IsGroup() const
{
    return false;
};