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
	bool isPlayAnimation = false;
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
	void ChangeAnimation(const std::string& id);

	void Move(int upX, int upY) override;
	
	std::list<Obstacle*>& GetObstacleList() { return obstacleList; };
};

