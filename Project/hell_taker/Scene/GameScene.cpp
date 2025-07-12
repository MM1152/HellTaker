#include "stdafx.h"
#include "GameScene.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Grid.h"
#include "Player.h"
GameScene::GameScene()
	:Scene(SceneIds::SceneGame)
{
}

void GameScene::Init()
{
	fontIds.push_back(FONT_PATH"Amiri-Regular.ttf");

	texIds.push_back(SPRITE_PATH"chapterBG0001.png");
	texIds.push_back(SPRITE_PATH"chapterBG0002.png");
	texIds.push_back(SPRITE_PATH"chapterBG0003.png");
	texIds.push_back(SPRITE_PATH"chapterBG0004.png");
	texIds.push_back(SPRITE_PATH"chapterBG0005.png");
	texIds.push_back(SPRITE_PATH"chapterBG0006.png");
	texIds.push_back(SPRITE_PATH"chapterBG0007.png");
	texIds.push_back(SPRITE_PATH"chapterBG0008.png");

	texIds.push_back(SPRITE_PATH"assets100V20053.png");
	texIds.push_back(SPRITE_PATH"assets100V20081.png");

	mapIndex = 0;

	SpriteGo* backGround = new SpriteGo(MAP_IMAGE(mapIndex + 1));
	backGround->SetSortingLayer(SortingLayers::BACKGROUND);

	AddGameObject(backGround);
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
	Scene::Reset();
	//SETSCALE (0.7 , 0.7) �̶� ������ �׸��� ����� 0.7 ��������߉�
	mapData = TranslateMapData(UTILS.ReadFile(MAP_DATA(mapIndex + 1)));
	sf::Vector2f gridSize = GetGridSize() / 0.7f;
	sf::Vector2f gridCount = GetGridCount();

	for (int i = 0; i < mapData.size(); i++) {
		for (int j = 0; j < mapData[i].size(); j++) {
			if (mapData[i][j] > 3) {
				if (!player) {
					player = new Player(Grid::textureMap[(SpriteTypes)(mapData[i][j] - (int)Types::TYPECOUTN)]);
					player->Init();
					player->Reset();
					player->SetSortingLayer(SortingLayers::FORGROUND);
					AddGameObject(player);
				}
				player->SetPosition({ gridSize.x * j , gridSize.y * i });
				player->SetMapData(mapData, gridSize, j, i);
			}
		}
	}

}

void GameScene::Exit()
{
	Scene::Exit();
}

void GameScene::Release()
{
	Scene::Release();
}
