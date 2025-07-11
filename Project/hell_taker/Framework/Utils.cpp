#include "stdafx.h"
#include "Utils.h"
#include "GameObject.h"

void Utils::SetOrigins(sf::Sprite& sp , Origins ori)
{
	sf::FloatRect rect = sp.getLocalBounds();

	sf::Vector2f origin;
	origin.x = rect.width * (((int)ori % 3) * 0.5f);
	origin.y = rect.height * (((int)ori / 3) * 0.5f);

	sp.setOrigin(origin);
}

void Utils::SetOrigins(sf::Text& sp, Origins ori)
{
	sf::FloatRect rect = sp.getLocalBounds();

	sf::Vector2f origin;
	origin.x = rect.width * (((int)ori % 3) * 0.5f);
	origin.y = rect.height * (((int)ori / 3) * 0.5f);

	sp.setOrigin(origin);
}





