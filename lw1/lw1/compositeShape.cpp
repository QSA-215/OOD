#include "compositeShape.h"

void Group::MakeFrame()
{
    m_frame.setPosition(GetPosition());
    m_frame.setSize(sf::Vector2f(GetRightDownCorner().x - GetPosition().x, GetRightDownCorner().y - GetPosition().y));
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineThickness(2);
    m_frame.setOutlineColor(sf::Color::Green);
};
void Group::AddShape(Shape* shape)
{
    m_group.push_back(shape);
};
void Group::DeleteShape(Shape* shape)
{
    m_group.erase(std::remove(m_group.begin(), m_group.end(), shape), m_group.end());
};
std::vector<Shape*> Group::GetShapes()
{
    return m_group;
};
bool Group::IsEmpty()
{
    return m_group.empty();
};
void Group::Draw(sf::RenderWindow& window)
{
    for (auto shape : m_group)
        shape->Draw(window);
    if (m_isSelected)
        window.draw(m_frame);
};
std::string Group::GetParams() const
{
    return "";
};
bool Group::Contains(const sf::Vector2f& point) const
{
    for (auto shape : m_group)
        if (shape->Contains(point))
            return true;
    return false;
};
sf::Vector2f Group::GetPosition() const
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
sf::Vector2f Group::GetRightDownCorner() const
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
void Group::Move(const sf::Vector2f& point)
{
    for (auto shape : m_group)
        shape->Move(point);
    m_frame.move(point);
};
void Group::Select(const bool select)
{
    m_isSelected = select;
};
bool Group::IsSelected() const
{
    return m_isSelected;
};
bool Group::IsGroup() const
{
    return true;
};