#pragma once
#include "stdafx.h"

class GameObject
{
protected:
	std::string name;

	sf::Vector2f position;
	sf::Vector2f origin;
	sf::Vector2f scale;
	float rotation;

	Origins originPreset;

	SortingLayers sortingLayer;
	int sortingOrder;

	sf::FloatRect localBound;
	sf::FloatRect globalBound;
	bool isActive;
public:

	GameObject(const std::string name = "");
	virtual ~GameObject() = default;

	virtual void SetPosition(const sf::Vector2f pos) = 0;
	virtual void SetRotaion(const float rot) = 0;
	virtual void SetOrigin(Origins preset) = 0;
	virtual void SetOrigin(sf::Vector2f ori) = 0;
	virtual void SetScale(sf::Vector2f scale) = 0;

	void SetSortingOrder(int ord) { sortingOrder = ord; };
	void SetSortingLayer(SortingLayers layer) { sortingLayer = layer; };
	void SetActive(bool active) { isActive = active; };

	virtual void Init() = 0;
	virtual void Reset() = 0;
	virtual void Update(float dt) = 0;
	virtual void Exit() = 0;
	virtual void Release() = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

	sf::Vector2f GetPosition() const { return position; };
	float GetRotation() { return rotation; };
	sf::Vector2f GetOrigin() { return origin; };
	Origins GetOriginPreset() { return originPreset; };
	int GetSortingOrder() { return sortingOrder; };
	SortingLayers GetSortingLayer() { return sortingLayer; };
	bool GetActive() { return isActive; };
	sf::Vector2f GetScale() { return scale; };
	virtual sf::FloatRect GetLocalBound() = 0;
	virtual sf::FloatRect GetGlobalBound() = 0;
};

