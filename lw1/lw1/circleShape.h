#pragma once
#include "shapeFactory.h"

class Circle : public Shape
{
public:
    Circle(float radius, sf::Vector2f position);
    float GetRadius() const;
    std::string GetParams() const override;
    sf::Vector2f GetPosition() const override;
    sf::Vector2f GetRightDownCorner() const override;

    void Draw(sf::RenderWindow& window) override;
    void Move(const sf::Vector2f& point) override;
    void Select(const bool select) override;
    bool Contains(const sf::Vector2f& point) const override;
    bool IsSelected() const override;
    bool IsGroup() const override;

private:
    sf::CircleShape m_circle;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;
};