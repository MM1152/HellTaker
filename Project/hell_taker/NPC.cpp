#include "stdafx.h"
#include "NPC.h"

NPC::NPC(const std::string texId, const std::string name)
	:Obstacle(texId , name)
{
}

void NPC::ClearMap()
{
	if (finGame) {
		finGame();
	}
}

void NPC::Move(int upX, int upY)
{
}
