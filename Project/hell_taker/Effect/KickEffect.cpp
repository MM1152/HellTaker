#include "stdafx.h"
#include "KickEffect.h"

KickEffect::KickEffect(const std::string& texId, const std::string& name)
{
}

void KickEffect::Init()
{
	Effect::Init();
	animator.SetTarget(&sprite);
	animator.SetEvent("kickEffect", -1, [this]() {
		SetActive(false);
	});
}

void KickEffect::Reset()
{
	Effect::Reset();
	SetScale({ 0.8f , 0.8f });
	SetOrigin(Origins::MC);
	
}

void KickEffect::Play()
{
	SetActive(true);
	animator.Play(ANI_PATH"kickEffect.csv", true);
}
