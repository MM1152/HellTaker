#pragma once
#include "GameObject.h"
class BossLayser : public GameObject
{
protected:
	sf::CircleShape layser;
	sf::RectangleShape warningSign;

	sf::RectangleShape brightBackGorund;

	sf::Vector2f maxSize = { 18 , 8 };
	sf::Vector2f minSize = { 0 , 0 };
	
	float maxTimer = 1.0f;
	float middleTimer = 0.5f;
	float timer = 0.f;

	float t = 0;
	float duration = 1.f;
	float activeDuration = 8.f;
	
	bool isScaleUp = false;		
public:
	BossLayser(float radious, const std::string& name);
	~BossLayser() override = default;
	
	// GameObject을(를) 통해 상속됨
	void SetPosition(const sf::Vector2f pos) override;
	void SetRotaion(const float rot) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(sf::Vector2f ori) override;
	void SetScale(sf::Vector2f scale) override;
	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Exit() override;
	void Release() override;
	void Draw(sf::RenderWindow& window) override;
	sf::FloatRect GetLocalBound() override;
	sf::FloatRect GetGlobalBound() override;

	void Shoot();
};


