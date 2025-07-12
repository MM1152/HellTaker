#include "stdafx.h"
#include "Obstacle.h"

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
