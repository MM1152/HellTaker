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
	sf::Vector2f cameraShakeMin = { 1920 / 2 - 3.f , 1080 / 2 - 3.f };
	sf::Vector2f cameraShakeMax = { 1920 / 2 + 3.f , 1080 / 2 + 3.f };
	sf::Vector2f initCameraPos = { 1920 / 2 , 1080 / 2 };

	float shakeTime = 0;
	float shakeSmooth = 0.04;

	bool shakeLeft = true;
	bool shakeRight = false;

	int count = -1;

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
	void CameraShake();
};

