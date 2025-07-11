#include "stdafx.h"
#include "SpriteGo.h"

SpriteGo::SpriteGo(const std::string texId, const std::string name)
	:texId(texId)
	,GameObject(name)
{
}

void SpriteGo::SetPosition(const sf::Vector2f pos)
{
	position = pos;
	sprite.setPosition(pos);
}

void SpriteGo::SetRotaion(const float rot)
{
	rotation = rot;
	sprite.setRotation(rot);
}

void SpriteGo::SetOrigin(Origins preset)
{
	originPreset = preset;
	UTILS.SetOrigins(sprite, preset);
}

void SpriteGo::SetOrigin(sf::Vector2f ori)
{
	origin = ori;
	originPreset = Origins::Custom;
	sprite.setOrigin(ori);
}

void SpriteGo::Init()
{
	
}

void SpriteGo::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(texId));
}

void SpriteGo::Update(float dt)
{
}

void SpriteGo::Release()
{
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

sf::FloatRect SpriteGo::GetLocalBound()
{
	return sprite.getLocalBounds();
}

sf::FloatRect SpriteGo::GetGlobalBound()
{
	return sprite.getGlobalBounds();
}

void SpriteGo::SetScale(sf::Vector2f scale)
{
	this->scale = scale;
	sprite.setScale(scale);
}

void SpriteGo::Exit()
{
}
