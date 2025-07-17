#pragma once
#include "Effect.h"
class KickEffect :
    public Effect
{

public:
	KickEffect(const std::string& texId = "", const std::string& name = "");
	~KickEffect() override = default;

	void Init() override;
	void Reset() override;


	void Play() override;

};

