#include "stdafx.h"
#include "InputMgr.h"

bool InputMgr::Contain(std::vector<int> vector, sf::Keyboard::Key key)
{
	return vector[key];
}

void InputMgr::Init()
{
	downKeys.resize(sf::Keyboard::KeyCount);
	heldKeys.resize(sf::Keyboard::KeyCount);
	upKeys.resize(sf::Keyboard::KeyCount);
}

void InputMgr::Reset()
{
	std::fill(downKeys.begin(), downKeys.end(), 0);
	std::fill(upKeys.begin(), upKeys.end(), 0);
}

void InputMgr::Update(float dt)
{
	Reset();
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
