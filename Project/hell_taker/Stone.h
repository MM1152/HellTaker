#pragma once
#include "Obstacle.h"
class Stone : public Obstacle
{
public:
	Stone(const std::string& texId = "", const std::string& name = "");
	~Stone() override = default;

	void Move(int upX, int upY) override;
};

