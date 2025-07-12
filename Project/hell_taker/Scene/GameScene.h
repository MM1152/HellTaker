#pragma once
#include "Scene.h"

class SpriteGo;
class Player;
class GameScene : public Scene
{
protected:
	Player* player = nullptr;

	int mapIndex;
	
public:
	GameScene();
	~GameScene() = default;

	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
	void Reset();
	void Exit();
	void Release();

	static std::vector<std::vector<int>> mapData;
};

