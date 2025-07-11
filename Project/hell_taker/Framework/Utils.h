#pragma once
#include "stdafx.h"

class Utils : public Singleton<Utils>
{
	friend Singleton<Utils>;
protected:
	Utils() = default;
public:
	void SetOrigins(sf::Sprite& sp , Origins ori);
};

#define UTILS Utils::Instance()

