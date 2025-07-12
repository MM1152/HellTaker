#include "stdafx.h"
#include "ButtonSprite.h"

ButtonSprite::ButtonSprite(const std::string texId, const std::string name)
	:texId(texId)
	,Button("" , name)
{
}

void ButtonSprite::SetPosition(const sf::Vector2f pos)
{
	Button::SetPosition(pos);
	sprite.setPosition(pos);
}

void ButtonSprite::SetRotaion(const float rot)
{
	Button::SetRotaion(rot);
	sprite.setRotation(rot);
}

void ButtonSprite::SetOrigin(Origins preset)
{
	Button::SetOrigin(preset);
	UTILS.SetOrigins(sprite, preset);
}

void ButtonSprite::SetOrigin(sf::Vector2f ori)
{
	Button::SetOrigin(ori);
	sprite.setOrigin(ori);
}

void ButtonSprite::SetScale(sf::Vector2f scale)
{
	Button::SetScale(scale);
	sprite.setScale(scale);
}

void ButtonSprite::Draw(sf::RenderWindow& window)
{
	window.draw(rect);
	window.draw(sprite);
}

void ButtonSprite::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(texId));

	if (sprite.getLocalBounds().width == 0) {
		rect.setSize({ 75, 75 });
	}
	else {
		rect.setSize({ sprite.getLocalBounds().width , sprite.getLocalBounds().height });
	}
}
