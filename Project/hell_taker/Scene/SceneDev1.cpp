#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "Grid.h"
#include "Button.h"
#include "InputText.h"
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
	std::vector<std::string> ids = UTILS.ReadFile("GameData/MapData1.csv");
	fontIds.push_back(FONT_PATH"Amiri-Regular.ttf");

	texIds.push_back(SPRITE_PATH"chapterBG0001.png");
	texIds.push_back(SPRITE_PATH"chapterBG0002.png");
	texIds.push_back(SPRITE_PATH"chapterBG0003.png");
	texIds.push_back(SPRITE_PATH"chapterBG0004.png");
	texIds.push_back(SPRITE_PATH"chapterBG0005.png");
	texIds.push_back(SPRITE_PATH"chapterBG0006.png");
	texIds.push_back(SPRITE_PATH"chapterBG0007.png");
	texIds.push_back(SPRITE_PATH"chapterBG0008.png");
	
	for (int i = 0; i < 8; i++) {
		mapIds[i] = SPRITE_PATH"chapterBG000" + std::to_string(i + 1) + ".png";
	}
	for (int i = 0; i < 8; i++) {
		mapGridsIds[i] = "GameData/MapData" + std::to_string(i + 1) + ".csv";
	}

	TextGo* textGo = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	
	SpriteGo* spriteGo = new SpriteGo(SPRITE_PATH"chapterBG0001.png");

	Button* button = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* button1 = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* saveBNT = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* changeGridSize = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* nextMapBNT = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* prevMapBNT = new Button(FONT_PATH"Amiri-Regular.ttf");

	InputText* inputWidth = new InputText(FONT_PATH"Amiri-Regular.ttf");
	InputText* inputHeigth = new InputText(FONT_PATH"Amiri-Regular.ttf");

	InputText* inputGridSizeWidth = new InputText(FONT_PATH"Amiri-Regular.ttf");
	InputText* inputGridSizeHeight = new InputText(FONT_PATH"Amiri-Regular.ttf");

	TextGo* gridSizeText = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	TextGo* gridCountText = new TextGo(FONT_PATH"Amiri-Regular.ttf");

	button->SetString("WALL");
	button->SetPosition({ 1920 - 400.f, 300 });
	button->SetCallBack([this]() {
		this->type = Types::WALL;
	});

	button1->SetString("TILE");
	button1->SetPosition({ 1920 - 200.f, 300 });
	button1->SetCallBack([this]() {
		this->type = Types::TILE;
	});

	prevMapBNT->SetString("Prev");
	prevMapBNT->SetPosition({ 500.f , 1080.f - 200.f });
	prevMapBNT->SetCallBack([this , spriteGo]() {
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
	nextMapBNT->SetCallBack([this , spriteGo]() {
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
	saveBNT->SetPosition({1920 - 350.f , 1080 - 200.f});
	saveBNT->SetCallBack([this]() {
		std::vector<std::string> write;
		for (int i = 0; i < gridCount.y; i++) {
			std::string word;
			for (int j = 0; j < gridCount.x; j++) {
				word += std::to_string((int)grids[i][j]->GetType())	;
			}
			write.push_back(word);
		}

		write.push_back(std::to_string((int)gridSize.y));
		write.push_back(std::to_string((int)gridSize.x));

		UTILS.WriteFile("GameData/MapData" + std::to_string(mapIndex + 1) + ".csv" , write);
	});

	changeGridSize->SetString("Change");
	changeGridSize->SetToggle(false);
	changeGridSize->SetPosition({1920 - 320.f , 200});
	changeGridSize->SetCallBack([this, inputWidth , inputHeigth , inputGridSizeHeight , inputGridSizeWidth]() {
		if (inputHeigth->GetString() == "" || inputWidth->GetString() == "" || inputGridSizeHeight->GetString() == "" || inputGridSizeWidth->GetString() == "") return;

		int width = std::stoi(inputWidth->GetString());
		int height = std::stoi(inputHeigth->GetString());

		int sizeX = std::stoi(inputGridSizeWidth->GetString());
		int sizeY = std::stoi(inputGridSizeHeight->GetString());

		if (width && height && sizeX && sizeY) {
			this->gridCount = { (float)width , (float)height};
			this->gridSize = { (float)sizeX , (float)sizeY };
			DrawGrid(gridSize , gridCount);
		}
	});

	inputWidth->SetPosition({ 1920 - 400.f , 0 });
	inputHeigth->SetPosition({ 1920 - 200.f , 0 });

	inputGridSizeWidth->SetPosition({ 1920 - 400.f , 100 });
	inputGridSizeHeight->SetPosition({ 1920 - 200.f , 100 });

	gridSizeText->SetPosition({ 1920 - 340.f , 50 });
	gridSizeText->SetString("GRID COUNT");
	gridSizeText->SetFillColor(sf::Color::White);

	gridCountText->SetPosition({ 1920 - 320.f , 150 });
	gridCountText->SetString("GRID SIZE");
	gridCountText->SetFillColor(sf::Color::White);
	spriteGo->SetScale({ 0.7f , 0.7f });


	textGo->SetString("DEV1");

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

	if (ids.size() != 0) {
		DrawGrid(ids);
	}
	else {
		DrawGrid(gridSize, gridCount);
	}
	
	Scene::Init();
}

void SceneDev1::Reset()
{
	Scene::Reset();
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (INPUT_MGR.GetKeyDown(KEY::Enter)) {
		SCENE_MGR.ChangeScene(SceneIds::SceneGame);
	}


	for (int i = 0; i < grids.size(); i++) {
		for (int j = 0; j < grids[i].size(); j++) {
			if (grids[i][j]->GetGlobalBound().intersects(INPUT_MGR.GetMouseGlobalBound()) && INPUT_MGR.GetMouse(MOUSE::Left)) {
				grids[i][j]->SetTypes(type);
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
	std::vector<std::vector<int>> infos;

	for (int i = 0; i < lists.size() - 2; i++) {
		std::vector<int> vec;
		for (int j = 0; j < lists[i].size(); j++) {
			vec.push_back(lists[i][j] - '0');
		}
		infos.push_back(vec);
	}
	//FIX XYÃà ¹Ý´ë·ÎµÊ
	gridCount = { (float)lists[0].size() , (float)lists.size() - 2 };
	gridSize = {  std::stof(lists[lists.size() - 1]) , std::stof(lists[lists.size() - 2]) };

	DrawGrid(gridSize, gridCount);
	
	for (int i = 0; i < grids.size(); i++) {
		for (int j = 0; j < grids[i].size(); j++) {
			grids[i][j]->SetTypes((Types)infos[i][j]);
		}
	}
}
