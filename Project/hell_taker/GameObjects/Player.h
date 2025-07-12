#pragma once
#include "MoveAbleObject.h"
#include "Obstacle.h"
class Player : public MoveAbleObject
{
private:
	void TestPrint();
protected:
	std::list<Obstacle*> obstacleList;
	sf::Vector2i inputKey;
	bool CheckBound(int row, int height) override;
public:
	Player(const std::string texId = "", const std::string name ="");
	~Player() override = default;

	void Update(float dt) override;
	void Reset() override;

	void AddObstacle(Obstacle* obs);
	
};

