#pragma once
#include "stdafx.h"
#include "GameObject.h"

class SpriteGo : public GameObject
{
protected:
	std::string texId;
	sf::Sprite sprite;
	
public:
	SpriteGo(const std::string texId = "" , const std::string name = "");
	virtual ~SpriteGo() = default;

	// GameObject을(를) 통해 상속됨
	void SetPosition(const sf::Vector2f pos) override;
	void SetRotaion(const float rot) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(sf::Vector2f ori) override;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Release() override;
	void Draw(sf::RenderWindow& window) override;

	sf::Sprite& GetSprite() { return sprite; };
};

