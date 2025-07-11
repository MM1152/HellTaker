#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "Grid.h"
#include "Button.h"
//GRIDSIZE (101,81)
//GRIDCOUNT(19,12)
SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
	gridSize = { 101, 81};
	gridCount = { 19 , 13 };
}

void SceneDev1::Init()
{
	fontIds.push_back(FONT_PATH"Amiri-Regular.ttf");
	texIds.push_back(SPRITE_PATH"chapterBG0003.png");

	TextGo* textGo = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	SpriteGo* spriteGo = new SpriteGo(SPRITE_PATH"chapterBG0003.png");
	Button* button = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* button1 = new Button(FONT_PATH"Amiri-Regular.ttf");
	Button* saveBNT = new Button(FONT_PATH"Amiri-Regular.ttf");

	button->SetString("WALL");
	button->SetPosition({ 1920 - 500.f, 0 });
	button->SetCallBack([this]() {
		this->type = Types::WALL;
	});

	button1->SetString("TILE");
	button1->SetPosition({ 1920 - 200.f, 0 });
	button1->SetCallBack([this]() {
		this->type = Types::TILE;
	});

	saveBNT->SetString("SAVE");
	saveBNT->SetToggle(false);
	saveBNT->SetPosition({1920 - 350.f , 1080 - 200.f});
	saveBNT->SetCallBack([this]() {
		
	});
	spriteGo->SetScale({ 0.7f , 0.7f });

	
	gridSize.x *= spriteGo->GetScale().x;
	gridSize.y *= spriteGo->GetScale().y;

	textGo->SetString("DEV1");

	AddGameObject(saveBNT);
	AddGameObject(button);
	AddGameObject(button1);
	AddGameObject(spriteGo);
	AddGameObject(textGo);
	DrawGrid(gridSize, gridCount);
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

	

	//if (INPUT_MGR.GetKeyDown(KEY::Right)) {
	//	std::cout << "GRIDSIZE : " << gridSize.x << " ," << gridSize.y << std::endl;
	//	gridSize.x++;
	//	DrawGrid(gridSize, gridCount);
	//}
	//if (INPUT_MGR.GetKeyDown(KEY::Left)) {
	//	std::cout << "GRIDSIZE : " << gridSize.x << " ," << gridSize.y << std::endl;
	//	gridSize.x--;
	//	DrawGrid(gridSize, gridCount);
	//}
	//if (INPUT_MGR.GetKeyDown(KEY::Down)) {
	//	std::cout << "GRIDSIZE : " << gridSize.x << " ," << gridSize.y << std::endl;
	//	gridSize.y++;
	//	DrawGrid(gridSize, gridCount);
	//}
	//if (INPUT_MGR.GetKeyDown(KEY::Up)) {
	//	std::cout << "GRIDSIZE : " << gridSize.x << " ," << gridSize.y << std::endl;
	//	gridSize.y--;
	//	DrawGrid(gridSize, gridCount);
	//}

	//if (INPUT_MGR.GetKeyDown(KEY::D)) {
	//	std::cout << "GRID COUNT : " << gridCount.x << " ," << gridCount.y << std::endl;
	//	gridCount.x++;
	//	DrawGrid(gridSize, gridCount);
	//}
	//if (INPUT_MGR.GetKeyDown(KEY::A)) {
	//	std::cout << "GRID COUNT : " << gridCount.x << " ," << gridCount.y << std::endl;
	//	gridCount.x--;
	//	DrawGrid(gridSize, gridCount);
	//}
	//if (INPUT_MGR.GetKeyDown(KEY::S)) {
	//	std::cout << "GRID COUNT : " << gridCount.x << " ," << gridCount.y << std::endl;
	//	gridCount.y++;
	//	DrawGrid(gridSize, gridCount);
	//}
	//if (INPUT_MGR.GetKeyDown(KEY::W)) {
	//	std::cout << "GRID COUNT : " << gridCount.x << " ," << gridCount.y << std::endl;
	//	gridCount.y--;
	//	DrawGrid(gridSize, gridCount);
	//}
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	
}



void SceneDev1::DrawGrid(sf::Vector2f cellSize, sf::Vector2f cellCount)
{
	for (int i = 0; i < grids.size(); i++) {
		for (int j = 0; j < grids[i].size(); i++) {
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
			vec.push_back(grid);
		}
		grids.push_back(vec);
	}
}
