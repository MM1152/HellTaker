#pragma once
#include "Scene.h"
class SceneDev1 : public Scene
{
protected:


public:
	SceneDev1();
	~SceneDev1() = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;

	void DrawGrid(sf::Vector2f cellSize , sf::Vector2f cellCount);
};

