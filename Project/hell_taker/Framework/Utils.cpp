#include "stdafx.h"
#include "Utils.h"
#include "GameObject.h"
#include "rapidcsv.h"
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

void Utils::WriteFile(const std::string filePath , std::vector<std::string> write)
{
	rapidcsv::Document document;
	//document.SetCell(0, 0, "MapData");
	
	for (int i = 0; i < write.size(); i++) {
		for (int j = 0; j < write[i].size(); j++) {
			document.SetCell(j, i, write[i][j]);
		}
	}

	std::ifstream file(filePath);
	if (file.good()) {
		std::cout << "REMOVE FILE" << std::endl;
		remove(filePath.c_str());
	}
	std::cout << "CREATE FILE" << std::endl;
	document.Save(filePath);
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





