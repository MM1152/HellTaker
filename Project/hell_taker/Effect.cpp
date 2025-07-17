#include "stdafx.h"
#include "Effect.h"

Effect::Effect(const std::string& texId, const std::string& name)
	:SpriteGo(texId , name)
{
}

void Effect::Init()
{
	animator.SetTarget(&sprite);
}

void Effect::Update(float dt)
{
	if (GetActive()) {
		animator.Update(dt);
	}
}
