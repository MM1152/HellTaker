#include "stdafx.h"
#include "HitEffect.h"

HitEffect::HitEffect(const std::string& texId, const std::string& name)
	:Effect(texId , name)
{
}

void HitEffect::Init()
{
	Effect::Init();
	animator.SetEvent("playerHit", -1, [this]() {
		SetActive(false);
	});
}

void HitEffect::Reset()
{
	Effect::Reset();
	SetScale({0.7f, 0.7f});
	SetOrigin(Origins::MC);
}

void HitEffect::Play()
{
	SetActive(true);
	SetPosition({ GetPosition().x + 40.f , GetPosition().y - 50.f });
	animator.Play(ANI_PATH"playerHit.csv" , true);
}
