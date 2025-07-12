#include "stdafx.h"


std::string MAP_DATA(int x) {
	return "GameData/MapData" + std::to_string(x) + ".csv";
}

std::string MAP_IMAGE(int x)
{
	return SPRITE_PATH"chapterBG000" + std::to_string(x) + ".png";
}
