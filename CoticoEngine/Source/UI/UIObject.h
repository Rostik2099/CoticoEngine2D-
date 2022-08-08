#pragma once

#include "Core/CEngine.h"
#include "Core/CObject.h"

class UIObject : public CObject 
{
public:
	UIObject();
	UIObject(sf::RectangleShape shape);
	UIObject(sf::RectangleShape shape, sf::Text text);
	UIObject(sf::Sprite sprite);
	UIObject(sf::Sprite sprite, sf::Text text);
	UIObject(sf::Text text);

	~UIObject();
};
