#pragma once

#include <iostream>

#include "UI/UIObject.h"

class TextBlock : public UIObject
{
public:
	TextBlock(std::string text, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingSpeed);
	~TextBlock();

	virtual void SendToRender() override;

	sf::Text text;
};

