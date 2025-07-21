#include "stdafx.h"
#include "GoldKey.h"

GoldKey::GoldKey(const std::string& texId, const std::string& name)
	:ImmovableObstacle(texId , name)
{
}

void GoldKey::Init()
{
	animator.SetTarget(&sprite);
	effect.SetTarget(&sprite);
}

void GoldKey::Reset()
{
	ImmovableObstacle::Reset();
	getKey = false;
	SetScale({ 0.8f , 0.8f });

	animator.Play(ANI_PATH"goldKey.csv");
	effect.Play(ANI_PATH"goldKeyEffect.csv" , true);

	effect.SetEvent("goldKeyEffect", -1, [this]() {
		SetActive(false);
		effect.Stop();
	});

	effect.SetEvent("goldKeyEffect", 1 ,[this]() {
		SetPosition(GetPosition() - plusPos * 0.8f);
	});

	SetOrigin(Origins::MC);
}

void GoldKey::Update(float dt)
{
	if (getKey) {
		effect.Update(dt);
	}
	else {
		animator.Update(dt);
	}
}


void GoldKey::Interaction()
{
	getKey = true;
	SOUND_MGR.Play(SoundTypes::KEY_PICKUP);
}


