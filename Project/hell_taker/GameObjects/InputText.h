#pragma once
#include "Button.h"
class InputText : public Button
{
protected:
	bool writeAble;
public:
	InputText(const std::string fontId = "", const std::string name = "");

	void Update(float dt) override;
	void Reset() override;

	void SetString(const std::string tex) override;

	void SetSize(const sf::Vector2f size);
};

