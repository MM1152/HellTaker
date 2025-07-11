#include "stdafx.h"
#include "SceneMgr.h"
#include "GameScene.h"
#include "SceneDev1.h"
void SceneMgr::Init()
{
	scenes.insert({ SceneIds::SceneGame , new GameScene() });
	scenes.insert({ SceneIds::Dev1 , new SceneDev1() });
	for (auto scene : scenes) {
		scene.second->Init();
	}

	currentScene = startScene;
	scenes[currentScene]->Reset();
}

void SceneMgr::Update(float dt)
{
	if (nextScene != SceneIds::None) {
		Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		Reset();
	}
	scenes[currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[currentScene]->Draw(window);
}

void SceneMgr::Release()
{
	for (auto scene : scenes) {
		scene.second->Release();
		delete scene.second;
	}

	scenes.clear();
}

void SceneMgr::Exit()
{
	scenes[currentScene]->Exit();
}

void SceneMgr::Reset()
{
	scenes[currentScene]->Reset();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;
}

Scene* SceneMgr::GetCurrentScene()
{
	if (currentScene != SceneIds::None) {
		return scenes[currentScene];
	}
	return nullptr;
}
