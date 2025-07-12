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
	FONT_MGR.Load(fontIds);

	for (auto obj : gameObjects) {
		obj->Reset();
	}
}

void Scene::Exit()
{
	TEXTURE_MGR.UnLoad();
	FONT_MGR.UnLoad();

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

void Scene::RemoveGameObject(GameObject* obj)
{
	gameObjects.remove(obj);
	delete obj;
}

std::vector<std::vector<int>>& Scene::TranslateMapData(const std::vector<std::string>& mapData)
{
	infos.clear();

	for (int i = 0; i < mapData.size() - 2; i++) {
		std::vector<int> vec;
		for (int j = 0; j < mapData[i].size(); j++) {
			vec.push_back(mapData[i][j] - '0');
		}
		infos.push_back(vec);
	}

	//FIX XYÃà ¹Ý´ë·ÎµÊ
	gridCount = { (float)mapData[0].size() , (float)mapData.size() - 2 };
	gridSize = { std::stof(mapData[mapData.size() - 1]) , std::stof(mapData[mapData.size() - 2]) };

	return infos;
}
