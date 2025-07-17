#include "stdafx.h"
#include "Enemy.h"
#include "GameScene.h"
#include "Player.h"
#include "Huddle.h"
Enemy::Enemy(const std::string texId, const std::string name)
	:Obstacle(texId , name)
{
}

void Enemy::Init()
{
	Obstacle::Init();
	animator.SetTarget(&sprite);
	animator.SetEvent("enemyKicked", -1 , [this]() {
		animator.Play(ANI_PATH"enemyIdle.csv");
	});
}

void Enemy::Reset()
{
	Obstacle::Reset();
	animator.Play(ANI_PATH"enemyIdle.csv");
	sprite.setScale(0.8f, 0.8f);
	SetOrigin(Origins::MC);
}

void Enemy::Update(float dt)
{
	Obstacle::Update(dt);
	animator.Update(dt);
}

void Enemy::Move(int upX, int upY)
{
	if (MAP.GetTileData(y + upY , x + upX)!= 1) {
		SetActive(false);
		//GameScene::mapData[y][x] = 1;
		return;
	}
	animator.Play(ANI_PATH"enemyKicked.csv");
	Obstacle::Move(upX, upY);
	
}

void Enemy::CheckUnderHuddle()
{
	for (auto huddle : player->GetObstacleList()) {
		if (huddle->GetType() == SpriteTypes::HUDLE || huddle->GetType() == SpriteTypes::DOWNUPHUDDLE || huddle->GetType() ==		SpriteTypes::UPDOWNHUDLE) {
			Huddle* hud = (Huddle*)huddle;
			if (huddle->GetXY().x == x && huddle->GetXY().y == y && hud->GetHitAble()) {
				SetActive(false);
			}
		}
		
	}
}
