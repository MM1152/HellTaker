#include "stdafx.h"
#include "MoveAbleObject.h"
#include "GameScene.h"
bool MoveAbleObject::CheckBound(int x, int y)
{
	if (x < 0 || y < 0) return false;
	else if (x > GameScene::mapData[0].size() - 1 || y > GameScene::mapData.size() - 1) return false;
	else if (GameScene::mapData[y][x] == 0) return false;

	return true;
}

MoveAbleObject::MoveAbleObject(const std::string texId, const std::string name)
	: SpriteGo(texId , name)
{
	
}

void MoveAbleObject::SetPosition(const sf::Vector2f pos)
{
	position = pos;
	sprite.setPosition({ pos.x + plusPos.x , pos.y + plusPos.y });
}

void MoveAbleObject::SetMapData(sf::Vector2f gridSize, int x, int y , SpriteTypes objectId)
{
	this->gridSize = gridSize;
	this->x = x;
	this->y = y;
	this->objectId = objectId;

	SetPosition({ gridSize.x * x , gridSize.y * y });
}

void MoveAbleObject::Update(float dt)
{
	SpriteGo::Update(dt);
	if (isMoveAble) {
		SetPosition(UTILS.Lerp(curPos, targetPos, t));
		t += 0.1f;
		if (t >= 1) {
			t = 0;
			isMoveAble = false;
		}
	}
}

void MoveAbleObject::Move(int upX, int upY)
{
	if (GameScene::mapData[y][x] != 8) {
		GameScene::mapData[y][x] = 1;
	}
	

	x += upX;
	y += upY;
	
	curPos = GetPosition();
	targetPos = { x * gridSize.x, y * gridSize.y };
	isMoveAble = true;
	GameScene::mapData[y][x] = (int)objectId + (int)Types::TYPECOUTN;
}




