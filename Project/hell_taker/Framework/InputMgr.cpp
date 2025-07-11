#include "stdafx.h"
#include "InputMgr.h"

bool InputMgr::Contain(std::vector<int> vector, sf::Keyboard::Key key)
{
	return vector[key];
}

bool InputMgr::Contain(std::vector<int> vector, sf::Mouse::Button key)
{
	return vector[key + KEY::KeyCount];
}

void InputMgr::Init()
{
	downKeys.resize(sf::Keyboard::KeyCount + sf::Mouse::ButtonCount);
	heldKeys.resize(sf::Keyboard::KeyCount + sf::Mouse::ButtonCount);
	upKeys.resize(sf::Keyboard::KeyCount + sf::Mouse::ButtonCount);
}

void InputMgr::Reset()
{
	std::fill(downKeys.begin(), downKeys.end(), 0);
	std::fill(upKeys.begin(), upKeys.end(), 0);
}

void InputMgr::Update(float dt)
{
	Reset();
	mousePosition = sf::Mouse::getPosition();
}

void InputMgr::UpdateEvent(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (!Contain(heldKeys, event.key.code)) {
			heldKeys[(int)event.key.code] = 1;
			downKeys[(int)event.key.code] = 1;
		}
		break;
	case sf::Event::KeyReleased:
		heldKeys[(int)event.key.code] = 0;
		upKeys[(int)event.key.code] = 1;
		break;
	case sf::Event::MouseButtonPressed:
		if (!Contain(heldKeys, event.mouseButton.button)) {
			heldKeys[(int)event.mouseButton.button + KEY::KeyCount] = 1;
			downKeys[(int)event.mouseButton.button + KEY::KeyCount] = 1;
		}
		break;
	case sf::Event::MouseButtonReleased:
		heldKeys[(int)event.mouseButton.button + KEY::KeyCount] = 0;
		upKeys[(int)event.mouseButton.button + KEY::KeyCount] = 1;
		break;
	}
}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return downKeys[(int)key];
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return heldKeys[(int)key];
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return upKeys[(int)key];
}

bool InputMgr::GetMouseDown(sf::Mouse::Button key)
{
	return downKeys[key + KEY::KeyCount];
}

bool InputMgr::GetMouse(sf::Mouse::Button key)
{
	return heldKeys[key + KEY::KeyCount];
}

bool InputMgr::GetMouseUp(sf::Mouse::Button key)
{
	return upKeys[key + KEY::KeyCount];
}
