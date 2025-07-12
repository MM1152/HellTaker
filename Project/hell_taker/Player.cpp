#include "stdafx.h"
#include "Player.h"

bool Player::CheckBound(int x, int y)
{
	if (x < 0 || y < 0) return false;
	else if (x > mapData[0].size() - 1 || y > mapData.size() - 1) return false;
	else if (mapData[y][x] == 0) return false;

	return true;
}

Player::Player(const std::string texId, const std::string name)
	: SpriteGo(texId , name)
{
	
}

void Player::Update(float dt)
{
	if (INPUT_MGR.GetKeyDown(KEY::Left)) {
		if (CheckBound(x - 1, y)) {
			x--;
		}
	}
	if (INPUT_MGR.GetKeyDown(KEY::Right)) {
		if (CheckBound(x + 1, y)) {
			x++;
		}
	}
	if (INPUT_MGR.GetKeyDown(KEY::Up)) {
		if (CheckBound(x, y - 1)) {
			y--;
		}
	}
	if (INPUT_MGR.GetKeyDown(KEY::Down)) {
		if (CheckBound(x, y + 1)) {
			y++;
		}
	}
	Move();
}

void Player::SetMapData(std::vector<std::vector<int>>& mapData, sf::Vector2f gridSize, int x, int y)
{
	this->mapData = mapData;
	this->gridSize = gridSize;
	this->x = x;
	this->y = y;
}

void Player::Move()
{
	SetPosition({x * gridSize.x , y * gridSize.y});
}




