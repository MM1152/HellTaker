#pragma once
#include "MoveAbleObject.h"
#include "Obstacle.h"
#include "Animator.h"
#include "MoveEffect.h"
class Player : public MoveAbleObject
{
private:
	
protected:
	Animator animator;
	MoveEffect moveEffect;
	sf::RectangleShape dieAnimationBackGround;
	bool isDie = false;

	std::list<Obstacle*> obstacleList;
	sf::Vector2i inputKey;
	bool isPlayAnimation = false;

	int moveCount = 0;
	std::function<void(int)> changeMoveCountFunc;
	std::function<void()> changeMapAnimationFunc;
	
	bool CheckBound(int row, int height) override;
public:
	void TestPrint();

	Player(const std::string texId = "", const std::string name ="");
	~Player() override = default;

	void Exit() override;
	void Init() override;
	void Update(float dt) override;
	void Reset() override;
	void Draw(sf::RenderWindow& window) override;
	void AddObstacle(Obstacle* obs);
	void ChangeAnimation(const std::string& id , bool resetTextureRect = false);

	void Move(int upX, int upY) override;
	void SetMoveCount(int count) {
		moveCount = count;
	};

	int GetMoveCount() { return moveCount; };
	bool Die();
	void SetMoveCountFunc(std::function<void(int)> callBack) { changeMoveCountFunc = callBack; };
	void SetChangeMapFunc(std::function<void()> callBack) { changeMapAnimationFunc = callBack; };
	std::list<Obstacle*>& GetObstacleList() { return obstacleList; };
};

