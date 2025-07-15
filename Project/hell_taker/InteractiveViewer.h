#pragma once
#include "TextGo.h"
class InteractiveViewer : public TextGo
{
protected:
	sf::Text nameText;
	sf::Text lineText;
	sf::Text mixUp1;
	sf::Text mixUp2;

	sf::Sprite sprite;
	sf::Sprite backGroundSprite;
	sf::Sprite topButton;
	sf::Sprite downButton;

	sf::RectangleShape backGround;

	std::vector<std::string> texures;

	std::vector<std::string> names;
	std::vector<std::string> lines;
	std::vector<std::string> mixUp;

	int curIndex = 0;

	bool up = false;
	bool showMessageBox = false;

	sf::Vector2f targetSize = { 0.8f , 0.7f };
	sf::Vector2f curSize = { 0.75f , 0.6f };
	sf::Color initColor = { 101,61,72 };
	sf::Color selectColor = { 230, 77, 81 };
	float t = 0;
public:
	InteractiveViewer(const std::string& fontId = "", const std::string& name = "");
	~InteractiveViewer() override = default;

	void SettingCharacter(int idx);

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

