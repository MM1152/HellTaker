#pragma once
#include "Singleton.h"

class Scene;
class TextGo;
class SceneMgr : public Singleton<SceneMgr>
{
protected:
	friend Singleton<SceneMgr>;

	SceneIds startScene = SceneIds::SceneGame;
	SceneIds currentScene = SceneIds::None;
	SceneIds nextScene = SceneIds::None;

	std::unordered_map<SceneIds, Scene*> scenes;

	bool showFPS = false;
	sf::Text fps;
	sf::Font font;
	float timer = 0.f;
	float currentTimer = 0.f;
	float prevTimer = 0.f;
	

	SceneMgr() = default;
	~SceneMgr() = default;
public:
	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
	void Release();
	void Exit();
	void Reset();

	void ChangeScene(SceneIds id);
	Scene* GetCurrentScene();
};


#define SCENE_MGR SceneMgr::Instance()
