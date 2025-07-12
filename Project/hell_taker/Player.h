#pragma once
#include "SpriteGo.h"
class Player : public SpriteGo
{
protected:
	std::vector<std::vector<int>> mapData;

	sf::Vector2f gridSize;

	int x;
	int y;

	bool CheckBound(int row , int height);
public:
	Player(const std::string texId = "", const std::string name = "");
	~Player() override = default;


	void Update(float dt) override;
	void SetMapData(std::vector<std::vector<int>>& mapData , sf::Vector2f gridSize , int x , int y);
	void Move();
};

