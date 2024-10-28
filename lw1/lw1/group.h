#pragma once
#include "shape.h"

class Group : public Shape
{
public:
    void MakeFrame()
    {
        m_frame.setPosition(GetPosition());
        m_frame.setSize(sf::Vector2f(GetRightDownCorner().x - GetPosition().x, GetRightDownCorner().y - GetPosition().y));
        m_frame.setFillColor(sf::Color::Transparent);
        m_frame.setOutlineThickness(2);
        m_frame.setOutlineColor(sf::Color::Green);
    };
    void AddShape(Shape* shape)
    {
        m_group.push_back(shape);
    };
    void DeleteShape(Shape* shape)
    {
        m_group.erase(std::remove(m_group.begin(), m_group.end(), shape), m_group.end());
    };
    std::vector<Shape*> GetShapes()
    {
        return m_group;
    };
    bool IsEmpty()
    {
        return m_group.empty();
    };
    void Draw(sf::RenderWindow& window) override
    {
        for (auto shape : m_group)
            shape->Draw(window);
        if (m_isSelected)
            window.draw(m_frame);
    };
    float GetPerimeter() const override
    {return 0;};
    float GetArea() const override
    {return 0;};
    std::string GetParams() const override
    {return "";};
    bool Contains(const sf::Vector2f& point) const override
    {
        for (auto shape : m_group)
            if (shape->Contains(point))
                return true;
        return false;
    }
    sf::Vector2f GetPosition() const override
    {
        if (!m_group.empty())
        {
            float minX = m_group[0]->GetPosition().x;
            float minY = m_group[0]->GetPosition().y;
            for (auto shape : m_group)
            {
                if (shape->GetPosition().x < minX)
                    minX = shape->GetPosition().x;
                if (shape->GetPosition().y < minY)
                    minY = shape->GetPosition().y;
            }
            return sf::Vector2f(minX, minY);
        }
        return sf::Vector2f(0, 0);
    };
    sf::Vector2f GetRightDownCorner() const override
    {
        if (!m_group.empty())
        {
            float maxX = m_group[0]->GetRightDownCorner().x;
            float maxY = m_group[0]->GetRightDownCorner().y;
            for (auto shape : m_group)
            {
                if (shape->GetRightDownCorner().x > maxX)
                    maxX = shape->GetRightDownCorner().x;
                if (shape->GetRightDownCorner().y > maxY)
                    maxY = shape->GetRightDownCorner().y;
            }
            return sf::Vector2f(maxX, maxY);
        }
        return sf::Vector2f(0, 0);
    };
    void Move(const sf::Vector2f& point) override
    {
        for (auto shape : m_group)
            shape->Move(point);
        m_frame.move(point);
    };
    void Select(const bool select) override
    {
        m_isSelected = select;
    };
    bool IsSelected() const override
    {
        return m_isSelected;
    };
    bool IsGroup() const override
    {
        return true;
    };

private:
    std::vector<Shape*> m_group;
    sf::RectangleShape m_frame;
    bool m_isSelected = true;
};