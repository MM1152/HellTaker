#pragma once
#include "Huddle.h"
class UpDownHudle : public Huddle
{
protected:
	Animator animator;
public:
	UpDownHudle(const std::string& texId ="", const std::string& name ="");
	~UpDownHudle() override = default;

	void Init() override;
	void Reset() override;
	void Update(float dt) override;
	void Play();
};

