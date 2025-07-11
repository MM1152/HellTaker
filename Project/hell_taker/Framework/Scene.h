#pragma once
#include "GameObject.h"
class Scene
{
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
};

