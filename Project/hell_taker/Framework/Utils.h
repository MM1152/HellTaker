#pragma once
#include "stdafx.h"

class GameObject;
class Utils : public Singleton<Utils>
{
	friend Singleton<Utils>;
protected:
	Utils() = default;

public:
	std::unordered_map<SpriteTypes, std::string> textureMap;
	void Init();
	void SetOrigins(sf::Sprite& sp , Origins ori);
	void SetOrigins(sf::Text& sp, Origins ori);

	void WriteMapDataFile(const std::string filePath , std::vector<std::vector<float>> write);
	float Lerp(float x, float y, float t);
	sf::Vector2f Lerp(sf::Vector2f x, sf::Vector2f y, float t);
	std::vector<std::vector<float>> ReadMapDataFile(const std::string filePath);

	nlohmann::json ReadInteractiveViewerData(const std::string& filePath);
};

#define UTILS Utils::Instance()

