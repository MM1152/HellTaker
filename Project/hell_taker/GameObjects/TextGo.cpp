#include "stdafx.h"
#include "TextGo.h"

TextGo::TextGo(const std::string fontId, const std::string name)
    :GameObject(name)
    ,fontId(fontId)
{
    SetSortingLayer(SortingLayers::UI);
    SetFillColor(sf::Color::Black);
}

void TextGo::SetString(const std::string tex)
{
    text.setString(tex);
    if (originPreset != Origins::Custom) {
        SetOrigin(originPreset);
    }
}

void TextGo::SetCharacterSize(size_t size)
{
    text.setCharacterSize(size);
}

void TextGo::ChangeColor(sf::Color color)
{
    text.setFillColor(color);
}

void TextGo::SetPosition(const sf::Vector2f pos)
{
    position = pos;
    text.setPosition(pos);
}

void TextGo::SetRotaion(const float rot)
{
    rotation = rot;
    text.setRotation(rot);
}

void TextGo::SetOrigin(Origins preset)
{
    originPreset = preset;
    UTILS.SetOrigins(text , preset);
}

void TextGo::SetOrigin(sf::Vector2f ori)
{
    origin = ori;
    originPreset = Origins::Custom;
    text.setOrigin(ori);
}

void TextGo::Init()
{
}

void TextGo::Reset()
{
    text.setFont(FONT_MGR.Get(fontId));
}

void TextGo::Update(float dt)
{
}

void TextGo::Exit()
{
}

void TextGo::Release()
{
}

void TextGo::Draw(sf::RenderWindow& window)
{
    window.draw(text);
}

sf::FloatRect TextGo::GetLocalBound()
{
    return text.getLocalBounds();
}

sf::FloatRect TextGo::GetGlobalBound()
{
    return text.getGlobalBounds();
}

void TextGo::SetFillColor(sf::Color color)
{
    text.setFillColor(color);
}

void TextGo::SetScale(sf::Vector2f scale)
{
    this->scale = scale;
    text.setScale(scale);
}
