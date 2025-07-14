#pragma once
#include "SpriteGo.h"
class MoveAbleObject : public SpriteGo
{
protected:
	sf::Vector2f gridSize;
	
	SpriteTypes objectId;
	int x;
	int y;

	virtual bool CheckBound(int row , int height);

public:
	sf::Vector2f plusPos = { 0,0 };
	MoveAbleObject(const std::string texId = "", const std::string name = "");
	~MoveAbleObject() override = default;

	void SetPosition(const sf::Vector2f pos) override;
	void SetMapData(sf::Vector2f gridSize , int x , int y , SpriteTypes objectId);
	sf::Vector2i GetXY() { return { x , y }; };
	virtual void Move(int x , int y);
};

