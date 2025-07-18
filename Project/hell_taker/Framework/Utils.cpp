#include "stdafx.h"
#include "Utils.h"
#include "GameObject.h"
#include "rapidcsv.h"

void Utils::Init()
{
	textureMap.insert({ SpriteTypes::PLAYER , SPRITE_PATH"move1.png" });
	textureMap.insert({ SpriteTypes::ENEMY , SPRITE_PATH"enemy1.png" });
	textureMap.insert({ SpriteTypes::OBSTACLE , SPRITE_PATH"assets100V20081.png" });
	textureMap.insert({ SpriteTypes::MAP1NPC , SPRITE_PATH"NPC1.png" });
	textureMap.insert({ SpriteTypes::HUDLE , SPRITE_PATH"assets100V20122.png" });
	textureMap.insert({ SpriteTypes::BOX , SPRITE_PATH"backup_lockbox.png" });
	textureMap.insert({ SpriteTypes::GOLDKEY , SPRITE_PATH"assets100V20104.png" });
	textureMap.insert({ SpriteTypes::UPDOWNHUDLE , SPRITE_PATH"assets100V20123.png" });	
	textureMap.insert({ SpriteTypes::DOWNUPHUDDLE , SPRITE_PATH"assets100V20120.png" });
	textureMap.insert({ SpriteTypes::BOSSMAPTILE , SPRITE_PATH"bossFloor.png" });
	textureMap.insert({ SpriteTypes::BOSSOUTTILE , SPRITE_PATH"BossOutTile.png" });
	textureMap.insert({ SpriteTypes::BOSSMAPLASER , TEXTURE_PATH"labLaser0001.png" });
	textureMap.insert({ SpriteTypes::BOSS , SPRITE_PATH"boss.png" });
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

void Utils::SetOrigins(sf::Shape& sp, Origins ori)
{
	sf::FloatRect rect = sp.getLocalBounds();

	sf::Vector2f origin;
	origin.x = rect.width * (((int)ori % 3) * 0.5f);
	origin.y = rect.height * (((int)ori / 3) * 0.5f);

	sp.setOrigin(origin);
}

void Utils::WriteMapDataFile(const std::string filePath , std::vector<std::vector<float>> write)
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
	document.SetCell(0, i, write[i][0]);
	document.SetCell(1, i, write[i][1]);
	document.SetCell(0, i, write[++i][0]);

	std::ifstream file(filePath);
	if (file.good()) {
		std::cout << "REMOVE FILE" << std::endl;
		remove(filePath.c_str());
	}
	std::cout << "CREATE FILE" << std::endl;
	document.Save(filePath);
}

float Utils::Lerp(float min, float max, float t)
{
	return min + (max - min) * t;
}

sf::Vector2f Utils::Lerp(sf::Vector2f min, sf::Vector2f max, float t)
{
	return min + (max - min) * t;
}

std::vector<std::vector<float>> Utils::ReadMapDataFile(const std::string filePath)
{
	std::ifstream file(filePath);
	std::vector<std::vector<float>> readFileInfo;

	if (!file.good()) {
		std::cout << "FAIL TO LOAD FILE " << filePath << std::endl;
		return readFileInfo;
	}
	
	rapidcsv::Document document(filePath);
	int i = 0;
	int j = 0;

	if (document.GetRowCount() == 0) return readFileInfo;
 
	std::vector<float> vec;
	for (i = 0; i < document.GetRowCount() - 2; i++) {
		auto row = document.GetRow<float>(i);
		for (j = 0; j < row.size(); j++) {
			vec.push_back(row[j]);
		}

		readFileInfo.push_back(vec);
		vec.clear();
	}
	
	vec.push_back(document.GetCell<float>(0, i));
	readFileInfo.push_back(vec);
	vec.clear();

	vec.push_back(document.GetCell<float>(1, i));
	readFileInfo.push_back(vec);
	vec.clear();

	vec.push_back(document.GetCell<float>(0, i + 1));
	readFileInfo.push_back(vec);

	return readFileInfo;
}

nlohmann::json Utils::ReadInteractiveViewerData(const std::string& filePath)
{
	std::ifstream read(filePath);
	nlohmann::json data = nlohmann::json::parse(read);
	
	return data;
}





