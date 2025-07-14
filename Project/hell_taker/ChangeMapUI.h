#pragma once
#include "TextGo.h"
#include "Animator.h"
class ChangeMapUI : public TextGo
{
protected:
	sf::Sprite sprite;
	std::string texId;

	Animator animator;
	bool playAnimation = false;
public:
	ChangeMapUI(const std::string& texId , const std::string& name);
	~ChangeMapUI() = default;

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
	void Play();
};

