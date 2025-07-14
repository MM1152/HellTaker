#include "stdafx.h"
#include "Animator.h"



void Animator::SetEvent(const std::string& id,  std::function<void()> event)
{
	events.insert({ id , event });
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

	for (auto event : events) {
		if (event.first == GetCurrentClipId() && currentFrame == totalFrame) {
			if (event.second) {
				event.second();
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
