#pragma once
#include "Scene.h"
class Grid;
class SceneDev1 : public Scene
{
protected:
	sf::Vector2f cameraShakeMin = { 1920 / 2 - 2.f , 1080 / 2};
	sf::Vector2f cameraShakeMax = { 1920 / 2 + 2.f , 1080 / 2};
	sf::Vector2f initCameraPos = { 1920 / 2 , 1080 / 2 };

	float shakeTime = 0;
	float shakeSmooth = 0.05;

	bool shakeLeft = true;
	bool shakeRight = false;

	int count = 1;
public:
	SceneDev1();
	~SceneDev1() = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void CameraShake();
};

