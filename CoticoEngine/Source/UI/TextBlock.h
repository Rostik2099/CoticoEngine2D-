#pragma once

#include <iostream>

#include "UI/UIObject.h"

class TextBlock : public UIObject
{
public:
	TextBlock(std::list<CObject*> &Objects, std::list<CObject*>::iterator &parentObject, std::string textStringT, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelayT = 0.0, float lineSpacing = 15, sf::Color textColor = sf::Color::White, sf::Text::Style textStyle = sf::Text::Regular);
	~TextBlock();	

	virtual sf::Drawable& GetForDraw() override;
	virtual void Tick() override;
	virtual void setTransparency(float procent) override;

private:

	TextBlock(std::string textStringT, float newPosY, float appearingDelayT, sf::Text textT);
	void UpdateTextBlock(std::string textString);
	std::list<std::pair<std::string, int>> strParcing(std::string str);

	//Variables
	bool procentSpeed;
	sf::Text text;
	sf::Font font;
	std::string textString;
	float progress, lastDelay;
	float appearingDelay;

protected:
	sf::Text GetText();
};

