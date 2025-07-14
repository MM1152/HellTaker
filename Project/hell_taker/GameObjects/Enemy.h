#pragma once
#include "Obstacle.h"
#include "Animator.h"
class Enemy : public Obstacle
{
protected:
	Animator animator;
public:
	Enemy(const std::string texId="" , const std::string name ="");
	~Enemy() override = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Move(int upX, int upY) override;
};

