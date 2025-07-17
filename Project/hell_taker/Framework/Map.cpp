#include "stdafx.h"
#include "Map.h"

void MapData_MGR::Init()
{	
	for (int i = 0; i < 8; i++) {
		map_Data.push_back(TranslateMapData(UTILS.ReadMapDataFile(MAP_DATA(i + 1))));

		map_gridSize.push_back(gridSize);
		map_gridCount.push_back(gridCount);
		map_MoveCount.push_back(moveCount);

		backGround_Map_Data.push_back(TranslateMapData(UTILS.ReadMapDataFile(MAP_BACKGROUND_DATA(i + 1))));
	}
}

void MapData_MGR::ReLoad() {
	map_Data.clear();
	map_gridSize.clear();
	map_gridCount.clear();
	map_MoveCount.clear();
	backGround_Map_Data.clear();
	for (int i = 0; i < 8; i++) {
		map_Data.push_back(TranslateMapData(UTILS.ReadMapDataFile(MAP_DATA(i + 1))));

		map_gridSize.push_back(gridSize);
		map_gridCount.push_back(gridCount);
		map_MoveCount.push_back(moveCount);

		backGround_Map_Data.push_back(TranslateMapData(UTILS.ReadMapDataFile(MAP_BACKGROUND_DATA(i + 1))));
	}
}

void MapData_MGR::Release()
{
}

std::vector<std::vector<int>> MapData_MGR::GetMapData()
{
	return map_Data[mapIndex];
}

std::vector<std::vector<int>> MapData_MGR::GetBackGroundMap()
{
	return backGround_Map_Data[mapIndex];
}

sf::Vector2f MapData_MGR::GetGridSize()
{
	return map_gridSize[mapIndex];
}

sf::Vector2f MapData_MGR::GetGridCount()
{
	return map_gridCount[mapIndex];
}

int MapData_MGR::GetTileData(int height, int row)
{
	return map_Data[mapIndex][height][row];
}

int MapData_MGR::GetMoveCount()
{
	return map_MoveCount[mapIndex];
}

void MapData_MGR::SetMapIndex(int idx)
{
	if (idx < 0) idx = 0;
	if (idx > 5) idx = 5;

	mapIndex = idx;
}

std::vector<std::vector<int>> MapData_MGR::TranslateMapData(const std::vector<std::vector<float>>& mapData)
{
	std::vector<std::vector<int>> infos;

	if (mapData.size() > 0) {
		for (int i = 0; i < mapData.size() - 3; i++) {
			std::vector<int> vec;
			for (int j = 0; j < mapData[i].size(); j++) {
				vec.push_back((int)mapData[i][j]);
			}
			infos.push_back(vec);
		}

		//FIX XYÃà ¹Ý´ë·ÎµÊ
		gridCount = { (float)mapData[0].size() , (float)mapData.size() - 3.f };
		gridSize = { mapData[mapData.size() - 2][0] , mapData[mapData.size() - 3][0] };
		moveCount = (int)(mapData[mapData.size() - 1][0]);
	}

	return infos;
}

