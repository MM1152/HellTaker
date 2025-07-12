#include "stdafx.h"
#include "Utils.h"
#include "GameObject.h"
#include "rapidcsv.h"

void Utils::Init()
{
	textureMap.insert({ SpriteTypes::PLAYER , SPRITE_PATH"assets100V20053.png" });
	textureMap.insert({ SpriteTypes::OBSTACLE , SPRITE_PATH"assets100V20081.png" });
}
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
	int i = 0;
	int j = 0;
	for (i = 0; i < write.size() - 2; i++) {
		for (j = 0; j < write[i].size(); j++) {
			document.SetCell(j, i, write[i][j]);
		}
	}
	
	document.SetCell(0, i-1, write[i++]);
	document.SetCell(1, i-1, write[i]);

	std::ifstream file(filePath);
	if (file.good()) {
		std::cout << "REMOVE FILE" << std::endl;
		remove(filePath.c_str());
	}
	std::cout << "CREATE FILE" << std::endl;
	document.Save(filePath);
}

std::vector<std::string> Utils::ReadFile(const std::string filePath)
{
	std::ifstream file(filePath);
	std::vector<std::string> readFileInfo;

	if (!file.good()) {
		std::cout << "FAIL TO LOAD FILE " << filePath << std::endl;
		return readFileInfo;
	}
	
	rapidcsv::Document document(filePath);
	int i = 0;
	int j = 0;

	if (document.GetRowCount() == 0) return readFileInfo;
 
	for (i = 0; i < document.GetRowCount() - 1; i++) {
		auto row = document.GetRow<std::string>(i);
		std::string word;
		for (j = 0; j < row.size(); j++) {
			word += row[j];
		}

		readFileInfo.push_back(word);
	}
	readFileInfo.push_back(document.GetCell<std::string>(0, i ));
	readFileInfo.push_back(document.GetCell<std::string>(1, i ));


	return readFileInfo;
}





