#pragma once
#include "Scene.h"

class GameScene : public Scene
{
protected:

public:
	GameScene();
	~GameObject() = default;
	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
	void Reset();
	void Exit();
	void Release();
};

