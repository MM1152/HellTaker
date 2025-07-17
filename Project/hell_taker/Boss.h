#pragma once
#include "GameObject.h"
#include "Animator.h";
#include "BossHuddle.h"
#include "Player.h"

class GameScene;
class Boss : public GameObject
{
protected:
	int workAbleRow = 5;
	int workAbleHeight = 6;

	int workAbleMaxHeight = 9;
	int workAbleMaxRow = 13;

	int huddleCount = 7;
	int spawnHuddleX = 6;
	int spawnHuddleY = 6;

	int attackCount = 0;

	sf::Sprite right;
	sf::Sprite left;

	Animator rightAni;
	Animator leftAni;

	std::string texId;

	GameScene* gameScene;

	std::list<BossHuddle*> bossHuddlsPool;
	std::list<BossHuddle*> bossHuddles;

	Player* player;
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

	void SettingGameScene(GameScene* gameScene) { this->gameScene = gameScene; };
	void Attack1(int count ,int row, int height);
	void SetNextHuddle(int row, int height);
	void SetPlayer(Player* player) { this->player = player; };


};

