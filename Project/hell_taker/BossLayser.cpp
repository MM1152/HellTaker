#include "stdafx.h"
#include "BossLayser.h"
#include "Scene.h"
#include "Player.h"

BossLayser::BossLayser(float radious, const std::string& name)
    :GameObject(name)
{
    layser.setRadius(radious);
	translayser.setRadius(radious + 10);
	translayser.setFillColor({ 255, 255, 255, 60 });
    warningSign.setSize({ 1000 , 50 });
    warningSign.setFillColor({ 255 , 255 , 255 , 70 });
	brightBackGorund.setSize({ 0 ,0});
	brightBackGorund.setFillColor({ 255, 255, 255 , 40 });
}

void BossLayser::SetPosition(const sf::Vector2f pos)
{
    position = pos;
    layser.setPosition(pos);
	translayser.setPosition(pos);
	warningSign.setPosition({ pos.x , pos.y - 20.f });
}

void BossLayser::SetRotaion(const float rot)
{
    rotation = rot;
    layser.setRotation(rot);
	translayser.setRotation(rot);
	warningSign.setRotation(rot);
}

void BossLayser::SetOrigin(Origins preset)
{
    originPreset = preset;
    UTILS.SetOrigins(layser, preset);
	UTILS.SetOrigins(warningSign, preset);
	UTILS.SetOrigins(translayser, preset);
}

void BossLayser::SetOrigin(sf::Vector2f ori)
{
    originPreset = Origins::Custom;
    origin = ori;
    layser.setOrigin(ori);
	translayser.setOrigin(ori);
}

void BossLayser::SetScale(sf::Vector2f scale)
{
    this->scale = scale;
    layser.setScale(scale);
	translayser.setScale(scale);
}

void BossLayser::Init()
{
}

void BossLayser::Reset()
{
	brightBackGorund.setSize({ 0,0 });
	translayser.setScale({ 0,0 });
	SetOrigin(Origins::LC);
	SetActive(false);
	SetRotaion(90);

	activeDuration = 3.6f;
    isScaleUp = false;
    t = 0;
    duration = 0.3f;
}

void BossLayser::Update(float dt)
{
	if (GetActive()) {
		timer += dt;

		if (hitAble && player->GetXY().x >= minRow && player->GetXY().y <= maxRow) {
			player->SetMoveCount(-1);
			player->Die();
		}

		if (timer < middleTimer) {
			warningSign.setFillColor(sf::Color(255, 255, 255, 100));
			return;
		}
		else if (timer < maxTimer) {
			warningSign.setFillColor(sf::Color(255, 255, 255, 0));
			return;
		}

		layser.setFillColor(sf::Color(255, 255, 255, 255));

		if (isScaleUp) {
			float size = UTILS.Lerp(minSize.y, maxSize.y, t);
			layser.setScale({ maxSize.x , size });
			translayser.setScale({ maxSize.x , size });
			brightBackGorund.setSize({ 1920 ,1080 });
			
			t += dt / duration;
			if (t >= 0.5) hitAble = true;
			if (t >= 1) {
				isScaleUp = false;
				t = 0;
			}
		}
		else {
			activeDuration -= dt;
			if (activeDuration >= 0) {
				if (minSizeUp) {
					layser.setScale({layser.getScale().x , layser.getScale().y * 1.05f });
					translayser.setScale({ layser.getScale().x , layser.getScale().y * 1.05f });
					minSizeUp = false;
				}
				else {
					layser.setScale({ layser.getScale().x , layser.getScale().y / 1.05f });
					translayser.setScale({ layser.getScale().x , layser.getScale().y / 1.05f });
					minSizeUp = true;
				}
				return;
			}

			float size = UTILS.Lerp(maxSize.y, minSize.y, t);
			layser.setScale({ maxSize.x , size });
			translayser.setScale({ maxSize.x , size });
			t += dt / duration;
			if (t <= 0.8) hitAble = true;
			if (t >= 1) {
				hitAble = false;
				SetActive(false);
				t = 0;
			}
		}
	}
}

void BossLayser::Exit()
{
}

void BossLayser::Release()
{
}

void BossLayser::Draw(sf::RenderWindow& window)
{
	if (GetActive()) {
		window.draw(brightBackGorund);
		window.draw(warningSign);
		window.draw(layser);
		window.draw(translayser);
	}
}

sf::FloatRect BossLayser::GetLocalBound()
{
    return sf::FloatRect();
}

sf::FloatRect BossLayser::GetGlobalBound()
{
    return sf::FloatRect();
}

void BossLayser::Shoot()
{
	SetActive(true);
	layser.setScale({ 0, 0 });
	isScaleUp = true;
	timer = 0;
}

void BossLayser::SetRow(int minRow , int maxRow)
{
	this->minRow = minRow;
	this->maxRow = maxRow;
}
