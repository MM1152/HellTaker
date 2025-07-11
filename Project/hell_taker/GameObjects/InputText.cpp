#include "stdafx.h"
#include "InputText.h"

InputText::InputText(const std::string fontId, const std::string name)
	:Button(fontId , name)
{
}


void InputText::Update(float dt)
{
	if (INPUT_MGR.GetMouseGlobalBound().intersects(rect.getGlobalBounds()) && INPUT_MGR.GetMouseDown(MOUSE::Left)) {
		writeAble = true;
		std::cout << "WRITE ABLE" << std::endl;
		rect.setFillColor(sf::Color::Cyan);
	}
	if (!INPUT_MGR.GetMouseGlobalBound().intersects(rect.getGlobalBounds()) && INPUT_MGR.GetMouseDown(MOUSE::Left)) {
		writeAble = false;
		std::cout << "WRITE ABLE FALSE" << std::endl;
		rect.setFillColor(sf::Color::White);
	}

	if (writeAble) {
		for (int i = KEY::Num0; i <= KEY::Num9; i++) {
			if (INPUT_MGR.GetKeyDown((KEY)i)) {
				std::string curString = GetString();
				curString += std::to_string(i - KEY::Num0);
				SetString(curString);

				std::cout << GetString() << std::endl;
			}
		}
		for (int i = KEY::Numpad0; i <= KEY::Numpad9; i++) {
			if (INPUT_MGR.GetKeyDown((KEY)i)) {
				std::string curString = GetString();
				curString += std::to_string(i - KEY::Numpad0);
				SetString(curString);
			}
		}
		if (INPUT_MGR.GetKeyDown(KEY::BackSpace)) {
			std::string curString = GetString();
			if (curString.size() > 0) {
				curString.resize(curString.size() - 1);
			}
			SetString(curString);
		}
	}
}

void InputText::Reset()
{
	Button::Reset();
	rect.setSize({100 , 50});
}

void InputText::SetString(const std::string tex)
{
	TextGo::SetString(tex);
}

void InputText::SetSize(const sf::Vector2f size)
{
	rect.setSize(size);
}
