#include "stdafx.h"
#include "GoldKey.h"

GoldKey::GoldKey(const std::string& texId, const std::string& name)
	:ImmovableObstacle(texId , name)
{
}

void GoldKey::Init()
{
	animator.SetTarget(&sprite);
	effect.SetTarget(&effectSprite);
}

void GoldKey::Reset()
{
	ImmovableObstacle::Reset();
	SetScale({ 0.8f , 0.8f });
	effectSprite.setScale(GetScale());
	animator.Play(ANI_PATH"goldKey.csv");

	effect.SetEvent("goldKeyEffect", -1, [this]() {
		SetActive(false);
	});
}

void GoldKey::Update(float dt)
{
	animator.Update(dt);
	effect.Update(dt);
}

void GoldKey::Draw(sf::RenderWindow& window)
{
	ImmovableObstacle::Draw(window);
	window.draw(effectSprite);	
}
