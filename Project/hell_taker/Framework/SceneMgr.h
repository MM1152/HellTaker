#pragma once
#include "Singleton.h"

class Scene;
class SceneMgr : public Singleton<SceneMgr>
{
protected:
	friend Singleton<SceneMgr>;

	SceneIds startScene = SceneIds::Dev1;
	SceneIds currentScene = SceneIds::None;
	SceneIds nextScene = SceneIds::None;

	std::unordered_map<SceneIds, Scene*> scenes;

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
