#pragma once
#include "SpriteGo.h"
#include "Animator.h"

class Effect : public SpriteGo
{
protected:
	Animator animator;
public:
	Effect(const std::string& texId = "", const std::string& name = "");
	~Effect() override = default;

	void Init() override;
	void Update(float dt) override;

	virtual void Play() = 0;
};

