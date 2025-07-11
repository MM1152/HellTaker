#pragma once
#include "GameObject.h"

enum class Types {
	WALL,
	TILE,
	NONE,
	TYPECOUTN,
};

enum class SpriteTypes {
	DELETE,
	PLAYER,
	OBSTACLE,
	ENEMY,
	MAP1NPC,
	NONE,
	SPRITECOUNT,
};

class Grid : public GameObject
{
protected:
	sf::RectangleShape rectangle;
	sf::Vector2f gridSize;

	SpriteTypes spriteType;
	Types type;

	sf::Sprite sp;
	
public:


	Grid(const sf::Vector2f gridSize , const std::string name = "");
	~Grid() override = default;
	// GameObject을(를) 통해 상속됨
	void SetPosition(const sf::Vector2f pos) override;
	void SetRotaion(const float rot) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(sf::Vector2f ori) override;
	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Exit() override;
	void Release() override;
	void Draw(sf::RenderWindow& window) override;
	sf::FloatRect GetLocalBound() override;
	sf::FloatRect GetGlobalBound() override;

	void SetOutLineColor(sf::Color color);

	// GameObject을(를) 통해 상속됨
	void SetScale(sf::Vector2f scale) override;
	void SetTypes(Types type) { this->type = type; };
	void SetTypes(SpriteTypes types);
	Types GetType() { return this->type; };
	SpriteTypes GetSpriteTypes() { return this->spriteType; };

};

