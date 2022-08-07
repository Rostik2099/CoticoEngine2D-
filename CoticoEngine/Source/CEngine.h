#pragma once

#include <iostream>
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

	void Draw(sf::CircleShape circle);

//VARIABLES
public:
	sf::RenderWindow* window;
	sf::Event* windowEvent;
};

