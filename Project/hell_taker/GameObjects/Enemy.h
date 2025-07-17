#pragma once
#include "Obstacle.h"
#include "Animator.h"

class Player;
class Enemy : public Obstacle
{
protected:
	Animator animator;
	Player* player;
public:
	Enemy(const std::string texId="" , const std::string name ="");
	~Enemy() override = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Move(int upX, int upY) override;

	void CheckUnderHuddle();
	void SettingPlayer(Player* player) {
		this->player = player;
	}
};

