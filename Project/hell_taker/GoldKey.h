#pragma once
#include "ImmovableObstacle.h"
#include "Animator.h"

class GoldKey : public ImmovableObstacle
{
protected:
	Animator animator;

	sf::Sprite effectSprite;
	Animator effect;
public:
	GoldKey(const std::string& texId = "", const std::string& name = "");
	~GoldKey() override = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

