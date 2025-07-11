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
	button->SetPosition({ 1920 / 2, 1080 / 2 });
	button->SetOrigin(Origins::LT);
	button->SetCharacterSize(50);
	button->SetString("ASDASD");
	button->SetFillColor(sf::Color::Black);
	
	spriteGo->SetScale({ 0.7f , 0.7f });

	mouseRect = new Grid({10 , 10});
	gridSize.x *= spriteGo->GetScale().x;
	gridSize.y *= spriteGo->GetScale().y;

	textGo->SetString("DEV1");

	AddGameObject(button);
	AddGameObject(spriteGo);
	AddGameObject(textGo);
	DrawGrid(gridSize, gridCount);
	AddGameObject(mouseRect);
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

	mouseRect->SetPosition({ INPUT_MGR.GetMousePosition().x - 10.f , INPUT_MGR.GetMousePosition().y - 30.f});

	for (Grid* grid : grids) {
		if (grid->GetGlobalBound().intersects(mouseRect->GetGlobalBound())) {
			grid->SetOutLineColor(sf::Color::Red);
		}
		else {
			grid->SetOutLineColor(sf::Color::Green);
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



void SceneDev1::DrawGrid(sf::Vector2f cellSize, sf::Vector2f cellCount)
{
	for (auto grid : grids) {
		RemoveGameObject(grid);
	}

	grids.clear();

	for (int i = 0; i < cellCount.y; i++) {
		for (int j = 0; j < cellCount.x; j++) {
			Grid* grid = new Grid(cellSize);
			grid->Init();
			grid->SetPosition({ cellSize.x * j , cellSize.y * i });
			AddGameObject(grid);
			grids.push_back(grid);
		}
	}
}
