#pragma once
#include "ImmovableObstacle.h"
class Huddle : public ImmovableObstacle
{
protected:

public:
	Huddle(const std::string& texId = "", const std::string& name = "");
	~Huddle() override;

	void Init() override;
	void Reset() override;
};

