#include "stdafx.h"
#include "SceneMapEditor.h"
#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "Grid.h"
#include "Button.h"
#include "InputText.h"
#include "ButtonSprite.h"
SceneMapEditor::SceneMapEditor()
	:Scene(SceneIds::SceneMapEditor)
{
	gridSize = { 50, 50 };
	gridCount = { 15 , 15 };
}

void SceneMapEditor::Init()
{

#pragma region TEXTURE , FONT
	fontIds.push_back(FONT_PATH"Amiri-Regular.ttf");

	texIds.push_back(SPRITE_PATH"chapterBG0001.png");
	texIds.push_back(SPRITE_PATH"chapterBG0002.png");
	texIds.push_back(SPRITE_PATH"chapterBG0003.png");
	texIds.push_back(SPRITE_PATH"chapterBG0004.png");
	texIds.push_back(SPRITE_PATH"chapterBG0005.png");
	texIds.push_back(SPRITE_PATH"chapterBG0006.png");
	texIds.push_back(SPRITE_PATH"chapterBG0007.png");
	texIds.push_back(SPRITE_PATH"chapterBG0008.png");

	texIds.push_back(UTILS.textureMap[SpriteTypes::PLAYER]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::OBSTACLE]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::ENEMY]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::MAP1NPC]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::HUDLE]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::GOLDKEY]);
	texIds.push_back(UTILS.textureMap[SpriteTypes::BOX]);

#pragma endregion


	for (int i = 0; i < 8; i++) {
		mapIds[i] = SPRITE_PATH"chapterBG000" + std::to_string(i + 1) + ".png";
	}
	for (int i = 0; i < 8; i++) {
		mapGridsIds[i] = MAP_DATA(i + 1);
		mapBackGround[i] = MAP_BACKGROUND_DATA(i + 1);
	}

	TextGo* textGo = new TextGo(FONT_PATH"Amiri-Regular.ttf");

	mapImage = new SpriteGo(SPRITE_PATH"chapterBG0001.png");

	Button* button = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* button1 = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* saveBNT = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* changeGridSize = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* nextMapBNT = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* prevMapBNT = new Button(FONT_PATH"Amiri-Regular.ttf");

	ButtonSprite* deleteButton = new ButtonSprite();
	ButtonSprite* playerButton = new ButtonSprite(UTILS.textureMap[SpriteTypes::PLAYER]);
	ButtonSprite* obstacleButton = new ButtonSprite(UTILS.textureMap[SpriteTypes::OBSTACLE]);
	ButtonSprite* enemyButton = new ButtonSprite(UTILS.textureMap[SpriteTypes::ENEMY]);
	ButtonSprite* map1NpcButton = new ButtonSprite(UTILS.textureMap[SpriteTypes::MAP1NPC]);
	ButtonSprite* hurdleButton = new ButtonSprite(UTILS.textureMap[SpriteTypes::HUDLE]);
	ButtonSprite* goldKeyButton = new ButtonSprite(UTILS.textureMap[SpriteTypes::GOLDKEY]);
	ButtonSprite* boxButton = new ButtonSprite(UTILS.textureMap[SpriteTypes::BOX]);

	InputText* inputWidth = new InputText(FONT_PATH"Amiri-Regular.ttf");
	InputText* inputHeigth = new InputText(FONT_PATH"Amiri-Regular.ttf");

	InputText* inputGridSizeWidth = new InputText(FONT_PATH"Amiri-Regular.ttf");
	InputText* inputGridSizeHeight = new InputText(FONT_PATH"Amiri-Regular.ttf");
	InputText* inputMoveCount = new InputText(FONT_PATH"Amiri-Regular.ttf");

	TextGo* gridSizeText = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	TextGo* gridCountText = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	TextGo* moveCountText = new TextGo(FONT_PATH"Amiri-Regular.ttf");

#pragma region BUTTONS

	button->SetString("WALL");
	button->SetPosition({ 1920 - 400.f, 400 });
	button->SetCallBack([this]() {
		this->type = Types::WALL;
		spriteType = SpriteTypes::NONE;
		});

	button1->SetString("TILE");
	button1->SetPosition({ 1920 - 200.f, 400 });
	button1->SetCallBack([this]() {
		this->type = Types::TILE;
		spriteType = SpriteTypes::NONE;
		});

	prevMapBNT->SetString("Prev");
	prevMapBNT->SetPosition({ 500.f , 1080.f - 200.f });
	prevMapBNT->SetCallBack([this]() {
		if (MAP.GetMapIndex() > 0) {
			MAP.SetMapIndex(MAP.GetMapIndex() - 1);
			std::vector<std::vector<int>> list = MAP.GetMapData();
			std::vector<std::vector<int>> backGround = MAP.GetBackGroundMap();
			if (!list.size()) {
				gridSize = { 50, 50 };
				gridCount = { 15 , 15 };
				DrawGrid(gridSize, gridCount);
			}
			else {
				DrawGrid(list , backGround);
			}
			mapImage->ChangeTexture(mapIds[MAP.GetMapIndex()]);
		}

		});

	nextMapBNT->SetString("Next");
	nextMapBNT->SetPosition({ 600.f , 1080.f - 200.f });
	nextMapBNT->SetCallBack([this]() {
		if (MAP.GetMapIndex() < 7) {
			MAP.SetMapIndex(MAP.GetMapIndex() + 1);
			std::vector<std::vector<int>> list = MAP.GetMapData();
			std::vector<std::vector<int>> backGround = MAP.GetBackGroundMap();
			if (!list.size()) {
				gridSize = { 50, 50 };
				gridCount = { 15 , 15 };
				DrawGrid(gridSize, gridCount);
			}
			else {
				DrawGrid(list , backGround);
			}
			mapImage->ChangeTexture(mapIds[MAP.GetMapIndex()]);
		}

		});
	saveBNT->SetString("SAVE");
	saveBNT->SetToggle(false);
	saveBNT->SetPosition({ 1920 - 350.f , 1080 - 200.f });
	saveBNT->SetCallBack([this, inputMoveCount]() {
		std::vector<std::vector<float>> write;
		std::vector<std::vector<float>> backGround;

		std::vector<float> type;
		std::vector<float> backGroundType;
		for (int i = 0; i < gridCount.y; i++) {
			for (int j = 0; j < gridCount.x; j++) {
				if (grids[i][j]->GetSpriteTypes() != SpriteTypes::NONE && grids[i][j]->GetSpriteTypes() != SpriteTypes::DELETE) {
					type.push_back((float)grids[i][j]->GetSpriteTypes() + (float)Types::TYPECOUTN);
				}
				else {
					type.push_back((float)grids[i][j]->GetType());
				}

				if (grids[i][j]->GetBackGroundTypes() != SpriteTypes::NONE && grids[i][j]->GetBackGroundTypes() != SpriteTypes::DELETE) {
					backGroundType.push_back((int)grids[i][j]->GetBackGroundTypes());
				}
				else {
					backGroundType.push_back(0);
				}
			}
			backGround.push_back(backGroundType);
			backGroundType.clear();
			write.push_back(type);
			type.clear();
		}

		type.push_back(gridSize.y);
		type.push_back(gridSize.x);
		write.push_back(type);

		type.clear();
		type.push_back(std::stof(inputMoveCount->GetString()));
		write.push_back(type);

		backGroundType.push_back(0);
		backGroundType.push_back(0);
		backGround.push_back(backGroundType);

		backGroundType.clear();
		backGroundType.push_back(0);
		backGround.push_back(backGroundType);

		UTILS.WriteMapDataFile("GameData/MapData" + std::to_string(MAP.GetMapIndex() + 1) + ".csv", write);
		UTILS.WriteMapDataFile("GameData/MapData" + std::to_string(MAP.GetMapIndex() + 1) + "_backGroundTiles.csv", backGround);

		MAP.ReLoad(); 
	});
	changeGridSize->SetString("Change");
	changeGridSize->SetToggle(false);
	changeGridSize->SetPosition({ 1920 - 320.f , 200 });
	changeGridSize->SetCallBack([this, inputWidth, inputHeigth, inputGridSizeHeight, inputGridSizeWidth]() {
		if (inputHeigth->GetString() == "" || inputWidth->GetString() == "" || inputGridSizeHeight->GetString() == "" || inputGridSizeWidth->GetString() == "") return;

		int width = std::stoi(inputWidth->GetString());
		int height = std::stoi(inputHeigth->GetString());

		int sizeX = std::stoi(inputGridSizeWidth->GetString());
		int sizeY = std::stoi(inputGridSizeHeight->GetString());

		if (width && height && sizeX && sizeY) {
			this->gridCount = { (float)width , (float)height };
			this->gridSize = { (float)sizeX , (float)sizeY };
			DrawGrid(gridSize, gridCount);
		}
		});

#pragma endregion
#pragma region INPUTTEXTS
	inputWidth->SetPosition({ 1920 - 400.f , 0 });
	inputHeigth->SetPosition({ 1920 - 200.f , 0 });

	inputGridSizeWidth->SetPosition({ 1920 - 400.f , 100 });
	inputGridSizeHeight->SetPosition({ 1920 - 200.f , 100 });

	inputMoveCount->SetPosition({ 1920 - 300.f , 250.f });
	inputMoveCount->SetString("0");
#pragma endregion
#pragma region TEXTS
	gridSizeText->SetPosition({ 1920 - 340.f , 50 });
	gridSizeText->SetString("GRID COUNT");
	gridSizeText->SetFillColor(sf::Color::White);

	gridCountText->SetPosition({ 1920 - 320.f , 150 });
	gridCountText->SetString("GRID SIZE");
	gridCountText->SetFillColor(sf::Color::White);

	moveCountText->SetPosition({ 1920 - 350.f , 300.f });
	moveCountText->SetString("MOVE COUNT");
	moveCountText->SetFillColor(sf::Color::White);
#pragma endregion
#pragma region BUTTONSPITE
	deleteButton->SetPosition({ 1920 - 450.f , 500.f });
	deleteButton->SetCallBack([this]() {
		spriteType = SpriteTypes::DELETE;
		type = Types::NONE;
		});

	playerButton->SetPosition({ 1920 - 350.f , 500 });
	playerButton->SetCallBack([this]() {
		spriteType = SpriteTypes::PLAYER;
		isForGround = true;
		type = Types::NONE;
		});

	obstacleButton->SetPosition({ 1920 - 250.f , 500 });
	obstacleButton->SetCallBack([this]() {
		spriteType = SpriteTypes::OBSTACLE;
		isForGround = true;
		
		type = Types::NONE;
		});

	enemyButton->SetPosition({ 1920 - 450.f , 600 });
	enemyButton->SetCallBack([this]() {
		spriteType = SpriteTypes::ENEMY;
		isForGround = true;
		type = Types::NONE;
		});

	map1NpcButton->SetPosition({ 1920 - 350.f , 600 });
	map1NpcButton->SetCallBack([this]() {
		spriteType = SpriteTypes::MAP1NPC;
		isForGround = true;
		type = Types::NONE;
		});

	hurdleButton->SetPosition({ 1920 - 250.f , 600.f });
	hurdleButton->SetCallBack([this] {
		spriteType = SpriteTypes::HUDLE;
		isForGround = false;
		type = Types::NONE;
	});

	goldKeyButton->SetPosition({ 1920 - 450.f , 700 });
	goldKeyButton->SetCallBack([this]() {
		spriteType = SpriteTypes::GOLDKEY;
		isForGround = true;
		type = Types::NONE;
	});

	boxButton->SetPosition({ 1920 - 350.f , 700 });
	boxButton->SetCallBack([this]() {
		spriteType = SpriteTypes::BOX;
		isForGround = true;
		type = Types::NONE;
	});
#pragma endregion

	mapImage->SetScale({ 0.7f , 0.7f });
#pragma region ADDGAMEOBJECT
	AddGameObject(saveBNT);
	AddGameObject(button);
	AddGameObject(button1);
	AddGameObject(mapImage);
	AddGameObject(textGo);
	AddGameObject(inputWidth);
	AddGameObject(inputHeigth);
	AddGameObject(gridSizeText);
	AddGameObject(inputGridSizeWidth);
	AddGameObject(inputGridSizeHeight);
	AddGameObject(changeGridSize);
	AddGameObject(gridCountText);
	AddGameObject(prevMapBNT);
	AddGameObject(nextMapBNT);
	AddGameObject(playerButton);
	AddGameObject(deleteButton);
	AddGameObject(obstacleButton);
	AddGameObject(enemyButton);
	AddGameObject(map1NpcButton);
	AddGameObject(inputMoveCount);
	AddGameObject(moveCountText);
	AddGameObject(hurdleButton);
	AddGameObject(goldKeyButton);
	AddGameObject(boxButton);
#pragma endregion



	Scene::Init();

}

void SceneMapEditor::Update(float dt)
{

	Scene::Update(dt);

	if (INPUT_MGR.GetKeyDown(KEY::Enter)) {
		SCENE_MGR.ChangeScene(SceneIds::SceneGame);
	}

	for (int i = 0; i < grids.size(); i++) {
		for (int j = 0; j < grids[i].size(); j++) {
			if (type != Types::NONE && grids[i][j]->GetGlobalBound().intersects(INPUT_MGR.GetMouseGlobalBound()) && INPUT_MGR.GetMouse(MOUSE::Left)) {
				grids[i][j]->SetTypes(type);
			}
			if (spriteType != SpriteTypes::NONE && grids[i][j]->GetGlobalBound().intersects(INPUT_MGR.GetMouseGlobalBound()) && INPUT_MGR.GetMouseDown(MOUSE::Left)) {
				grids[i][j]->SetTypes(spriteType , isForGround);
			}
		}
	}

	if (INPUT_MGR.GetKey(KEY::Right)) {
		gridSize.x += 0.1f;
		DrawGrid(gridSize, gridCount);
	}
	if (INPUT_MGR.GetKey(KEY::Left)) {
		gridSize.x -= 0.1f;
		DrawGrid(gridSize, gridCount);
	}
	if (INPUT_MGR.GetKey(KEY::Down)) {
		gridSize.y += 0.1f;
		DrawGrid(gridSize, gridCount);
	}
	if (INPUT_MGR.GetKey(KEY::Up)) {
		gridSize.y -= 0.1f;
		DrawGrid(gridSize, gridCount);
	}

	if (INPUT_MGR.GetKeyDown(KEY::D)) {
		gridCount.x++;
		DrawGrid(gridSize, gridCount);
	}
	if (INPUT_MGR.GetKeyDown(KEY::A)) {
		gridCount.x--;
		DrawGrid(gridSize, gridCount);
	}
	if (INPUT_MGR.GetKeyDown(KEY::S)) {
		gridCount.y++;
		DrawGrid(gridSize, gridCount);
	}
	if (INPUT_MGR.GetKeyDown(KEY::W)) {
		gridCount.y--;
		DrawGrid(gridSize, gridCount);
	}
}

void SceneMapEditor::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void SceneMapEditor::Reset()
{
	std::vector<std::vector<int>> forGround = MAP.GetMapData();
	std::vector<std::vector<int>> backGround = MAP.GetBackGroundMap();
	mapImage->ChangeTexture(SPRITE_PATH"chapterBG000"+std::to_string(MAP.GetMapIndex() + 1)+ ".png");

	Scene::Reset();

	if (forGround.size() != 0) {
		DrawGrid(forGround , backGround);
	}
	else {
		DrawGrid(gridSize, gridCount);
	}

}

void SceneMapEditor::Exit()
{
	Scene::Exit();
}

void SceneMapEditor::Release()
{
	Scene::Release();
}

void SceneMapEditor::DrawGrid(sf::Vector2f cellSize, sf::Vector2f cellCount)
{
	for (int i = 0; i < grids.size(); i++) {
		for (int j = 0; j < grids[i].size(); j++) {
			RemoveGameObject(grids[i][j]);
		}
	}

	grids.clear();

	for (int i = 0; i < cellCount.y; i++) {
		std::vector<Grid*> vec;
		for (int j = 0; j < cellCount.x; j++) {
			Grid* grid = new Grid(cellSize);
			grid->Init();
			grid->SetPosition({ cellSize.x * j , cellSize.y * i });
			AddGameObject(grid);
			vec.push_back(grid);
		}
		grids.push_back(vec);
	}
}

void SceneMapEditor::DrawGrid(std::vector<std::vector<int>>& forGround , std::vector<std::vector<int>>& backGround)
{
	std::vector<std::vector<int>> infos(MAP.GetMapData());
	gridSize = MAP.GetGridSize();
	gridCount = MAP.GetGridCount();

	DrawGrid(gridSize, gridCount);

	for (int i = 0; i < grids.size(); i++) {
		for (int j = 0; j < grids[i].size(); j++) {
			if (infos[i][j] < 2) grids[i][j]->SetTypes((Types)infos[i][j]);
			if (infos[i][j] > 3) {
				grids[i][j]->SetTypes((SpriteTypes)(infos[i][j] - (int)Types::TYPECOUTN));
			}
		}
	}

	if (backGround.size() > 0) {
		for (int i = 0; i < grids.size(); i++) {
			for (int j = 0; j < grids[i].size(); j++) {
				if (backGround[i][j] != 0) {
					grids[i][j]->SetTypes((SpriteTypes)backGround[i][j], false);
				}
			}
		}
	}

}
