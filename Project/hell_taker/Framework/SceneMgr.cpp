#include "stdafx.h"
#include "SceneMgr.h"
#include "GameScene.h"
#include "SceneDev1.h"
#include "SceneMapEditor.h"
#include "TextGo.h"

void SceneMgr::Init()
{
	
	font.loadFromFile(FONT_PATH"Amiri-Regular.ttf");
	fps.setFont(font);

	scenes.insert({ SceneIds::SceneGame , new GameScene() });
	scenes.insert({ SceneIds::Dev1 , new SceneDev1() });
	scenes.insert({ SceneIds::SceneMapEditor , new SceneMapEditor() });
	for (auto scene : scenes) {
		scene.second->Init();
	}

	currentScene = startScene;
	scenes[currentScene]->Reset();
	fps.setFillColor(sf::Color::Green);
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

	if (timer >= 1 && showFPS) {
		float dtInMs = dt * 1000.f;
		float fpss = 1000.f / dtInMs;

		fps.setString("FPS: " + std::to_string(static_cast<int>(fpss)));
		timer = 0;
	}

	if (INPUT_MGR.GetKeyDown(KEY::F)) {
		showFPS = !showFPS;
	}

	timer += dt;

	
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[currentScene]->Draw(window);

	if (showFPS) {
		window.draw(fps);
	}
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
