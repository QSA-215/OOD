#pragma once
#include "shapeFactory.h"

class Group : public Shape
{
public:
    void AddShape(Shape* shape) override;
    void DeleteShape(Shape* shape) override;
    void MakeFrame() override;
    std::vector<Shape*> GetShapes();
    std::string GetParams() const override;
    sf::Vector2f GetPosition() const override;
    sf::Vector2f GetRightDownCorner() const override;

    void Draw(sf::RenderWindow& window) override;
    void Move(const sf::Vector2f& point) override;
    void Select(const bool select) override;
    bool Contains(const sf::Vector2f& point) const override;
    bool IsEmpty() override;
    bool IsSelected() const override;
    bool IsGroup() const override;

private:
    std::vector<Shape*> m_group;
    sf::RectangleShape m_frame;
    bool m_isSelected = true;
};