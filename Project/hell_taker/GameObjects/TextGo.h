#pragma once
#include "GameObject.h"
class TextGo : public GameObject
{
protected:
	sf::Text text;
	std::string fontId;
public:
	TextGo(const std::string fontId = "", const std::string name = "");
	virtual ~TextGo() = default;

	virtual void SetString(const std::string tex);
	virtual void SetCharacterSize(size_t size);
	void ChangeColor(sf::Color color);
	std::string GetString() { return text.getString(); };
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

	void SetFillColor(sf::Color color);

};

