#pragma once
#include "GameObject.h"
class Scene
{
protected:
	std::unordered_map<std::string, Scene*> scenes;
	std::list<GameObject*> gameObjects;

	std::vector<std::string> texIds;

	SceneIds startScene = SceneIds::SceneGame;
	SceneIds currentScene = SceneIds::None;
	SceneIds nextScene = SceneIds::None;
public:
	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
	virtual void Reset();
	virtual void Exit();
	virtual void Release();

	void AddGameObject(GameObject* obj);
};

