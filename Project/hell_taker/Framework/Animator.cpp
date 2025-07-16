#include "stdafx.h"
#include "Animator.h"



void Animator::SetEvent(const std::string& id , int checkFrame , std::function<void()> event)
{	
	if (events.find(id) == events.end()) {
		std::vector<int> vec1 = { checkFrame };
		std::vector<std::function<void()>> vec2 = { event };

		events.insert({ id , vec2 });
		eventsCheckFrame.insert({ id , vec1 });
		return;
	}	
	events[id].push_back(event);
	eventsCheckFrame[id].push_back(checkFrame);
}	

void Animator::Play(const std::string id , bool resetTexuterRect)
{
	Play(&ANIMATION_MGR.Get(id) , resetTexuterRect);
}

void Animator::Play(AnimationClip* clip , bool resetTexuterRect)
{
	this->resetTexuterRect = resetTexuterRect;
	currentClip = clip;
	totalFrame = clip->frames.size() - 1;
	currentFrame = 0;

	frameDuration = 1.f / clip->fps;
	accTime = 0.f;	
	SetFrame(currentFrame);
}

void Animator::Update(float dt)
{
	if (currentClip == nullptr) return;

	accTime += dt;
	if (accTime < frameDuration) return;

	currentFrame++;
	accTime = 0;
	
	SetFrame(currentFrame);

	for (int i = 0; i < events[GetCurrentClipId()].size(); i++) {
		int checkFrame = eventsCheckFrame[GetCurrentClipId()][i];

		if (checkFrame == -1) {
			checkFrame = totalFrame;
		}

		if (currentFrame == checkFrame) {
			if (events[GetCurrentClipId()][i]) {
				events[GetCurrentClipId()][i]();
			}
		}
	}

	if (currentFrame >= totalFrame) {
		currentFrame = 0;
	}

}

void Animator::SetFrame(int currentFrarme)
{
	if (body != nullptr) {
		body->setTexture(TEXTURE_MGR.Get(currentClip->frames[currentFrame]) , resetTexuterRect);		
	}
}

void Animator::Stop()
{
	currentClip = nullptr;
}
