#include "stdafx.h"
#include "InteractiveViewer.h"
#include "GameScene.h"
InteractiveViewer::InteractiveViewer(const std::string& fontId, const std::string& name)
	:TextGo(fontId , name)
{
	sortingOrder = 50;
}

void InteractiveViewer::Init()
{
	TextGo::Init();
	textures.resize(2);
	lines.resize(3);
	mixUp.resize(2);

	iconAnimation.SetTarget(&icon);
	successAnimation.SetTarget(&succecsSprite);
	badEndAnimation.SetTarget(&badEndSprite);

	icon.setColor(sf::Color::Red);

	successAnimation.SetEvent("Success", -1, [this](){
		successAnimation.Stop();	
	});
	badEndAnimation.SetEvent("badEnd", -1, [this]() {
		badEndAnimation.Stop();
	});
}

void InteractiveViewer::Reset()
{	
	nlohmann::json data = UTILS.ReadInteractiveViewerData(INTERATIVE_DATA_PATH"map" + std::to_string(MAP.GetMapIndex() + 1) + ".json");

	textures[0] = (data)["texture"][0];
	textures[1] = (data)["texture"][1];

	name = (data)["name"];
	lines[0] = (data)["lines"][0];
	lines[1] = (data)["lines"][1];
	lines[2] = (data)["lines"][2];

	mixUp[0] = (data)["mixUp"][0];
	mixUp[1] = (data)["mixUp"][1];
	correct = (data)["correct"];

	SetActive(false);

	TextGo::Reset();
	successAnimation.Play(ANI_PATH"Success.csv");
	succecsSprite.setPosition({ 1920 / 2 , 1080 - 200.f });
	UTILS.SetOrigins(succecsSprite, Origins::MC);

	badEndSprite.setPosition({ 1920/2 , 1080 / 2 - 100.f });
	
	badEndAnimation.Play(ANI_PATH"badEnd.csv");
	UTILS.SetOrigins(badEndSprite, Origins::MC);

	iconAnimation.Play(ANI_PATH"InteractiveViewIcon.csv" , true);
	icon.setPosition({ 1920 / 2 , 1080 - 200.f });
	icon.setColor(sf::Color::Red);
	icon.setScale({ 0.8f , 0.8f });

	topButton.setTexture(TEXTURE_MGR.Get(SPRITE_PATH"button0003.png"));
	downButton.setTexture(TEXTURE_MGR.Get(SPRITE_PATH"button0003.png"));

	mixUp1.setFont(FONT_MGR.Get(fontId));
	mixUp1.setFillColor(sf::Color::White);
	mixUp1.setString(mixUp[0]);
	mixUp1.setCharacterSize(23);
	UTILS.SetOrigins(mixUp1 , Origins::MC);

	mixUp2.setFont(FONT_MGR.Get(fontId));
	mixUp2.setFillColor(sf::Color::White);
	mixUp2.setString(mixUp[1]);
	mixUp2.setCharacterSize(23);
	UTILS.SetOrigins(mixUp2, Origins::MC);

	topButton.setPosition({ 1920 / 2 , 890.f});
	topButton.setColor(initColor);
	topButton.setScale(curSize);
	mixUp1.setPosition({ topButton.getPosition().x ,  topButton.getPosition().y - 7.f });
	UTILS.SetOrigins(topButton, Origins::MC);

	downButton.setPosition({ 1920 / 2 , 950.f });
	downButton.setColor(initColor);
	downButton.setScale(curSize);
	mixUp2.setPosition({ downButton.getPosition().x ,  downButton.getPosition().y - 7.f });
	UTILS.SetOrigins(downButton, Origins::MC);

	backGround.setFillColor(sf::Color(2,2,27));
	backGround.setSize({1920 , 1080});
	backGroundSprite.setTexture(TEXTURE_MGR.Get(SPRITE_PATH"dialogueBG_hell.png"));
	backGroundSprite.setPosition({ 0 , 1080 / 2  - 100.f});
	UTILS.SetOrigins(backGroundSprite, Origins::LC);

	nameText.setFont(FONT_MGR.Get(fontId));
	lineText.setFont(FONT_MGR.Get(fontId));
	sprite.setTexture(TEXTURE_MGR.Get(textures[0]) , true);

	sprite.setPosition({ 1920 / 2 , 1080 / 2 + 200.f });
	UTILS.SetOrigins(sprite, Origins::MB);

	nameText.setString(name);
	lineText.setString(lines[0]);
	nameText.setPosition({1920 / 2 , 750.f});
	nameText.setFillColor(sf::Color::Red);
	lineText.setPosition({ 1920 / 2 , 800.f });

	UTILS.SetOrigins(nameText, Origins::MC);
	UTILS.SetOrigins(lineText, Origins::MC);

	showMessageBox = false;
	up = false;
	badClear = false;
	clear = false;
	badSelect = false;
	t = 0;
}

void InteractiveViewer::Update(float dt)
{
	TextGo::Update(dt);
	iconAnimation.Update(dt);
	if (clear) {
		successAnimation.Update(dt);
	}
	if (badClear) {
		badEndAnimation.Update(dt);
	}
	
	UTILS.SetOrigins(icon, Origins::MC);

	if (INPUT_MGR.GetKeyDown(KEY::Up) && up) {
		up = false;
		t = 0;
	}
	if (INPUT_MGR.GetKeyDown(KEY::Down) && !up) {
		up = true;
		t = 0;
	}
	
	if (!up && t <= 1) {
		topButton.setScale({ UTILS.Lerp(curSize , targetSize , t).x , UTILS.Lerp(curSize , targetSize , t).y });
		downButton.setScale({ UTILS.Lerp(targetSize ,curSize ,t).x , UTILS.Lerp(targetSize , curSize , t).y });
		t += 0.05f;
		topButton.setColor(selectColor);
		mixUp2.setFillColor(initColor);
		downButton.setColor(initColor);
		mixUp1.setFillColor(sf::Color::White);
	}
	if (up && t <= 1) {
		downButton.setScale({ UTILS.Lerp(curSize , targetSize , t).x , UTILS.Lerp(curSize , targetSize , t).y });
		topButton.setScale({ UTILS.Lerp(targetSize ,curSize ,t).x , UTILS.Lerp(targetSize , curSize , t).y });
		t += 0.05f;
		topButton.setColor(initColor);
		mixUp1.setFillColor(initColor);
		downButton.setColor(selectColor);
		mixUp2.setFillColor(sf::Color::White);
	}



	if (INPUT_MGR.GetKeyDown(KEY::Space) && (clear || badClear)) {
		gameScene->ResetScene();
	}

	if (INPUT_MGR.GetKeyDown(KEY::Space) && badSelect) {
		badClear = true;
	}

	if (INPUT_MGR.GetKeyDown(KEY::Space) && showMessageBox) {
		if (correct == up) {
			sprite.setTexture(TEXTURE_MGR.Get(textures[1] ), true);
			lineText.setString(lines[1]);

			UTILS.SetOrigins(lineText, Origins::MC);
			UTILS.SetOrigins(sprite, Origins::MB);

			clear = true;
			MAP.SetMapIndex(MAP.GetMapIndex() + 1);
		}
		else {
			lineText.setString(lines[2]);
			badSelect = true;
			UTILS.SetOrigins(lineText, Origins::MC);
		}
	}
	

	if (INPUT_MGR.GetKeyDown(KEY::Space) && !showMessageBox) {
		showMessageBox = true;
	}
}

void InteractiveViewer::Draw(sf::RenderWindow& window)
{
	window.draw(backGround);
	if (!badClear) {
		window.draw(backGroundSprite);
		window.draw(sprite);
		window.draw(nameText);
		window.draw(lineText);
	}
	if ((!showMessageBox || badSelect) && !badClear) window.draw(icon);
	
	if (showMessageBox && !clear && !badSelect) {
		window.draw(topButton);
		window.draw(downButton);
		window.draw(mixUp1);
		window.draw(mixUp2);
	}
	if (clear) {
		window.draw(succecsSprite);
	}
	if (badClear) {
		window.draw(badEndSprite);
	}
}
