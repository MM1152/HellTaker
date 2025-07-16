#pragma once
#include "Obstacle.h"
#include "Animator.h"
class NPC : public Obstacle
{
protected:
	std::function<void()> finGame;

	Animator animator;
public:
	NPC(const std::string texId = "" , const std::string name = "");
	~NPC() override = default;

	void SettingCallBack(std::function<void()> callback) { finGame = callback; };
	void Reset() override;
	void ClearMap();
	void Update(float dt) override;
	void Move(int upX , int upY) override;
};

