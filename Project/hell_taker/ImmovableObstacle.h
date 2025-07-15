#pragma once
#include "Obstacle.h"
class ImmovableObstacle : public Obstacle
{
protected:

public:
	ImmovableObstacle(const std::string& texId = "", const std::string& name = "");
	~ImmovableObstacle() override = default;

	void Move(int upX , int upY) override;
};

