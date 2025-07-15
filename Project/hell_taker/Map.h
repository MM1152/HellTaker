#pragma once
#include "Singleton.h"
class Map : public Singleton<Map>
{
	friend Singleton<Map>;
protected:
	std::vector<std::vector<std::vector<int>>> map_Data;
	std::vector<std::vector<std::vector<int>>> backGround_Map_Data;

	std::vector<sf::Vector2f> map_gridSize;
	std::vector<sf::Vector2f> map_gridCount;
	std::vector<int> map_MoveCount;
	
	int mapIndex = 0;
	
	sf::Vector2f gridSize;
	sf::Vector2f gridCount;
	int moveCount;
public:
	void Init();
	void Release();

	std::vector<std::vector<int>> GetMapData();
	std::vector<std::vector<int>> GetBackGroundMap();
	sf::Vector2f GetGridSize();
	sf::Vector2f GetGridCount();
	int GetTileData(int height , int row);
	int GetMoveCount();
	int GetMapIndex() { return mapIndex; };
	void SetMapIndex(int idx);
	void ReLoad();
	std::vector<std::vector<int>> TranslateMapData(const std::vector<std::vector<float>>& mapData);
};

#define MAP Map::Instance()