#include "stdafx.h"
#include "GameScene.h"
#include "SpriteGo.h"

GameScene::GameScene()
	:Scene(SceneIds::SceneGame)
{
}

void GameScene::Init()
{
	texIds.push_back(SPRITE_PATH"assets100V20053.png");

	sp = new SpriteGo(SPRITE_PATH"assets100V20053.png");

	AddGameObject(sp);
	Scene::Init();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);
}

void GameScene::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void GameScene::Reset()
{
	UTILS.SetOrigins(sp.GetSprite(), Origins::MC);
	sp.SetPosition({ 1280 / 2 , 720 / 2 });
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
