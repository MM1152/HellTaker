#include "stdafx.h"
#include "Animator.h"

void Animator::Play(const std::string id)
{
	Play(&ANIMATION_MGR.Get(id));
}

void Animator::Play(AnimationClip* clip)
{
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

	if (currentFrame == totalFrame) {
		currentFrame = 0;
	}
}

void Animator::SetFrame(int currentFrarme)
{
	if (body != nullptr) {
		body->setTexture(TEXTURE_MGR.Get(currentClip->frames[currentFrame]), true);		
	}
}
