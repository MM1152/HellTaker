#pragma once
#include "TextGo.h"
#include "Animator.h"

class GameScene;
class InteractiveViewer : public TextGo
{
protected:
	Animator iconAnimation;
	Animator successAnimation;
	Animator badEndAnimation;

	sf::Text nameText;
	sf::Text lineText;
	sf::Text mixUp1;
	sf::Text mixUp2;

	sf::Sprite sprite;
	sf::Sprite backGroundSprite;
	sf::Sprite topButton;
	sf::Sprite downButton;
	sf::Sprite succecsSprite;
	sf::Sprite badEndSprite;

	sf::Sprite icon;

	sf::RectangleShape backGround;

	std::vector<std::string> textures;

	std::string name;
	std::vector<std::string> lines;
	std::vector<std::string> mixUp;
	int correct;

	bool up = false;
	bool showMessageBox = false;
	bool clear = false;
	bool badClear = false;
	bool badSelect = false;

	sf::Vector2f targetSize = { 0.8f , 0.7f };
	sf::Vector2f curSize = { 0.75f , 0.6f };
	sf::Color initColor = { 101,61,72 };
	sf::Color selectColor = { 230, 77, 81 };
	float t = 0;

	GameScene* gameScene;
public:
	InteractiveViewer(const std::string& fontId = "", const std::string& name = "");
	~InteractiveViewer() override = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetGameScene(GameScene* scene) { gameScene = scene; };
};

