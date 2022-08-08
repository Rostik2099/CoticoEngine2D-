#pragma once

#include <iostream>
#include <list>

#include "ImGui/imgui.h"
#include "ImGui/imgui-SFML.h"

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class CEngine
{

//FUNCTIONS
private:
	void Init();

public:
	CEngine();
	~CEngine();

	void CreateWindow(unsigned int windowWidth, unsigned int windowHeight, std::string windowName, sf::Uint32 windowStyle);

	void UpdateWindowEvents();

	void Update();

	void Draw();

	void CreateText(std::string text, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingSpeed); //appeatingSpeed = 0 мнгновенное появление

	//Setters
	void AddTextToRender(sf::Text text);

	//void Animation(std::vector<std::string> pictures, sf::Vector2f location, sf::Vector2f size);

	//void ResizedAnimation(std::vector<std::string> pictures, std::vector<sf::Vector2f> location, std::vector<sf::Vector2f> size);

	//void Sound(std::string pathToFile);

//VARIABLES
public:
	sf::Clock deltaClock;
	sf::RenderWindow* window;
	sf::Event* windowEvent;
	std::list<CObject&> Objects;
	std::list<UIObject&> UIObjects;

private:
	//Render stuff

	//UI
	std::vector<sf::RectangleShape> UIRects;
	std::vector<sf::Sprite> UISprites;
	std::vector<sf::Text> UITexts;
};

