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
}

void SpriteGo::SetOrigin(sf::Vector2f ori)
{
	origin = ori;
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
