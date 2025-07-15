#include "stdafx.h"
#include "ImmovableObstacle.h"

ImmovableObstacle::ImmovableObstacle(const std::string& texId, const std::string& name)
	:Obstacle(texId , name)
{
}

void ImmovableObstacle::Move(int upX, int upY)
{
}
