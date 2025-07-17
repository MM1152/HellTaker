#pragma once
#include "GameObject.h"
#include "Animator.h";
class Boss : public GameObject
{
protected:
	sf::Sprite right;
	sf::Sprite left;


	Animator rightAni;
	Animator leftAni;

	std::string texId;
public:
	Boss(const std::string& texId = "" , const std::string& name = "");
	~Boss() override = default;
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
};

