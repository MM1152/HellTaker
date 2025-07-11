#include "stdafx.h"
#include "GameScene.h"
#include "SpriteGo.h"
#include "TextGo.h"
GameScene::GameScene()
	:Scene(SceneIds::SceneGame)
{
}

void GameScene::Init()
{
	texIds.push_back(SPRITE_PATH"assets100V20053.png");
	fontIds.push_back(FONT_PATH"Amiri-Regular.ttf");

	sp = new SpriteGo(SPRITE_PATH"assets100V20053.png");
	TextGo* text = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	text->SetString("GAMESCENE");

	AddGameObject(text);
	AddGameObject(sp);
	Scene::Init();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);
	if (INPUT_MGR.GetKeyDown(KEY::Enter)) {
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
}

void GameScene::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void GameScene::Reset()
{
	sp->SetOrigin(Origins::MC);
	sp->SetPosition({ 1280 / 2 , 720 / 2 });
	Scene::Reset();
}

void GameScene::Exit()
{
	Scene::Exit();
}

void GameScene::Release()
{
	Scene::Release();
}
