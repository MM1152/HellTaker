#pragma once
#include "SpriteGo.h"
#include "Animator.h"
class MoveEffect : public SpriteGo
{
protected:
	Animator animator;
public:
	MoveEffect(const std::string& texId = "" , const std::string& name = "");
	~MoveEffect() override = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;

	void Play();
};

