#pragma once
#include "SpriteGo.h"
class Layser : public SpriteGo
{
protected:
	sf::Vector2f maxSize = { 14.5f , 0.8f };
	sf::Vector2f minsize = { 0.f , 0.f };

	float timer = 0.0f;
	float maxTime = 0.5f;
	float middleTimer = 0.3f;
	float t = 0;

	bool hitAble = false;
	bool isScaleUp = true;
public:
	Layser(const std::string& texId = "" , const std::string name = "");
	~Layser() override = default;

	void Reset() override;
	void Update(float dt) override;
	void Shoot();
	void Draw(sf::RenderWindow& window) override;
};

