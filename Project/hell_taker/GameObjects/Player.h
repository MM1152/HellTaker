#pragma once
#include "MoveAbleObject.h"
#include "Obstacle.h"
#include "Animator.h"
class Player : public MoveAbleObject
{
private:
	void TestPrint();
protected:
	Animator animator;
	std::list<Obstacle*> obstacleList;
	sf::Vector2i inputKey;
	bool CheckBound(int row, int height) override;
public:
	sf::Vector2f plusPos = { 0,0 };

	Player(const std::string texId = "", const std::string name ="");
	~Player() override = default;

	void Init() override;
	void Update(float dt) override;
	void Reset() override;

	void AddObstacle(Obstacle* obs);
	
};

