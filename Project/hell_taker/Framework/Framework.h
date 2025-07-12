#pragma once
#include "Singleton.h"
class Framework : public Singleton<Framework>
{
	friend Singleton<Framework>;
protected:
	Framework() = default;
	~Framework() = default;

	sf::RenderWindow window;
	sf::Clock clock;
public:
	void Init(sf::Vector2f windowSize);
	void Update();
	void Release();

	sf::RenderWindow& GetWindow() { return window; };
};

#define FRAMEWORK Framework::Instance()