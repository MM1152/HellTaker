#include "stdafx.h"
#include "MoveEffect.h"

MoveEffect::MoveEffect(const std::string& texId, const std::string& name)
	:Effect(texId,  name)
{
}

void MoveEffect::Init()
{
	Effect::Init();
	animator.SetEvent("moveEffect", -1, [this]() {
		SetActive(false);
	});
}

void MoveEffect::Reset()
{	
	Effect::Reset();
	SetOrigin(Origins::MC);
	SetScale({0.7f, 0.7f});
}
	

void MoveEffect::Play()
{
	SetActive(true);
	SetPosition({ GetPosition().x + 20.f, GetPosition().y + 50.f});
	
	animator.Play(ANI_PATH"moveEffect.csv" , true);
}
