#include "stdafx.h"
#include "Scene.h"

void Scene::Init()
{
}

void Scene::Update(float dt)
{
	for (auto obj : gameObjects) {
		obj->Update(dt);
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	for (auto obj : gameObjects) {
		if(obj->GetActive())
			obj->Draw(window);
	}
}

void Scene::Reset()
{
	for (auto obj : gameObjects) {
		obj->Reset();
	}
}

void Scene::AddGameObject(GameObject* obj)
{
	if (gameObjects.empty()) {
		gameObjects.push_back(obj);
		return;
	}
	
	auto iter = gameObjects.begin();
	bool isInput = false;
	while (iter != gameObjects.end()) {
		if ((*iter)->GetSortingLayer() > (obj->GetSortingLayer())) {
			gameObjects.insert(iter, obj);
			isInput = true;
			break;
		}
		else if ((*iter)->GetSortingLayer() == (obj->GetSortingLayer())) {
			gameObjects
		}
		iter++;
	}
}
