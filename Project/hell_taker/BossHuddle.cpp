#include "stdafx.h"
#include "BossHuddle.h"

BossHuddle::BossHuddle(const std::string& texId, const std::string& name)
	:Huddle(texId , name)
{
}

void BossHuddle::Init()
{
	Huddle::Init();
	animator.SetTarget(&sprite);
}

void BossHuddle::Reset()
{
	Huddle::Reset();
	SetScale({ 0.8f , 0.8f });
	animator.SetEvent("bossHuddle", 8, [this]() {
		hitAble = true;
	});
	animator.SetEvent("bossHuddle", 8, [this]() {
		if (callBack) {
			callBack(GetXY().x , GetXY().y + 1);
		}
	});
	animator.SetEvent("bossHuddle", -1, [this]() {
		hitAble = false;
		animator.Stop();
		SetActive(false);
	});

	
}

void BossHuddle::SetReset()
{
	hitAble = false;
	SetActive(true);
	animator.Play(ANI_PATH"bossHuddle.csv" , true);
	//SetPosition(spawnPos);
}

void BossHuddle::Update(float dt)
{
	if (GetActive()) {
		animator.Update(dt);
		SetOrigin(Origins::MB);
	}

	if (hitAble && player->GetXY().x == x && player->GetXY().y == y) {
		player->SetMoveCount(-1);
		player->Die();
	}

}
