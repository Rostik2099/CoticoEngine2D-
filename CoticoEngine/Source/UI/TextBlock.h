#pragma once

#include <iostream>

#include "UI/UIObject.h"

class TextBlock : public UIObject
{
public:
	TextBlock(std::string textStringT, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelayT = 0.0, sf::Color textColor = sf::Color::White, sf::Text::Style textStyle = sf::Text::Regular);
	~TextBlock();	

	virtual sf::Drawable& GetForDraw() override;
	virtual void AddTick() override;

private:

	void UpdateTextBlock(std::string textString);

	//Variables
	sf::Text text;
	sf::Font font;
	std::string textString;
	float progress;
	float appearingDelay;
};

