#pragma once
#include "AnimationClip.h"

class Animator
{
protected:
	int currentFrame = 0;
	int totalFrame = 0;

	float accTime = 0.f;
	float frameDuration = 0.f;
	float speed = 1.f;

	float x = 0;
	float prevX = 0;
	AnimationClip* currentClip;
	sf::Sprite* body = nullptr;
	std::unordered_map<std::string , std::function<void()>> events;

public:
	Animator() = default;
	~Animator() = default;


	void SetEvent(const std::string& id , std::function<void()> event);
	void SetTarget(sf::Sprite* body) { this->body = body; };
	void Play(const std::string id);
	void Play(AnimationClip* clip);
	void Update(float dt);
	void SetFrame(int currentFrarme);
	const std::string& GetCurrentClipId() {
		if (currentClip == nullptr) {
			return "";
		}
		return currentClip->id;
	}
};

