#include "stdafx.h"
#include "Grid.h"

Grid::Grid(const sf::Vector2f gridSize , const std::string name)
    :GameObject(name)
    ,gridSize(gridSize)
{
}

void Grid::SetPosition(const sf::Vector2f pos)
{
    position = pos;
    rectangle.setPosition(pos);
}

void Grid::SetRotaion(const float rot)
{
    rotation = rot;
    rectangle.setRotation(rot);
}

void Grid::SetOrigin(Origins preset)
{
    originPreset = preset;
    sf::Vector2f origin;
    sf::FloatRect rect = rectangle.getLocalBounds();
    origin.x = rect.width * (((int)preset % 3) * 0.5f);
    origin.y = rect.height * (((int)preset / 3) * 0.5f);
}

void Grid::SetOrigin(sf::Vector2f ori)
{
    origin = ori;
    originPreset = Origins::Custom;
    rectangle.setOrigin(ori);
}

void Grid::Init()
{
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setOutlineThickness(5.f);
    rectangle.setSize(gridSize);
}

void Grid::Reset()
{
}

void Grid::Update(float dt)
{
}

void Grid::Exit()
{
}

void Grid::Release()
{
}

void Grid::Draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}

sf::FloatRect Grid::GetLocalBound()
{
    return sf::FloatRect();
}

sf::FloatRect Grid::GetGlobalBound()
{
    return sf::FloatRect();
}
