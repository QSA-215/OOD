#pragma once
#include "shape.h"
#include <cmath>

class Convex : public Shape
{
public:
    Convex(int pointsAmount, std::vector<sf::Vector2f> points)
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
    void Draw(sf::RenderWindow& window) override
    {
        window.draw(m_convex);
        if (m_isSelected)
            window.draw(m_frame);
    };
    float GetPerimeter() const override // возможно убрать
    {
        float perimeter = 0;
        const int pointsAmount = m_convex.getPointCount();
        for (int i = 0; i < pointsAmount - 1; i++)
        {
            perimeter += std::sqrt(std::pow(m_convex.getPoint(i + 1).x - m_convex.getPoint(i).x, 2) + std::pow(m_convex.getPoint(i + 1).y - m_convex.getPoint(i).y, 2));
        }
        perimeter += std::sqrt(std::pow(m_convex.getPoint(0).x - m_convex.getPoint(pointsAmount - 1).x, 2) + std::pow(m_convex.getPoint(0).y - m_convex.getPoint(pointsAmount - 1).y, 2));
        return perimeter;
    };
    float GetArea() const override // возможно убрать
    {
        const sf::Vector2f& p1 = m_convex.getPoint(0);
        const sf::Vector2f& p2 = m_convex.getPoint(1);
        const sf::Vector2f& p3 = m_convex.getPoint(2);
        float line1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
        float line2 = std::sqrt(std::pow(p3.x - p2.x, 2) + std::pow(p3.y - p2.y, 2));
        float line3 = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));
        float semiperimeter = (line1 + line2 + line3) / 2;
        return std::sqrt(semiperimeter * (semiperimeter - line1) * (semiperimeter - line2) * (semiperimeter - line3));
    };
    std::string GetParams() const override
    {
        return "P = " + std::to_string(GetPerimeter()) + "; S = " + std::to_string(GetArea());
    };
    bool Contains(const sf::Vector2f& point) const override
    {
        return m_convex.getGlobalBounds().contains(point);
    }
    sf::Vector2f GetPosition() const override
    {
        return m_convex.getGlobalBounds().getPosition();
    };
    void Move(const sf::Vector2f& point) override
    {
        m_convex.move(point);
        m_frame.move(point);
    };
    sf::Vector2f GetRightDownCorner() const override
    {
        return sf::Vector2f(m_convex.getGlobalBounds().getPosition().x + m_convex.getGlobalBounds().width - m_convex.getOutlineThickness(), m_convex.getGlobalBounds().getPosition().y + m_convex.getGlobalBounds().height - m_convex.getOutlineThickness());
    };
    void Select(const bool select) override
    {
        m_isSelected = select;
    };
    bool IsSelected() const override
    {
        return m_isSelected;
    };


private:
    sf::ConvexShape m_convex;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;
};