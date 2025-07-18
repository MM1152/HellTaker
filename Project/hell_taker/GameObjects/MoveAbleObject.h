#pragma once
#include "SpriteGo.h"
class MoveAbleObject : public SpriteGo
{
protected:
	sf::Vector2f gridSize;
	
	SpriteTypes objectId;
	int x;
	int y;

	bool isMoveAble = false;

	sf::Vector2f targetPos={ 0,0 };
	sf::Vector2f curPos = { 0,0 };
	float t = 0;
	float smooth = 10;
	virtual bool CheckBound(int row , int height);

public:
	sf::Vector2f plusPos = { 0,0 };
	MoveAbleObject(const std::string texId = "", const std::string name = "");
	~MoveAbleObject() override = default;

	void SetPosition(const sf::Vector2f pos) override;
	virtual void SetMapData(sf::Vector2f gridSize , int x , int y , SpriteTypes objectId);
	SpriteTypes GetObjectId() { return objectId; };
	sf::Vector2i GetXY() { return { x , y }; };
	void Update(float dt) override;
	virtual void Move(int x , int y);
};

