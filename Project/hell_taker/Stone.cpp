#include "stdafx.h"
#include "Stone.h"

Stone::Stone(const std::string& texId, const std::string& name)
	:Obstacle(texId, name)
{
}

void Stone::Move(int upX, int upY)
{
	SOUND_MGR.Play(SoundTypes::STONE_KICK);
	Obstacle::Move(upX , upY);

	if (CheckBound(x + upX, y + upY)) {
		SOUND_MGR.Play(SoundTypes::STONE_MOVE);
	}
}
