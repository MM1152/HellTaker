#include "stdafx.h"
#include "GameScene.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Grid.h"
#include "MoveAbleObject.h"
#include "Player.h"
#include "Obstacle.h"
#include "Enemy.h"
#include "NPC.h"
#include "ChangeMapUI.h"
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
	texIds.push_back(SPRITE_PATH"mainUIexport_fUI0001.png");
	texIds.push_back(SPRITE_PATH"mainUIexport_bUI2.png");

	texIds.push_back(UTILS.textureMap[SpriteTypes::PLAYER]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::OBSTACLE]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::ENEMY]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::MAP1NPC]);

	aniIds.push_back(ANI_PATH"playerIdle.csv");
	aniIds.push_back(ANI_PATH"enemyIdle.csv");
	aniIds.push_back(ANI_PATH"enemyKicked.csv");
	aniIds.push_back(ANI_PATH"playerKick.csv");
	aniIds.push_back(ANI_PATH"playerMove.csv");
	aniIds.push_back(ANI_PATH"map1Npc.csv");
	aniIds.push_back(ANI_PATH"changeMap.csv");

	mapIndex = 0;

	SpriteGo* backGround = new SpriteGo(MAP_IMAGE(mapIndex + 1));
	
	backGround->SetSortingLayer(SortingLayers::BACKGROUND);
	player = new Player(UTILS.textureMap[SpriteTypes::PLAYER]);
	player->SetSortingLayer(SortingLayers::FORGROUND);

	changeMapUI = new ChangeMapUI("" , "");

	moveCountUI = new SpriteGo(SPRITE_PATH"mainUIexport_fUI0001.png");
	moveCountUI->SetSortingLayer(SortingLayers::UI);
	moveCountUI->SetSortingOrder(1);
	moveCountUIBackGround = new SpriteGo(SPRITE_PATH"mainUIexport_bUI2.png");
	moveCountUIBackGround->SetSortingLayer(SortingLayers::UI);
	moveCountUIBackGround->SetSortingOrder(0);

	mapIndexUI = new SpriteGo(SPRITE_PATH"mainUIexport_fUI0001.png");
	mapIndexUI->SetScale({ -1 , 1 });
	mapIndexUI->SetSortingLayer(SortingLayers::UI);
	mapIndexUI->SetSortingOrder(1);

	mapIndexUIBackGround = new SpriteGo(SPRITE_PATH"mainUIexport_bUI2.png");
	mapIndexUIBackGround->SetScale({ -1 , 1 });
	mapIndexUIBackGround->SetSortingLayer(SortingLayers::UI);
	mapIndexUIBackGround->SetSortingOrder(0);
	
	moveCountText = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	moveCountText->SetSortingOrder(3);
	moveCountText->SetFillColor(sf::Color::White);
	moveCountText->SetCharacterSize(100);
	moveCountText->SetSortingLayer(SortingLayers::UI);
	moveCountText->SetPosition({ 150.f , 750.f });

	mapIndexText = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	mapIndexText->SetSortingOrder(3);
	mapIndexText->SetFillColor(sf::Color::White);
	mapIndexText->SetCharacterSize(100);
	mapIndexText->SetSortingLayer(SortingLayers::UI);
	mapIndexText->SetPosition({ 1800.f , 750.f });

	

	AddGameObject(mapIndexText);
	AddGameObject(moveCountText);
	AddGameObject(mapIndexUI);
	AddGameObject(moveCountUIBackGround);
	AddGameObject(moveCountUI);
	AddGameObject(changeMapUI);
	AddGameObject(player);
	AddGameObject(backGround);
	AddGameObject(mapIndexUIBackGround);
	Scene::Init();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);
	if (INPUT_MGR.GetKeyDown(KEY::Enter)) {
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
	
	if (player->GetMoveCount() == 0) {

		for (auto& i : player->GetObstacleList()) {
			RemoveGameObject(i);
		}
		Reset();
	}
}

void GameScene::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void GameScene::Reset()
{
	Scene::Reset();
	moveCountUI->SetPosition({ 0,1080 - moveCountUI->GetLocalBound().height });
	mapIndexUI->SetPosition({ 1920, 1080 - moveCountUI->GetLocalBound().height });

	mapIndexUIBackGround->SetPosition({ 1920, 0 });
	moveCountText->SetString(std::to_string(10));
	//SETSCALE (0.7 , 0.7) 이라 설정된 그리드 사이즈에 0.7 나누어줘야됌
	mapData = TranslateMapData(UTILS.ReadFile(MAP_DATA(mapIndex + 1)));
	mapIndexText->SetString(std::to_string(mapIndex + 1));
	sf::Vector2f gridSize = GetGridSize() / 0.7f;
	sf::Vector2f gridCount = GetGridCount();
	int moveCount = GetMoveCount();

	for (int i = 0; i < mapData.size(); i++) {
		for (int j = 0; j < mapData[i].size(); j++) {
			if (mapData[i][j] > 3) {
				int curSpriteType = mapData[i][j] - (int)Types::TYPECOUTN;
				if (curSpriteType == (int)SpriteTypes::PLAYER) {
					player->plusPos = { gridSize.x * 0.4f , gridSize.y * 0.5f };
					player->SetMapData(gridSize, j, i, (SpriteTypes)curSpriteType);
					player->SetMoveCount(moveCount);
					player->SetMoveCountFunc([this](int moveCount) {
						moveCountText->SetString(std::to_string(moveCount));
					});
				}
				else{
					Obstacle* ob = nullptr;
					if (curSpriteType == (int)SpriteTypes::OBSTACLE) {
						ob = new Obstacle(UTILS.textureMap[SpriteTypes::OBSTACLE]);
					}
					else if (curSpriteType == (int)SpriteTypes::ENEMY) {
						ob = new Enemy(UTILS.textureMap[SpriteTypes::ENEMY]);
						ob->plusPos = { gridSize.x / 2 , gridSize.y  / 2};
					}
					else if (curSpriteType == (int)SpriteTypes::MAP1NPC) {
						ob = new NPC(UTILS.textureMap[SpriteTypes::MAP1NPC]);
						((NPC*)ob)->SettingCallBack([this]() {
							changeMapUI->Play();
						});
					}
					DrawObs(ob, (SpriteTypes)curSpriteType, gridSize, i, j);
				}
			}
		}
	}

}

void GameScene::Exit()
{
	Scene::Exit();
	
	for (auto& i : player->GetObstacleList()) {
		RemoveGameObject(i);
	}
}

void GameScene::Release()
{
	Scene::Release();
}

void GameScene::DrawObs(Obstacle* ob, SpriteTypes types , sf::Vector2f gridSize ,int i , int j)
{
	AddGameObject(ob);
	ob->Init();
	ob->Reset();
	ob->SetPosition({ gridSize.x * j , gridSize.y * i });
	ob->SetMapData(gridSize, j, i, types);
	player->AddObstacle(ob);
}
