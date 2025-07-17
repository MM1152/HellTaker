#pragma once
#include "Huddle.h"
#include "Animator.h"
#include "Player.h"
class BossHuddle : public Huddle
{
protected:
	Animator animator;
	Player* player;
public:
	std::function<void(int ,int)> callBack;

	BossHuddle(const std::string& texId = "", const std::string& name = "");
	~BossHuddle() override = default;

	void Init() override;
	void Reset() override;
	void SetReset();
	void Update(float dt) override;

	void SetPlayer(Player* player) { this->player = player; };
};

