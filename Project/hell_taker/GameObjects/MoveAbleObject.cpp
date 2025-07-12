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

void MoveAbleObject::SetMapData(sf::Vector2f gridSize, int x, int y , int objectId)
{
	this->gridSize = gridSize;
	this->x = x;
	this->y = y;
	this->objectId = objectId;
}

void MoveAbleObject::Move(int upX, int upY)
{
	GameScene::mapData[y][x] = 1;

	x += upX;
	y += upY;
	SetPosition({x * gridSize.x , y * gridSize.y});
	GameScene::mapData[y][x] = objectId;
}




