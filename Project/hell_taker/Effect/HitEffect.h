#pragma once
#include "Effect.h"
class HitEffect : public Effect
{
protected:

public:
	HitEffect(const std::string& texId = "" , const std::string& name = "");
	~HitEffect() override = default;

	void Init() override;
	void Reset() override;
	
	
	void Play() override;

};

