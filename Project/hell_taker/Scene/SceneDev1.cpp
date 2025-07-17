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
}

void SceneDev1::Init()
{
	Scene::Init();
}

void SceneDev1::Reset()
{
	
	worldView.setSize({ 1920 , 1080 });
	worldView.setCenter({ 1920 / 2 , 1080 / 2 });

	SpriteGo* test = new SpriteGo(SPRITE_PATH"azazel_finalModel0001.png");

	AddGameObject(test);

	test->SetPosition({ 1920 / 2 , 1080 / 2 });

	Scene::Reset();

}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (INPUT_MGR.GetKeyDown(KEY::Space)) {
		shakeLeft = true;

	}
	CameraShake();
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	
	Scene::Draw(window);
	
}

void SceneDev1::CameraShake() {
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
				count = 1;
			}
			
			shakeRight = false;
			
		}
	}
}

