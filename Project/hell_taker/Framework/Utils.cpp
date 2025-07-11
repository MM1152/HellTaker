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

void Utils::WriteFile(const std::string filePath)
{
	 std::ofstream file(filePath);

	 if (file.is_open()) {
		 file << "HIHI";
		 file.close();
	 }
	 else {
		 std::cout << "READ FILE FAIL" << std::endl;
	 }
}

std::list<std::string> Utils::ReadFile(const std::string filePath)
{
	std::string line;
	std::list<std::string> readText;
	std::ifstream file(filePath);
	if (file.is_open()) {
		while (std::getline(file, line)) {
			readText.push_back(line);
		}
		file.close();
	}
	else {
		std::cout << "FAIL TO OPEN FILE " << filePath << std::endl;
	}

	return readText;
}





