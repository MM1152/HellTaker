#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(const std::string name)
	:name(name)
	,position({0,0})
	,origin({0,0})
	,rotation(0)
	,originPreset(Origins::LT)
	,sortingLayer(SortingLayers::DEFAULT)
	,sortingOrder(0)
	,isActive(true)
{
}
