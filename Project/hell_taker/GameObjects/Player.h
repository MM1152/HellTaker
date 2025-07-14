#pragma once
#include "MoveAbleObject.h"
#include "Obstacle.h"
#include "Animator.h"
class Player : public MoveAbleObject
{
private:
	
protected:
	Animator animator;
	std::list<Obstacle*> obstacleList;
	sf::Vector2i inputKey;
	bool CheckBound(int row, int height) override;
public:
	void TestPrint();

	Player(const std::string texId = "", const std::string name ="");
	~Player() override = default;

	void Exit() override;
	void Init() override;
	void Update(float dt) override;
	void Reset() override;
	void AddObstacle(Obstacle* obs);
	
	std::list<Obstacle*>& GetObstacleList() { return obstacleList; };
};

