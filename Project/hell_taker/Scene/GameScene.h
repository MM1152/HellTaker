#pragma once
#include "Scene.h"

class SpriteGo;
class Player;
class Obstacle;
class TextGo;
class ChangeMapUI;
class InteractiveViewer;
class GameScene : public Scene
{
protected:
	Player* player = nullptr;
	ChangeMapUI* changeMapUI;
	SpriteGo* backGround;

	SpriteGo* moveCountUI;
	SpriteGo* moveCountUIBackGround;
	SpriteGo* mapIndexUI;
	SpriteGo* mapIndexUIBackGround;

	InteractiveViewer* interactive;

	TextGo* moveCountText;
	TextGo* mapIndexText;
public:


	GameScene();
	~GameScene() = default;

	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
	void Reset();
	void Exit();
	void Release();
	void AddObs(Obstacle* ob, SpriteTypes types, sf::Vector2f gridSize, int i, int j);

	void ResetScene();
};

