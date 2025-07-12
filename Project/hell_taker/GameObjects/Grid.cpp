#include "stdafx.h"
#include "Grid.h"

std::unordered_map<SpriteTypes, std::string> Grid::textureMap;

Grid::Grid(const sf::Vector2f gridSize , const std::string name)
    :GameObject(name)
    ,gridSize(gridSize)
    ,type(Types::WALL)
    ,spriteType(SpriteTypes::NONE)
  
{
    SetSortingLayer(SortingLayers::UI);
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

    rectangle.setOrigin(origin);
}

void Grid::SetOrigin(sf::Vector2f ori)
{
    origin = ori;
    originPreset = Origins::Custom;
    rectangle.setOrigin(ori);
}

void Grid::Init()
{
    rectangle.setSize({gridSize.x , gridSize.y});
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setOutlineThickness(0.5f);
   
    textureMap.insert({SpriteTypes::PLAYER , SPRITE_PATH"assets100V20053.png"});
    textureMap.insert({SpriteTypes::OBSTACLE , SPRITE_PATH"assets100V20081.png"});
}

void Grid::Reset()
{
}

void Grid::Update(float dt)
{
    if (type == Types::WALL) {
        SetOutLineColor(sf::Color::Red);
    }
    if (type == Types::TILE) {
        SetOutLineColor(sf::Color::Blue);
    }
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
    window.draw(sp);
}

sf::FloatRect Grid::GetLocalBound()
{
    return rectangle.getLocalBounds();
}

sf::FloatRect Grid::GetGlobalBound()
{
    return rectangle.getGlobalBounds();
}

void Grid::SetOutLineColor(sf::Color color)
{
    rectangle.setOutlineColor(color);
}

void Grid::SetScale(sf::Vector2f scale)
{
    this->scale = scale;
    rectangle.setScale(scale);
}

void Grid::SetTypes(SpriteTypes types)
{
    spriteType = types;

    if (spriteType == SpriteTypes::DELETE) {
        sp.setColor(sf::Color::Transparent);
    }
    else if (spriteType != SpriteTypes::NONE) {
        sp.setTexture(TEXTURE_MGR.Get(textureMap[types]));
        sp.setColor(sf::Color::White);
        sp.setPosition(rectangle.getPosition());
        sp.setScale({ 0.7f , 0.7f });
    }
    
}
