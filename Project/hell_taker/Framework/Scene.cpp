#include "stdafx.h"
#include "Scene.h"

Scene::Scene(SceneIds id)
	:sceneId(id)
{
}

void Scene::Init()
{
	for (auto obj : gameObjects) {
		obj->Init();
	}
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
	TEXTURE_MGR.Load(texIds);

	for (auto obj : gameObjects) {
		obj->Reset();
	}
}

void Scene::Exit()
{
	TEXTURE_MGR.UnLoad();

	for (auto obj : gameObjects) {
		obj->Exit();
	}
}

void Scene::Release()
{
	for (auto obj : gameObjects) {
		obj->Release();
		delete obj;
	}

	gameObjects.clear();
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
			if ((*iter)->GetSortingOrder() >= obj->GetSortingOrder()) {
				gameObjects.insert(iter, obj);
				isInput = true;
				break;
			}
		}
		iter++;
	}

	if (!isInput)
		gameObjects.push_back(obj);
}
