#pragma once
#include "TextGo.h"
class Button : public TextGo
{
protected:
	sf::RectangleShape rect;

	std::function<void()> callback;
public:


	Button(const std::string fontId = "", const std::string name = "");
	~Button() override = default;

	void SetCharacterSize(size_t size) override;
	void SetString(const std::string tex) override;
	void SetPosition(const sf::Vector2f pos) override;
	void SetRotaion(const float rot) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(sf::Vector2f ori) override;
	void SetScale(sf::Vector2f scale) override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetCallBack(std::function<void()> callback);
	void OnClick();
};

