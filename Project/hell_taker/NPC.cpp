#include "stdafx.h"
#include "NPC.h"

NPC::NPC(const std::string texId, const std::string name)
	:Obstacle(texId , name)
{
}

void NPC::Reset()
{
	Obstacle::Reset();
	animator.SetTarget(&sprite);
	animator.Play(ANI_PATH"map1Npc.csv");
}

void NPC::ClearMap()
{
	if (finGame) {
		finGame();
	}
}

void NPC::Update(float dt)
{
	Obstacle::Update(dt);
	animator.Update(dt);
}

void NPC::Move(int upX, int upY)
{
}
