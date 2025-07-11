#pragma once
#include "Scene.h"
class Grid;
class SceneDev1 : public Scene
{
protected:
	sf::Vector2f gridSize;
	sf::Vector2f gridCount;
	std::vector<std::vector<Grid*>> grids;

	Types type = Types::NONE;

	std::string mapIds[8];
	std::string mapGridsIds[8];
	sf::Sprite* mapImage;
	int mapIndex = 0;

public:
	SceneDev1();
	~SceneDev1() = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void DrawGrid(sf::Vector2f cellSize , sf::Vector2f cellCount);
	void DrawGrid(std::vector<std::string>& lists);
};

