#pragma once
#include "ImmovableObstacle.h"
#include "Animator.h"
class Huddle : public ImmovableObstacle
{
protected:
	bool hitAble = true;

public:
	Huddle(const std::string& texId = "", const std::string& name = "");
	~Huddle() override;

	bool GetHitAble() { return hitAble; };
};

