#pragma once
#include "SpriteGo.h"
#include "Effect.h"

class MoveEffect : public Effect
{
protected:

public:
	MoveEffect(const std::string& texId = "" , const std::string& name = "");
	~MoveEffect() override = default;

	void Init() override;
	void Reset() override;

	void Play() override;
};

