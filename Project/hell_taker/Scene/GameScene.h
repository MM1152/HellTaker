#pragma once
#include "Scene.h"

class SpriteGo;
class GameScene : public Scene
{
protected:
	SpriteGo* sp;
public:
	GameScene();
	~GameScene() = default;

	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
	void Reset();
	void Exit();
	void Release();
};

