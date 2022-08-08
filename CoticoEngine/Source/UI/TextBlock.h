#pragma once

#include <iostream>

#include "UI/UIElement.h"

class TextBlock : public UIElement
{
public:
	TextBlock(std::string text, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize);
	~TextBlock();

	virtual void SendToRender() override;

	sf::Text text;
};

