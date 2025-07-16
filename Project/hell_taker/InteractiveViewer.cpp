#include "stdafx.h"
#include "InteractiveViewer.h"
#include "GameScene.h"
InteractiveViewer::InteractiveViewer(const std::string& fontId, const std::string& name)
	:TextGo(fontId , name)
{
	sortingOrder = 50;
}

void InteractiveViewer::SettingCharacter(int idx)
{
	curIndex = idx;
}

void InteractiveViewer::Init()
{
	TextGo::Init();
	iconAnimation.SetTarget(&icon);
	successAnimation.SetTarget(&succecsSprite);

	icon.setColor(sf::Color::Red);

	texures.push_back(SPRITE_PATH"pand_idle.png");
	texures.push_back(SPRITE_PATH"pand_flust.png");

	names.push_back("Pandemica, the Tired Demon");
	lines.push_back("Name's Pandemonica, Hell's Customer Service.\n\t\t\t\t\t\tHow may I serve you?");
	mixUp.push_back("We can figure somthing out at my place");
	mixUp.push_back("Maybe I can serve YOU instead?");	
	correct.push_back(1);

	successAnimation.SetEvent("Success", -1, [this](){
		successAnimation.Stop();	
	});
}

void InteractiveViewer::Reset()
{	
	SetActive(false);
	TextGo::Reset();
	successAnimation.Play(ANI_PATH"Success.csv");
	succecsSprite.setPosition({ 1920 / 2 , 1080 - 200.f });
	UTILS.SetOrigins(succecsSprite, Origins::MC);

	iconAnimation.Play(ANI_PATH"InteractiveViewIcon.csv" , true);
	icon.setPosition({ 1920 / 2 , 1080 - 200.f });
	icon.setColor(sf::Color::Red);
	icon.setScale({ 0.8f , 0.8f });

	topButton.setTexture(TEXTURE_MGR.Get(SPRITE_PATH"button0003.png"));
	downButton.setTexture(TEXTURE_MGR.Get(SPRITE_PATH"button0003.png"));

	mixUp1.setFont(FONT_MGR.Get(fontId));
	mixUp1.setFillColor(sf::Color::White);
	mixUp1.setString(mixUp[curIndex * 2]);
	mixUp1.setCharacterSize(23);
	UTILS.SetOrigins(mixUp1 , Origins::MC);

	mixUp2.setFont(FONT_MGR.Get(fontId));
	mixUp2.setFillColor(sf::Color::White);
	mixUp2.setString(mixUp[curIndex * 2 + 1]);
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
	sprite.setTexture(TEXTURE_MGR.Get(texures[curIndex * 2]) , true);

	sprite.setPosition({ 1920 / 2 , 1080 / 2 + 200.f });
	UTILS.SetOrigins(sprite, Origins::MB);

	nameText.setString(names[curIndex]);
	lineText.setString(lines[curIndex]);
	nameText.setPosition({1920 / 2 , 750.f});
	nameText.setFillColor(sf::Color::Red);
	lineText.setPosition({ 1920 / 2 , 800.f });

	UTILS.SetOrigins(nameText, Origins::MC);
	UTILS.SetOrigins(lineText, Origins::MC);

	showMessageBox = false;
	up = false;
	t = 0;
}

void InteractiveViewer::Update(float dt)
{
	TextGo::Update(dt);
	iconAnimation.Update(dt);
	if (clear) {
		successAnimation.Update(dt);
	}
	
	UTILS.SetOrigins(icon, Origins::MC);
	if (INPUT_MGR.GetKeyDown(KEY::Space) && !showMessageBox) {
		showMessageBox = true;
	}

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

	if (INPUT_MGR.GetKeyDown(KEY::Space) && clear) {
		gameScene->ResetScene();
	}

	if (INPUT_MGR.GetKeyDown(KEY::Space)) {
		if (correct[curIndex] == up) {
			sprite.setTexture(TEXTURE_MGR.Get(texures[curIndex * 2 + 1] ), true);
			UTILS.SetOrigins(sprite, Origins::MB);

			clear = true;
			MAP.SetMapIndex(MAP.GetMapIndex() + 1);
			
		}
		else {

		}
	}
}

void InteractiveViewer::Draw(sf::RenderWindow& window)
{
	window.draw(backGround);
	window.draw(backGroundSprite);
	window.draw(sprite);
	window.draw(nameText);
	window.draw(lineText);

	if (!showMessageBox) window.draw(icon);
	
	if (showMessageBox && !clear) {
		window.draw(topButton);
		window.draw(downButton);
		window.draw(mixUp1);
		window.draw(mixUp2);
	}
	if (clear) {
		window.draw(succecsSprite);
	}
}
