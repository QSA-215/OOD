#pragma once
#include "convexShape.h"
#include <cmath>

Convex::Convex(int pointsAmount, std::vector<sf::Vector2f> points)
{
    m_convex.setPointCount(pointsAmount);
    for (int i = 0; i < pointsAmount; i++)
    {
        m_convex.setPoint(i, points[i]);
    }
    m_convex.setFillColor(sf::Color::Black);
    m_convex.setOutlineThickness(2);
    m_convex.setOutlineColor(sf::Color::Red);

    m_frame.setPosition(m_convex.getGlobalBounds().getPosition());
    m_frame.setSize(sf::Vector2f(m_convex.getGlobalBounds().width, m_convex.getGlobalBounds().height));
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineThickness(2);
    m_frame.setOutlineColor(sf::Color::Magenta);
};
void Convex::Draw(sf::RenderWindow& window)
{
    window.draw(m_convex);
    if (m_isSelected)
        window.draw(m_frame);
};
std::string Convex::GetParams() const
{
    return "";
};
sf::Vector2f Convex::GetPoint(const int pointNumber) const
{
    return m_convex.getPoint(pointNumber);
};
bool Convex::Contains(const sf::Vector2f& point) const
{
    return m_convex.getGlobalBounds().contains(point);
};
sf::Vector2f Convex::GetPosition() const
{
    return m_convex.getGlobalBounds().getPosition();
};
void Convex::Move(const sf::Vector2f& point)
{
    m_convex.move(point);
    m_frame.move(point);
};
sf::Vector2f Convex::GetRightDownCorner() const
{
    return sf::Vector2f(m_convex.getGlobalBounds().getPosition().x + m_convex.getGlobalBounds().width - m_convex.getOutlineThickness(), m_convex.getGlobalBounds().getPosition().y + m_convex.getGlobalBounds().height - m_convex.getOutlineThickness());
};
void Convex::Select(const bool select)
{
    m_isSelected = select;
};
bool Convex::IsSelected() const
{
    return m_isSelected;
};
bool Convex::IsGroup() const
{
    return false;
};