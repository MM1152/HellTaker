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

	bool resetTexuterRect = false;

public:
	Animator() = default;
	~Animator() = default;


	void SetEvent(const std::string& id , std::function<void()> event);
	void SetTarget(sf::Sprite* body) { this->body = body; };
	void Play(const std::string id , bool resetTexuterRect = false);
	void Play(AnimationClip* clip , bool resetTexuterRect = false);
	void Update(float dt);
	void SetFrame(int currentFrarme);
	const std::string& GetCurrentClipId() {
		if (currentClip == nullptr) {
			return "";
		}
		return currentClip->id;
	}
};

