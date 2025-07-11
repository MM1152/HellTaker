#include "stdafx.h"
#include "Button.h"

Button::Button(const std::string fontId, const std::string name)
	:TextGo(fontId , name)
{
}

void Button::SetCharacterSize(size_t size)
{
	TextGo::SetCharacterSize(size);
	SetString(text.getString());
}

void Button::SetString(const std::string tex)
{
	TextGo::SetString(tex);
	rect.setSize({(float)tex.size() * text.getCharacterSize() * 0.6f , (float)text.getCharacterSize() * 1.5f});
}

void Button::SetPosition(const sf::Vector2f pos)
{
	TextGo::SetPosition(pos);
	rect.setPosition(pos);
}

void Button::SetRotaion(const float rot)
{
	TextGo::SetRotaion(rot);
	rect.setRotation(rot);
}

void Button::SetOrigin(Origins preset)
{
	TextGo::SetOrigin(preset);

	sf::Vector2f origin;
	sf::FloatRect rect = this->rect.getLocalBounds();
	origin.x = rect.width * (((int)preset % 3) * 0.5f);
	origin.y = rect.height * (((int)preset / 3) * 0.5f);

	this->rect.setOrigin(origin);
}

void Button::SetOrigin(sf::Vector2f ori)
{
	TextGo::SetOrigin(ori);
	rect.setOrigin(ori);
}

void Button::SetScale(sf::Vector2f scale)
{
	TextGo::SetScale(scale);
	rect.setScale(scale);
}


void Button::Update(float dt)
{
	
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(rect);
	TextGo::Draw(window);
}

void Button::SetCallBack(std::function<void()> callback)
{
	this->callback = callback;
}

void Button::OnClick()
{
	if (callback) {
		callback();
	}
}
