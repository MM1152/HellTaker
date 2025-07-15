#include "stdafx.h"
#include "MoveEffect.h"

MoveEffect::MoveEffect(const std::string& texId, const std::string& name)
	:SpriteGo(texId,  name)
{
}

void MoveEffect::Init()
{
	animator.SetTarget(&sprite);
	animator.SetEvent("moveEffect", -1, [this]() {
		SetActive(false);
	});
}

void MoveEffect::Reset()
{
	SetScale({0.7f, 0.7f});
	SetOrigin(Origins::RB);
}

void MoveEffect::Update(float dt)
{
	if (GetActive()) {
		animator.Update(dt);	
	}
	
}

void MoveEffect::Play()
{
	SetActive(true);
	SetPosition({ GetPosition().x + 20.f , GetPosition().y + 40.f });
	animator.Play(ANI_PATH"moveEffect.csv");
}
