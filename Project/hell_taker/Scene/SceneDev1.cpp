#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "Grid.h"
SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	fontIds.push_back(FONT_PATH"Amiri-Regular.ttf");
	texIds.push_back(SPRITE_PATH"chapterBG0001.png");
	TextGo* textGo = new TextGo(FONT_PATH"Amiri-Regular.ttf");
	SpriteGo* spriteGo = new SpriteGo(SPRITE_PATH"chapterBG0001.png");
	textGo->SetString("DEV1");

	AddGameObject(spriteGo);
	AddGameObject(textGo);
	DrawGrid({ 50,50 }, { 16 , 16 });
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
}

void SceneDev1::DrawGrid(sf::Vector2f cellSize, sf::Vector2f cellCount)
{
	for (int i = 0; i < cellCount.y; i++) {
		for (int j = 0; j < cellCount.x; j++) {
			Grid* grid = new Grid(cellSize);
			grid->Init();
			grid->SetPosition({ cellSize.x * j , cellSize.y * i });
			grid->GetPosition();
			AddGameObject(grid);
		}
	}
}
