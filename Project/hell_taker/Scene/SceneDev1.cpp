#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "Grid.h"
#include "Button.h"
#include "InputText.h"
#include "ButtonSprite.h"
//GRIDSIZE (101,81)
//GRIDCOUNT(19,12)
SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
	gridSize = { 50, 50 };
	gridCount = { 15 , 15 };
}

void SceneDev1::Init()
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

	texIds.push_back(SPRITE_PATH"assets100V20053.png");
	texIds.push_back(SPRITE_PATH"assets100V20081.png");
	texIds.push_back(SPRITE_PATH"assets100V20225.png");
#pragma endregion


	for (int i = 0; i < 8; i++) {
		mapIds[i] = SPRITE_PATH"chapterBG000" + std::to_string(i + 1) + ".png";
	}
	for (int i = 0; i < 8; i++) {
		mapGridsIds[i] = MAP_DATA(i + 1);
	}

	TextGo* textGo = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	
	SpriteGo* spriteGo = new SpriteGo(SPRITE_PATH"chapterBG0001.png");
	
	Button* button = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* button1 = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* saveBNT = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* changeGridSize = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* nextMapBNT = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* prevMapBNT = new Button(FONT_PATH"Amiri-Regular.ttf");

	ButtonSprite* deleteButton = new ButtonSprite();
	ButtonSprite* playerButton = new ButtonSprite(SPRITE_PATH"assets100V20053.png");
	ButtonSprite* obstacleButton = new ButtonSprite(SPRITE_PATH"assets100V20081.png");
	ButtonSprite* enemyButton = new ButtonSprite(SPRITE_PATH"assets100V20225.png");

	InputText* inputWidth = new InputText(FONT_PATH"Amiri-Regular.ttf");
	InputText* inputHeigth = new InputText(FONT_PATH"Amiri-Regular.ttf");

	InputText* inputGridSizeWidth = new InputText(FONT_PATH"Amiri-Regular.ttf");
	InputText* inputGridSizeHeight = new InputText(FONT_PATH"Amiri-Regular.ttf");

	TextGo* gridSizeText = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	TextGo* gridCountText = new TextGo(FONT_PATH"Amiri-Regular.ttf");

#pragma region BUTTONS

	button->SetString("WALL");
	button->SetPosition({ 1920 - 400.f, 300 });
	button->SetCallBack([this]() {
		this->type = Types::WALL;
		spriteType = SpriteTypes::NONE;
		});

	button1->SetString("TILE");
	button1->SetPosition({ 1920 - 200.f, 300 });
	button1->SetCallBack([this]() {
		this->type = Types::TILE;
		spriteType = SpriteTypes::NONE;
		});

	prevMapBNT->SetString("Prev");
	prevMapBNT->SetPosition({ 500.f , 1080.f - 200.f });
	prevMapBNT->SetCallBack([this, spriteGo]() {
		if (mapIndex > 0) {
			mapIndex--;
			std::vector<std::string> list = UTILS.ReadFile(mapGridsIds[mapIndex]);
			if (!list.size()) {
				gridSize = { 50, 50 };
				gridCount = { 15 , 15 };
				DrawGrid(gridSize, gridCount);
			}
			else {
				DrawGrid(list);
			}
			spriteGo->ChangeTexture(mapIds[mapIndex]);
		}

		});

	nextMapBNT->SetString("Next");
	nextMapBNT->SetPosition({ 600.f , 1080.f - 200.f });
	nextMapBNT->SetCallBack([this, spriteGo]() {
		if (mapIndex < 7) {
			mapIndex++;
			std::vector<std::string> list = UTILS.ReadFile(mapGridsIds[mapIndex]);
			if (!list.size()) {
				gridSize = { 50, 50 };
				gridCount = { 15 , 15 };
				DrawGrid(gridSize, gridCount);
			}
			else {
				DrawGrid(list);
			}
			spriteGo->ChangeTexture(mapIds[mapIndex]);
		}

		});
	saveBNT->SetString("SAVE");
	saveBNT->SetToggle(false);
	saveBNT->SetPosition({ 1920 - 350.f , 1080 - 200.f });
	saveBNT->SetCallBack([this]() {
		std::vector<std::string> write;
		for (int i = 0; i < gridCount.y; i++) {
			std::string word;
			for (int j = 0; j < gridCount.x; j++) {
				if (grids[i][j]->GetSpriteTypes() != SpriteTypes::NONE && grids[i][j]->GetSpriteTypes() != SpriteTypes::DELETE) {
					word += std::to_string((int)grids[i][j]->GetSpriteTypes() + (int)Types::TYPECOUTN);
				}
				else {
					word += std::to_string((int)grids[i][j]->GetType());
				}
			}
			write.push_back(word);
		}

		write.push_back(std::to_string((int)gridSize.y));
		write.push_back(std::to_string((int)gridSize.x));

		UTILS.WriteFile("GameData/MapData" + std::to_string(mapIndex + 1) + ".csv", write);
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
#pragma endregion
#pragma region TEXTS
	gridSizeText->SetPosition({ 1920 - 340.f , 50 });
	gridSizeText->SetString("GRID COUNT");
	gridSizeText->SetFillColor(sf::Color::White);

	gridCountText->SetPosition({ 1920 - 320.f , 150 });
	gridCountText->SetString("GRID SIZE");
	gridCountText->SetFillColor(sf::Color::White);
	
#pragma endregion
#pragma region BUTTONSPITE
	deleteButton->SetPosition({ 1920 - 450.f , 400.f });
	deleteButton->SetCallBack([this]() {
		spriteType = SpriteTypes::DELETE;
		type = Types::NONE;
	});

	playerButton->SetPosition({1920 - 350.f , 400.f});
	playerButton->SetCallBack([this]() {
		spriteType = SpriteTypes::PLAYER;
		type = Types::NONE;
	});
	
	obstacleButton->SetPosition({1920 - 250.f , 400.f});
	obstacleButton->SetCallBack([this]() {
		spriteType = SpriteTypes::OBSTACLE;
		type = Types::NONE;
	});

	enemyButton->SetPosition({ 1920 - 450.f , 500.f });
	enemyButton->SetCallBack([this]() {
		spriteType = SpriteTypes::ENEMY;
		type = Types::NONE;
	});
#pragma endregion
	
	spriteGo->SetScale({ 0.7f , 0.7f });
#pragma region ADDGAMEOBJECT
	AddGameObject(saveBNT);
	AddGameObject(button);
	AddGameObject(button1);
	AddGameObject(spriteGo);
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
#pragma endregion



	Scene::Init();
}

void SceneDev1::Reset()
{
	std::vector<std::string> ids = UTILS.ReadFile("GameData/MapData1.csv");

	Scene::Reset();

	if (ids.size() != 0) {
		DrawGrid(ids);
	}
	else {
		DrawGrid(gridSize, gridCount);
	}

}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (INPUT_MGR.GetKeyDown(KEY::Enter)) {
		SCENE_MGR.ChangeScene(SceneIds::SceneGame);
	}

	for (int i = 0; i < grids.size(); i++) {
		for (int j = 0; j < grids[i].size(); j++) {
			if (type != Types::NONE && grids[i][j]->GetGlobalBound().intersects(INPUT_MGR.GetMouseGlobalBound()) && INPUT_MGR.GetMouse(MOUSE::Left) ) {	
				grids[i][j]->SetTypes(type);
			}
			if (spriteType != SpriteTypes::NONE && grids[i][j]->GetGlobalBound().intersects(INPUT_MGR.GetMouseGlobalBound()) && INPUT_MGR.GetMouseDown(MOUSE::Left)) {
				grids[i][j]->SetTypes(spriteType);
			}
		}
	}

	if (INPUT_MGR.GetKeyDown(KEY::Right)) {
		gridSize.x++;
		DrawGrid(gridSize, gridCount);
	}
	if (INPUT_MGR.GetKeyDown(KEY::Left)) {
		gridSize.x--;
		DrawGrid(gridSize, gridCount);
	}
	if (INPUT_MGR.GetKeyDown(KEY::Down)) {
		gridSize.y++;
		DrawGrid(gridSize, gridCount);
	}
	if (INPUT_MGR.GetKeyDown(KEY::Up)) {
		gridSize.y--;
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

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	
}



void SceneDev1::DrawGrid(sf::Vector2f cellSize, sf::Vector2f cellCount)
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

void SceneDev1::DrawGrid(std::vector<std::string>& lists)
{
	std::vector<std::vector<int>> infos(TranslateMapData(lists));
	gridSize = GetGridSize();
	gridCount = GetGridCount();

	DrawGrid(gridSize, gridCount);
	
	for (int i = 0; i < grids.size(); i++) {
		for (int j = 0; j < grids[i].size(); j++) {
			if(infos[i][j] < 2) grids[i][j]->SetTypes((Types)infos[i][j]);
			if (infos[i][j] > 3) {
				grids[i][j]->SetTypes((SpriteTypes)(infos[i][j] - (int)Types::TYPECOUTN));
			}
			
		}
	}
}
