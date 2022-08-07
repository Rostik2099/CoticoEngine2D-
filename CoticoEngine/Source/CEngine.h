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

	//void Text(std::string text, sf::Vector2f location, sf::Vector2f size, std::string font, int fontSize);  // text appearing, надо еще насрать распознаванием слов и переносом если не влезает

	//void Animation(std::vector<std::string> pictures, sf::Vector2f location, sf::Vector2f size);

	//void ResizedAnimation(std::vector<std::string> pictures, std::vector<sf::Vector2f> location, std::vector<sf::Vector2f> size);

	//void Sound(std::string pathToFile);

//VARIABLES
public:
	sf::RenderWindow* window;
	sf::Event* windowEvent;
};

