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

	sf::Vector2i mousePosition;

	bool Contain(std::vector<int> vector, sf::Keyboard::Key key);
	bool Contain(std::vector<int> vector, sf::Mouse::Button key);
public:
	void Init();
	void Reset();
	void Update(float dt);
	void UpdateEvent(sf::Event& event);

	bool GetKeyDown(sf::Keyboard::Key key);
	bool GetKey(sf::Keyboard::Key key);
	bool GetKeyUp(sf::Keyboard::Key key);

	bool GetMouseDown(sf::Mouse::Button key);
	bool GetMouse(sf::Mouse::Button key);
	bool GetMouseUp(sf::Mouse::Button key);

	sf::Vector2i GetMousePosition() { return mousePosition; };
};

#define INPUT_MGR InputMgr::Instance()