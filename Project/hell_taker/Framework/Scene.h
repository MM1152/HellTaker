#pragma once
#include "GameObject.h"
class Scene
{
private:
	sf::Vector2f gridSize;
	sf::Vector2f gridCount;

	std::vector<std::vector<int>> infos;
protected:
	std::list<GameObject*> gameObjects;

	std::vector<std::string> texIds;
	std::vector<std::string> fontIds;

	SceneIds sceneId;

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;
	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
	virtual void Reset();
	virtual void Exit();
	virtual void Release();

	void AddGameObject(GameObject* obj);
	void RemoveGameObject(GameObject* obj);

	std::vector<std::vector<int>>& TranslateMapData(const std::vector<std::string>& mapData);
	sf::Vector2f GetGridSize() { return gridSize; };
	sf::Vector2f GetGridCount() { return gridCount; };
};

