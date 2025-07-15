#pragma once
#include "Scene.h"

class SpriteGo;
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
	std::string mapBackGround[8];
	SpriteGo* mapImage;
	int mapIndex = 0;

	bool isForGround = true;
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
	void DrawGrid(std::vector<std::vector<int>>& forGround , std::vector<std::vector<int>>& backGround);

	
};

