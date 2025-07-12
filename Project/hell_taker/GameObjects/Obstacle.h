#pragma once
#include "MoveAbleObject.h"
class Obstacle : public MoveAbleObject
{
protected:

public:
	Obstacle(const std::string texId = "", const std::string name = "");
	~Obstacle() override = default;

	void Move(int upX, int upY) override;
};

