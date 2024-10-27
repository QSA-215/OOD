#pragma once
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(sf::Vector2f size, sf::Vector2f position)
    {
        m_rectangle.setSize(size);
        m_rectangle.setPosition(position);
        m_rectangle.setOutlineThickness(2);
        m_rectangle.setFillColor(sf::Color::Black);
        m_rectangle.setOutlineColor(sf::Color::Red);

        m_frame.setPosition(m_rectangle.getGlobalBounds().getPosition());
        m_frame.setSize(sf::Vector2f(m_rectangle.getGlobalBounds().width, m_rectangle.getGlobalBounds().height));
        m_frame.setFillColor(sf::Color::Transparent);
        m_frame.setOutlineThickness(2);
        m_frame.setOutlineColor(sf::Color::Magenta);
    };
    void Draw(sf::RenderWindow& window) override
    {
        window.draw(m_rectangle);
        if (m_isSelected)
            window.draw(m_frame);
    };
    float GetPerimeter() const override // возможно убрать
    {
        return 2 * (m_rectangle.getSize().x + m_rectangle.getSize().y);
    };
    float GetArea() const override // возможно убрать
    {
        return m_rectangle.getSize().x * m_rectangle.getSize().y;
    };
    std::string GetParams() const override
    {
        return "P = " + std::to_string(GetPerimeter()) + "; S = " + std::to_string(GetArea());
    };
    bool Contains(const sf::Vector2f& point) const override
    {
        return m_rectangle.getGlobalBounds().contains(point);
    }
    sf::Vector2f GetPosition() const override
    {
        return m_rectangle.getPosition();
    };
    void Move(const sf::Vector2f& point) override
    {
        m_rectangle.move(point);
        m_frame.move(point);
    };
    sf::Vector2f GetRightDownCorner() const override
    {
        return sf::Vector2f(2, 2);
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
    sf::RectangleShape m_rectangle;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;
};