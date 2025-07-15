#include "stdafx.h"
#include "Obstacle.h"
#include "GameScene.h"
bool Obstacle::CheckBound(int row, int height)
{
	if (!MoveAbleObject::CheckBound(row, height)) {
		return false;
	}

	if (MAP.GetTileData(height,row) != 1) {
		return false;
	}

	return true;
}

Obstacle::Obstacle(const std::string texId, const std::string name)
	:MoveAbleObject(texId , name)
{
}

void Obstacle::Move(int upX, int upY)
{
	if (CheckBound(x + upX, y + upY)) {
		MoveAbleObject::Move(upX, upY);
	}
}
//TODO : 나중에 로직 변경
void Obstacle::Interaction()	
{
}
