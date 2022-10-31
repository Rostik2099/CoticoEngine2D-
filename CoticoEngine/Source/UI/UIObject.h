#pragma once

#include "Core/CObject.h"

struct ButtonParams
{
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color idleColor;
	sf::Color hovColor;
	sf::Color pressedColor;
};

struct TextBlockParams
{
	sf::Vector2f position;
	sf::Vector2f size;
	int charSize;
	std::string fontPath;
	std::string text;
};

struct BorderParams
{
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
};

class UIObject : public CObject 
{
public:
	virtual void Tick(float dt);
	virtual void SetProperties(std::list<std::pair<std::string, std::string>> properties);

	UIObject();
	~UIObject();

protected:
	TextBlockParams GetTextParams(std::list<std::pair<std::string, std::string>> properties);
	ButtonParams GetButtonParams(std::list<std::pair<std::string, std::string>> properties);
	BorderParams GetBorderParams(std::list<std::pair<std::string, std::string>> properties);

public:
	std::string name;

//Parsers
private:
	sf::Color ParseColor(std::string value);
	sf::Vector2f ParseVector2f(std::string value);
};

