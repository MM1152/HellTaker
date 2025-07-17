#include "stdafx.h"
#include "Layser.h"

Layser::Layser(const std::string& texId, const std::string name)
	:SpriteGo(texId , name)
{
}

void Layser::Reset()
{
	SpriteGo::Reset();
	SetOrigin(Origins::LC);
}

void Layser::Update(float dt)
{
	if (GetActive()) {
		timer += dt;
		hitAble = false;
		if (timer < middleTimer) {
			sprite.setColor(sf::Color(255, 255, 255, 60));
			sprite.setScale(maxSize.x , maxSize.y - 0.7f);
			return;
		}
		else if (timer < maxTime) {
			sprite.setColor(sf::Color(255, 255, 255, 0));
			return;
		}

		sprite.setColor(sf::Color(255, 255, 255, 255));
		
		if (isScaleUp) {
			float size = UTILS.Lerp(minsize.y, maxSize.y, t);
			sprite.setScale({ maxSize.x , size });
			t += 0.05f;
			if (t >= 0.5) hitAble = true;
			if (t >= 1) {
				isScaleUp = false;
				t = 0;
			}
		}
		else {
			float size = UTILS.Lerp(maxSize.y, minsize.y, t);
			sprite.setScale({ maxSize.x , size });
			t += 0.05f;
			if (t <= 0.7) hitAble = true;
			if (t >= 1) {
				SetActive(false);
				t = 0;
			}
		}
		
	}
}

void Layser::Shoot()
{
	SetActive(true);
	timer = 0;
}

void Layser::Draw(sf::RenderWindow& window)
{
	if (GetActive()) {
		window.draw(sprite);
	}
}
