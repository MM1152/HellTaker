#pragma once
#include "SpriteGo.h"

class Player;
class Layser : public SpriteGo
{
protected:
	sf::CircleShape circle;
	sf::Vector2f maxSize = { 14.5f , 0.6f };
	sf::Vector2f minsize = { 0.f , 0.f };

	float timer = 0.0f;
	float maxTime = 0.5f;
	float middleTimer = 0.3f;
	float t = 0;
	float duration = 0.1f;
	bool hitAble = false;
	bool isScaleUp = true;

	int height = 0;

	Player* player;
public:
	Layser(const std::string& texId = "" , const std::string name = "");
	~Layser() override = default;

	void Reset() override;
	void Update(float dt) override;
	void Shoot();
	void Draw(sf::RenderWindow& window) override;
	//void SetInfo(sf::Vector2f maxSize , sf::Vector2f minSize , float maxTime , float middleTime , float duration , float activeDuration);
	void SetHeight(int height) { this->height = height; };
	float GetTimer(){ return timer; };
};

