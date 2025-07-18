#pragma once
#include "ImmovableObstacle.h"
#include "Layser.h"

class LayserBlock : public ImmovableObstacle
{
protected:
	sf::Sprite layserSprite;
	Layser* layser;

	sf::Vector2f maxSize = { 0.35f , 0.35f };
	sf::Vector2f minSize = { 0.2f , 0.2f };

	float t = 0;

	bool isSizeUp = false;
	bool isShoot = false;

	bool oneTime = true;
	void Shoot();
public:
	std::function<void()> shootNextLayser;

	LayserBlock(const std::string& texId = "", const std::string& name = "");
	~LayserBlock() override = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Exit() override;
	void Draw(sf::RenderWindow& window) override;

	void SetShoot();
	void SetPosition(sf::Vector2f pos) override;
};

