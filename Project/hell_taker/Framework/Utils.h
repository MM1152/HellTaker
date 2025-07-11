#pragma once
#include "stdafx.h"

class GameObject;
class Utils : public Singleton<Utils>
{
	friend Singleton<Utils>;
protected:
	Utils() = default;

public:
	void SetOrigins(sf::Sprite& sp , Origins ori);
	void SetOrigins(sf::Text& sp, Origins ori);

	void WriteFile(const std::string filePath);
	std::list<std::string> ReadFile(const std::string filePath);
};

#define UTILS Utils::Instance()

