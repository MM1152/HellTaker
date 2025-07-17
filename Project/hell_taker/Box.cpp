#include "stdafx.h"
#include "Box.h"

Box::Box(const std::string& texId, const std::string& name)
	:ImmovableObstacle(texId , name)
{
}

void Box::Init()
{
	ImmovableObstacle::Init();
	effect.SetEvent("goldKeyEffect", -1, [this]() {
		SetActive(false);
	});
}

void Box::Reset()
{
	ImmovableObstacle::Reset();
	deleteBox = false;
}

void Box::Update(float dt)
{
	ImmovableObstacle::Update(dt);
	if (deleteBox) {
		effect.Update(dt);
	}
}

void Box::Interaction()
{
	deleteBox = true;
	effect.SetTarget(&sprite);
	effect.Play(ANI_PATH"goldKeyEffect.csv" , true);
	SetPosition({ GetPosition().x - 100.f , GetPosition().y - 80.f });
}
