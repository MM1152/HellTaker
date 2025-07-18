#include "stdafx.h"
#include "LayserBlock.h"

void LayserBlock::Shoot()
{
	if (isShoot) {

	}
}

LayserBlock::LayserBlock(const std::string& texId, const std::string& name)
	:ImmovableObstacle(texId , name)
{
}

void LayserBlock::Init()
{
	layser = new Layser(TEXTURE_PATH"W_chapter2.png");
	layser->Init();
	
	ImmovableObstacle::Init();
}

void LayserBlock::Reset()
{
	layser->Reset();

	layserSprite.setTexture(TEXTURE_MGR.Get(TEXTURE_PATH"Soft.png"));
	SetOrigin(Origins::MC);
	UTILS.SetOrigins(layserSprite, Origins::MC);
	ImmovableObstacle::Reset();
}

void LayserBlock::Update(float dt)
{
	if (!GetActive()) return;

	if (isSizeUp) {
		sf::Vector2f size = UTILS.Lerp(maxSize, minSize, t);
		layserSprite.setScale(size);
		t += 0.05f;
		if (t >= 1) {
			t = 0;
			isSizeUp = !isSizeUp;
		}
	}
	else {
		sf::Vector2f size = UTILS.Lerp(minSize, maxSize, t);
		layserSprite.setScale(size);
		t += 0.05f;
		if (t >= 1) {
			t = 0;
			isSizeUp = !isSizeUp;
		}
	}


	layser->Update(dt);
	if (layser->GetTimer() >= 0.5f && oneTime) {
		if (shootNextLayser) {
			shootNextLayser();
			oneTime = false;
		}
	}
	ImmovableObstacle::Update(dt);
}

void LayserBlock::Exit()
{
	ImmovableObstacle::Exit();
	delete layser;
}

void LayserBlock::Draw(sf::RenderWindow& window)
{
	ImmovableObstacle::Draw(window);
	window.draw(layserSprite);
	layser->Draw(window);
}

void LayserBlock::SetShoot()
{
	layser->Shoot();
	oneTime = true;
}

void LayserBlock::SetPosition(sf::Vector2f pos)
{
	ImmovableObstacle::SetPosition(pos);
	layserSprite.setPosition({ GetPosition().x + 50.f , GetPosition().y + 40.f });
	layser->SetPosition({ GetPosition().x + 50.f , GetPosition().y + 40.f });
}

void LayserBlock::SetMapData(sf::Vector2f gridSize, int x, int y, SpriteTypes objectId)
{
	ImmovableObstacle::SetMapData(gridSize, x, y, objectId);
	layser->SetHeight(y);
}

