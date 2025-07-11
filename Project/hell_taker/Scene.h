#pragma once
#include "GameObject.h"
class Scene
{
protected:
	std::unordered_map<std::string, Scene*> scenes;
	std::list<GameObject*> gameObjects;
public:
	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
	void Reset();
	
	void AddGameObject(GameObject* obj);
};

