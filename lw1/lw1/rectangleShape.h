#pragma once
#include "shapeFactory.h"

class Rectangle : public Shape
{
public:
    Rectangle(sf::Vector2f size, sf::Vector2f position);
    std::string GetParams() const override;
    sf::Vector2f GetSides() const;
    sf::Vector2f GetPosition() const override;
    sf::Vector2f GetRightDownCorner() const override;

    void Draw(sf::RenderWindow& window) override;
    void Move(const sf::Vector2f& point) override;
    void Select(const bool select) override;
    bool Contains(const sf::Vector2f& point) const override;
    bool IsSelected() const override;
    bool IsGroup() const override;

private:
    sf::RectangleShape m_rectangle;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;
};