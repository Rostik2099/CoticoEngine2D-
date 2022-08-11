#pragma once

#include <iostream>
#include <list>

#include "ImGui/imgui.h"
#include "ImGui/imgui-SFML.h"

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class CObject
{

	//Functions
public:
	CObject();
	~CObject();

	virtual sf::Drawable& GetForDraw();
	virtual void AddTick();
};



class StaticObject : public CObject
{
	sf::Sprite sprite;
};



class SemiStaticcObject : public CObject
{
public:
	std::vector<sf::Sprite> states;

	int animationStage; // если анимация не началась то 0
	bool StartAnimation(sf::Clock dT, float probability); // если возвращает true, то выставляет animationStage на states.size() - 1
};