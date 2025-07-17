#pragma once
#include "ImmovableObstacle.h"
#include "Animator.h"

class Box : public ImmovableObstacle
{
protected:
	Animator effect;
	bool deleteBox = false;
public:
	Box(const std::string& texId = "", const std::string& name = "");
	~Box() override = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;

	void Interaction() override;
};

