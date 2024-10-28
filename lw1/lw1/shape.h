#pragma once
#include <SFML/Graphics.hpp>

class Shape
{
public:
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual float GetPerimeter() const = 0;
    virtual float GetArea() const = 0;
    virtual std::string GetParams() const = 0;
    virtual bool Contains(const sf::Vector2f& point) const = 0;
    virtual sf::Vector2f GetPosition() const = 0;
    virtual sf::Vector2f GetRightDownCorner() const = 0;
    virtual void Move(const sf::Vector2f& point) = 0;
    virtual void Select(const bool select) = 0;
    virtual bool IsSelected() const = 0;
    virtual bool IsGroup() const = 0;
    virtual ~Shape() {}
};