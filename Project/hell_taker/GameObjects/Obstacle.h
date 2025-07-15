#pragma once
#include "MoveAbleObject.h"
class Obstacle : public MoveAbleObject
{
protected:
	bool CheckBound(int row, int height);
public:
	Obstacle(const std::string texId = "", const std::string name = "");
	~Obstacle() override = default;

	SpriteTypes GetType() { return objectId; };
	void Move(int upX, int upY) override;
	virtual void Interaction();
};

