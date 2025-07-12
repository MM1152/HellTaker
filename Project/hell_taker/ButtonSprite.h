#pragma once
#include "Button.h"
class ButtonSprite : public Button
{
protected:
	void SetString(const std::string tex) override {};
	void SetCharacterSize(size_t size) override {};

	std::string texId;
	sf::Sprite sprite;
public:
	ButtonSprite(const std::string texId = "", const std::string name = "");
	~ButtonSprite() override = default;

	void SetPosition(const sf::Vector2f pos) override;
	void SetRotaion(const float rot) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(sf::Vector2f ori) override;
	void SetScale(sf::Vector2f scale) override;

	void Draw(sf::RenderWindow& window) override;
	void Reset() override;
	
};

