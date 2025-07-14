#pragma once
#include "Obstacle.h"

class NPC : public Obstacle
{
protected:
	std::function<void()> finGame;
public:
	NPC(const std::string texId = "" , const std::string name = "");
	~NPC() override = default;


	void SettingCallBack(std::function<void()> callback) { finGame = callback; };
	void Move(int upX , int upY) override;
};

