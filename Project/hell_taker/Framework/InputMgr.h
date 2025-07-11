#pragma once
#include "Singleton.h"
class InputMgr : public Singleton<InputMgr>
{
	friend Singleton<InputMgr>;
protected:
	InputMgr() = default;

	std::vector<int> downKeys;
	std::vector<int> heldKeys;
	std::vector<int> upKeys;

	bool Contain(std::vector<int> vector, sf::Keyboard::Key key);

public:
	void Init();
	void Reset();
	void Update(float dt);
	void UpdateEvent(sf::Event& event);

	bool GetKeyDown(sf::Keyboard::Key key);
	bool GetKey(sf::Keyboard::Key key);
	bool GetKeyUp(sf::Keyboard::Key key);
};

#define INPUT_MGR InputMgr::Instance()