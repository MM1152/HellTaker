#pragma once
#include "Obstacle.h"
class NPC : public Obstacle
{
protected:

public:
	NPC(const std::string texId = "" , const std::string name = "");
	~NPC() override = default;

	void Move(int upX , int upY) override;
};

