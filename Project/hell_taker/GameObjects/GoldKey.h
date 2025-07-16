#pragma once
#include "ImmovableObstacle.h"
#include "Animator.h"

class GoldKey : public ImmovableObstacle
{
protected:
	Animator animator;
	Animator effect;

	bool getKey;
public:
	GoldKey(const std::string& texId = "", const std::string& name = "");
	~GoldKey() override = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void Interaction() override;
};

