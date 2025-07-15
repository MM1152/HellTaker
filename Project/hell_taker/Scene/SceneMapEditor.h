#pragma once
#include "Scene.h"
class SceneMapEditor : public Scene
{
protected:
	sf::Vector2f gridSize;
	sf::Vector2f gridCount;

	std::vector<std::vector<Grid*>> grids;

	Types type = Types::NONE;
	SpriteTypes spriteType = SpriteTypes::NONE;

	std::string mapIds[8];
	std::string mapGridsIds[8];
	sf::Sprite* mapImage;
	int mapIndex = 0;
public:
	SceneMapEditor();
	~SceneMapEditor() = default;
	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
	virtual void Reset();
	virtual void Exit();
	virtual void Release();

	void DrawGrid(sf::Vector2f cellSize, sf::Vector2f cellCount);
	void DrawGrid(std::vector<std::vector<float>>& lists);
};

