#pragma once

#include <iostream>
#include <list>

#include "ImGui/imgui.h"
#include "ImGui/imgui-SFML.h"

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class CEngine;
class Widget;
class CObject
{

	//Functions
public:
	CObject();
	~CObject();

	sf::Vector2f GetMousePosition();

	virtual sf::Drawable& GetForDraw();
	virtual void Tick(float dt);

	virtual void setTransparency(float procent);

	CEngine* GetEngine();
	void SetEngine(CEngine* engine);

	template<typename Type>
	Widget* CreateWidget()
	{
		Widget* newWidget = new Type;
		GetEngine()->CreateWidget(newWidget);
		return newWidget;
	};

private:
	CEngine* engine;
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