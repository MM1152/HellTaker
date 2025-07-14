#include "stdafx.h"
#include "ChangeMapUI.h"

ChangeMapUI::ChangeMapUI(const std::string& texId, const std::string& name)
	:texId(texId)
	,TextGo("",name)
{
	sortingOrder = 5;
}

void ChangeMapUI::SetPosition(const sf::Vector2f pos)
{
	position = pos;
	sprite.setPosition(pos);
}

void ChangeMapUI::SetRotaion(const float rot)
{
	rotation = rot;
	sprite.setRotation(rot);
}

void ChangeMapUI::SetOrigin(Origins preset)
{
	originPreset = preset;
	UTILS.SetOrigins(sprite, preset);
}

void ChangeMapUI::SetOrigin(sf::Vector2f ori)
{
	origin = ori;
	sprite.setOrigin(ori);
}

void ChangeMapUI::SetScale(sf::Vector2f scale)
{
	this->scale = scale;
	sprite.setScale(scale);
}

void ChangeMapUI::Init()
{
	animator.SetTarget(&sprite);
}

void ChangeMapUI::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(texId));

	
	//SetPosition({ 0 , 1080 - 100 });
	animator.Play(ANI_PATH"changeMap.csv" , true);
	SetActive(false);
	animator.SetEvent("changeMap", [this]() {
		playAnimation = false;
		SetActive(false);
	});
}

void ChangeMapUI::Update(float dt)
{
	if (playAnimation) {
		animator.Update(dt);
		SetPosition({0, 1080.f - sprite.getLocalBounds().height});
	}
}

void ChangeMapUI::Exit()
{
}

void ChangeMapUI::Release()
{
}

void ChangeMapUI::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void ChangeMapUI::Play()
{
	playAnimation = true;
	SetActive(true);
}
