#pragma once

#include "Core/CEngine.h"
#include "Core/CObject.h"

class UIElement : public CObject 
{
public:
	UIElement();
	UIElement(sf::RectangleShape shape);
	UIElement(sf::RectangleShape shape, sf::Text text);
	UIElement(sf::Sprite sprite);
	UIElement(sf::Sprite sprite, sf::Text text);
	UIElement(sf::Text text);

	~UIElement();
};

