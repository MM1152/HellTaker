#include "stdafx.h"
#include "GameScene.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Grid.h"
#include "MoveAbleObject.h"
#include "Player.h"
#include "Obstacle.h"

std::vector<std::vector<int>> GameScene::mapData;

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

	player = new Player(UTILS.textureMap[SpriteTypes::PLAYER]);
	player->SetSortingLayer(SortingLayers::FORGROUND);

	AddGameObject(player);
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
	//SETSCALE (0.7 , 0.7) 이라 설정된 그리드 사이즈에 0.7 나누어줘야됌
	mapData = TranslateMapData(UTILS.ReadFile(MAP_DATA(mapIndex + 1)));
	sf::Vector2f gridSize = GetGridSize() / 0.7f;
	sf::Vector2f gridCount = GetGridCount();

	for (int i = 0; i < mapData.size(); i++) {
		for (int j = 0; j < mapData[i].size(); j++) {
			if (mapData[i][j] > 3) {
				if (mapData[i][j] == (int)SpriteTypes::PLAYER + (int)Types::TYPECOUTN) {
					player->SetPosition({ gridSize.x * j , gridSize.y * i });
					player->SetMapData(gridSize, j, i , mapData[i][j] - (int)Types::TYPECOUTN);
				}
				if (mapData[i][j] == (int)SpriteTypes::OBSTACLE + (int)Types::TYPECOUTN) {
					Obstacle* ob = new Obstacle(UTILS.textureMap[SpriteTypes::OBSTACLE]);
					AddGameObject(ob);
					ob->Init();
					ob->Reset();
					ob->SetPosition({gridSize.x * j , gridSize.y * i});
					ob->SetMapData(gridSize, j, i, mapData[i][j] - (int)Types::TYPECOUTN);
					player->AddObstacle(ob);
					
				}
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
