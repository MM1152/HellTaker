#include "stdafx.h"
#include "Enemy.h"
#include "GameScene.h"
Enemy::Enemy(const std::string texId, const std::string name)
	:Obstacle(texId , name)
{
}

void Enemy::Move(int upX, int upY)
{
	if (GameScene::mapData[y + upY][x + upX] != 1) {
		SetActive(false);
		GameScene::mapData[y][x] = 1;
		return;
	}
	Obstacle::Move(upX, upY);
}
