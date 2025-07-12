#pragma once
#include "Obstacle.h"
class Enemy : public Obstacle
{
protected:

public:
	Enemy(const std::string texId="" , const std::string name ="");
	~Enemy() override = default;

	void Move(int upX, int upY) override;
};

