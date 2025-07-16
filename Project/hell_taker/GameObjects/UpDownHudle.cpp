#include "stdafx.h"
#include "UpDownHudle.h"

UpDownHudle::UpDownHudle(const std::string& texId, const std::string& name)
	:Huddle(texId, name)
{
}

void UpDownHudle::Init()
{
	
	animator.SetTarget(&sprite);

	animator.SetEvent("huddleDown", -1, [this]() {
		animator.Stop();
	});
	animator.SetEvent("huddleUp", -1, [this]() {
		animator.Stop();
	});
}

void UpDownHudle::Reset()
{
	Huddle::Reset();
}

void UpDownHudle::Update(float dt)
{
	animator.Update(dt);
	SetOrigin(Origins::MB);
}

void UpDownHudle::Play()
{
	hitAble = !hitAble;
	
	if (!hitAble) animator.Play(ANI_PATH"huddleDown.csv" , true);
	else animator.Play(ANI_PATH"huddleUp.csv" , true);
	
}
