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
#include "ImmovableObstacle.h"
#include "Huddle.h"
#include "GoldKey.h"
#include "Map.h"
#include "InteractiveViewer.h"
#include "UpDownHudle.h"
#include "Box.h"
GameScene::GameScene()
	:Scene(SceneIds::SceneGame)
{
}

void GameScene::Init()
{
	worldView.setSize({ 1920 , 1080 });
	worldView.setCenter({ 1920 / 2 , 1080 / 2 });
	uiView.setSize({ 1920 , 1080 });
	uiView.setCenter({ 1920 / 2 , 1080 / 2 });
	fontIds.push_back(FONT_PATH"Amiri-Regular.ttf");
	fontIds.push_back(FONT_PATH"CrimsonPro-Medium.ttf");

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
	texIds.push_back(SPRITE_PATH"pand_idle.png");
	texIds.push_back(SPRITE_PATH"pand_flust.png");
	texIds.push_back(SPRITE_PATH"dialogueBG_hell.png");
	texIds.push_back(SPRITE_PATH"button0003.png");
	texIds.push_back(SPRITE_PATH"button0004.png");
	texIds.push_back(SPRITE_PATH"mod_idle.png");
	texIds.push_back(SPRITE_PATH"mod_close.png");

	texIds.push_back(UTILS.textureMap[SpriteTypes::PLAYER]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::OBSTACLE]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::ENEMY]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::MAP1NPC]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::GOLDKEY]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::BOX]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::HUDLE]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::UPDOWNHUDLE]);

	aniIds.push_back(ANI_PATH"playerIdle.csv");
	aniIds.push_back(ANI_PATH"enemyIdle.csv");
	aniIds.push_back(ANI_PATH"enemyKicked.csv");
	aniIds.push_back(ANI_PATH"playerKick.csv");
	aniIds.push_back(ANI_PATH"playerMove.csv");
	aniIds.push_back(ANI_PATH"map1Npc.csv");
	aniIds.push_back(ANI_PATH"changeMap.csv");
	aniIds.push_back(ANI_PATH"playerDie.csv");
	aniIds.push_back(ANI_PATH"moveEffect.csv");
	aniIds.push_back(ANI_PATH"goldKey.csv");
	aniIds.push_back(ANI_PATH"InteractiveViewIcon.csv");
	aniIds.push_back(ANI_PATH"Success.csv");
	aniIds.push_back(ANI_PATH"badEnd.csv");
	aniIds.push_back(ANI_PATH"goldKeyEffect.csv");
	aniIds.push_back(ANI_PATH"huddleDown.csv");
	aniIds.push_back(ANI_PATH"huddleUp.csv");
	aniIds.push_back(ANI_PATH"playerHit.csv");

	backGround = new SpriteGo(MAP_IMAGE(MAP.GetMapIndex() + 1));
	backGround->SetSortingLayer(SortingLayers::BACKGROUND);

	bossmapBackGround = new SpriteGo(SPRITE_PATH"boss_EXPORT20001.png");
	bossmapBackGround->SetSortingLayer(SortingLayers::FORGROUND);

	player = new Player(UTILS.textureMap[SpriteTypes::PLAYER]);
	player->SetGameScene(this);
	interactive = new InteractiveViewer(FONT_PATH"CrimsonPro-Medium.ttf");
	interactive->SetGameScene(this);

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
	mapIndexUIBackGround->SetSortingLayer(SortingLayers::DEFAULT);
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

	AddGameObject(interactive);
	AddGameObject(mapIndexText);
	AddGameObject(moveCountText);
	AddGameObject(mapIndexUI);
	AddGameObject(moveCountUIBackGround);
	AddGameObject(moveCountUI);
	AddGameObject(changeMapUI);
	AddGameObject(player);
	AddGameObject(backGround);
	AddGameObject(mapIndexUIBackGround);
	AddGameObject(bossmapBackGround);

	changeMapUI->SetGameScene(this);
	player->SetChangeMapFunc([this]() {
		ResetScene();
	});
	Scene::Init();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);
	if (INPUT_MGR.GetKeyDown(KEY::Enter)) {
		SCENE_MGR.ChangeScene(SceneIds::SceneMapEditor);
	}
	if (INPUT_MGR.GetKeyDown(KEY::F1)) {
		interactive->Reset();
		interactive->SetActive(true);
	}
	if (INPUT_MGR.GetKeyDown(KEY::R)) {
		ResetScene();
	}
	if (INPUT_MGR.GetKeyDown(KEY::K)) {
		MAP.SetMapIndex(MAP.GetMapIndex() + 1);
		ResetScene();
	}
	if (INPUT_MGR.GetKeyDown(KEY::J)) {
		MAP.SetMapIndex(MAP.GetMapIndex() - 1);
		ResetScene();
	}

	CameraShake();
	
	
	/*if (player->GetMoveCount() == 0) {

		for (auto& i : player->GetObstacleList()) {
			RemoveGameObject(i);
		}
		Reset();
	}*/
}

void GameScene::Draw(sf::RenderWindow& window)
{
	window.setView(worldView);
	Scene::Draw(window);
}

void GameScene::Reset()
{
	Scene::Reset();

	if (MAP.GetMapIndex() == 5) {
		bossmapBackGround->SetActive(true);
		bossmapBackGround->SetScale({ 0.99f , 1 });
		bossmapBackGround->SetOrigin(Origins::MC);
		bossmapBackGround->SetPosition({ 1920 / 2 - 20.f , 1080 / 2 - 233.f });
		
		mapIndexUI->SetActive(false);
		mapIndexText->SetActive(false);
		mapIndexUIBackGround->SetActive(false);

		moveCountText->SetActive(false);
		moveCountUI->SetActive(false);
		moveCountUIBackGround->SetActive(false);
	}
	else {
		bossmapBackGround->SetActive(false);
		backGround->ChangeTexture(MAP_IMAGE(MAP.GetMapIndex() + 1));
		backGround->SetPosition({ 0, 0 });
		mapIndexUI->SetActive(true);
		mapIndexText->SetActive(true);
		mapIndexUIBackGround->SetActive(true);

		moveCountText->SetActive(true);
		moveCountUI->SetActive(true);
		moveCountUIBackGround->SetActive(true);
	}

	MAP.isClear = false;

	moveCountUI->SetPosition({ 0,1080 - moveCountUI->GetLocalBound().height });
	mapIndexUI->SetPosition({ 1920, 1080 - moveCountUI->GetLocalBound().height });

	mapIndexUIBackGround->SetPosition({ 1920, 0 });
	
	//SETSCALE (0.7 , 0.7) 이라 설정된 그리드 사이즈에 0.7 나누어줘야됌
	auto mapData = MAP.GetMapData();
	auto backGroundMapData = MAP.GetBackGroundMap();

	mapIndexText->SetString(std::to_string(MAP.GetMapIndex() + 1));
	
	sf::Vector2f gridSize = MAP.GetGridSize() / 0.7f;
	sf::Vector2f gridCount = MAP.GetGridCount();
	int moveCount = MAP.GetMoveCount();

	for (int i = 0; i < mapData.size(); i++) {
		for (int j = 0; j < mapData[i].size(); j++) {
			if (backGroundMapData.size() > 0) {
				if (backGroundMapData[i][j] != 0) {
					Obstacle* ob = nullptr;
					if (backGroundMapData[i][j] == (int)SpriteTypes::HUDLE) {
						ob = new Huddle(UTILS.textureMap[SpriteTypes::HUDLE]);
						ob->plusPos = { 10 , 20 };
						ob->SetScale({ 0.8f , 0.8f });
						ob->SetSortingOrder(-2);
					}
					else if (backGroundMapData[i][j] == (int)SpriteTypes::UPDOWNHUDLE) {
						ob = new UpDownHudle(UTILS.textureMap[SpriteTypes::UPDOWNHUDLE]);
						ob->plusPos = { 50 , 90 };
						ob->SetScale({ 0.8f , 0.8f });
						ob->SetSortingOrder(-2);
					}
					else if (backGroundMapData[i][j] == (int)SpriteTypes::DOWNUPHUDDLE) {
						ob = new UpDownHudle(UTILS.textureMap[SpriteTypes::UPDOWNHUDLE]);
						((UpDownHudle*)ob)->Play();
						ob->plusPos = { 50 , 90 };
						ob->SetScale({ 0.8f , 0.8f });
						ob->SetSortingOrder(-2);
					}
					else if (backGroundMapData[i][j] == (int)SpriteTypes::BOSSMAPTILE) {
						ob = new Obstacle(UTILS.textureMap[SpriteTypes::BOSSMAPTILE]);
						
					}
					AddObs(ob, (SpriteTypes)backGroundMapData[i][j], gridSize, i, j);
					
				}
			}
			if (mapData[i][j] > 3) {
				int curSpriteType = mapData[i][j] - (int)Types::TYPECOUTN;
				
				
				if (curSpriteType == (int)SpriteTypes::PLAYER) {
					player->plusPos = { gridSize.x * 0.5f , gridSize.y * 0.5f };
					player->SetMapData(gridSize, j, i, (SpriteTypes)curSpriteType);
					player->SetMoveCount(moveCount);
					player->SetMoveCountFunc([this](int moveCount) {
						moveCountText->SetString(std::to_string(moveCount));
					});
					moveCountText->SetString(std::to_string(moveCount));
				}
				else{
					Obstacle* ob = nullptr;
					if (curSpriteType == (int)SpriteTypes::OBSTACLE) {
						ob = new Obstacle(UTILS.textureMap[SpriteTypes::OBSTACLE]);
						//ob->SetScale({ 0.8f , 0.8f });
						ob->plusPos = { 10.f , 10.f };
					}
					else if (curSpriteType == (int)SpriteTypes::ENEMY) {
						ob = new Enemy(UTILS.textureMap[SpriteTypes::ENEMY]);
						((Enemy*)ob)->SettingPlayer(player);
						ob->plusPos = { gridSize.x / 2 , gridSize.y  / 2};
					}
					else if (curSpriteType == (int)SpriteTypes::MAP1NPC) {
						ob = new NPC(UTILS.textureMap[SpriteTypes::MAP1NPC]);
						((NPC*)ob)->SettingCallBack([this]() {
							interactive->Reset();
							interactive->SetActive(true);

							//changeMapUI->Play();
							MAP.isClear = true;
						});
					}
					else if (curSpriteType == (int)SpriteTypes::BOX) {
						ob = new Box(UTILS.textureMap[SpriteTypes::BOX]);
					}
					else if (curSpriteType == (int)SpriteTypes::GOLDKEY) {
						ob = new GoldKey(UTILS.textureMap[SpriteTypes::GOLDKEY]);
						ob->plusPos = { gridSize.x + 20.f , gridSize.y + 10.f };
					}
	
					AddObs(ob, (SpriteTypes)curSpriteType, gridSize, i, j);
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

void GameScene::AddObs(Obstacle* ob, SpriteTypes types , sf::Vector2f gridSize ,int i , int j)
{
	AddGameObject(ob);
	ob->Init();
	ob->Reset();
	ob->SetPosition({ gridSize.x * j , gridSize.y * i });
	ob->SetMapData(gridSize, j, i, types);
	
	player->AddObstacle(ob);
}

void GameScene::ResetScene()
{
	changeMapUI->Play();

	for (auto& i : player->GetObstacleList()) {
		RemoveGameObject(i);
	}

	Reset();
}

void GameScene::SetCameraShake() {
	shakeLeft = true;
}

void GameScene::CameraShake()
{
	if (shakeLeft) {
		sf::Vector2f pos = UTILS.Lerp(initCameraPos, cameraShakeMin, shakeTime);
		shakeTime += shakeSmooth;
		worldView.setCenter(pos);
		if (shakeTime >= 1) {
			shakeTime = 0;
			shakeLeft = false;
			shakeRight = true;
		}
	}
	if (shakeRight) {
		sf::Vector2f pos = UTILS.Lerp(cameraShakeMin, cameraShakeMax, shakeTime);
		shakeTime += shakeSmooth;
		worldView.setCenter(pos);
		if (shakeTime >= 1) {
			shakeTime = 0;
			if (count >= 0) {
				shakeLeft = true;
				count--;
			}
			else {
				shakeLeft = false;
				count = 0;
			}
			shakeRight = false;
		}
	}
}
