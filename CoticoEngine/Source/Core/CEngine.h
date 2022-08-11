#pragma once

#include "Core/CObject.h"
#include "UI/UIObject.h"
#include "UI/TextBlock.h"

class CEngine
{

//FUNCTIONS
private:
	void Init();

public:
	CEngine();
	~CEngine();

	void CreateWindow(unsigned int windowWidth, unsigned int windowHeight, std::string windowName, sf::Uint32 windowStyle, unsigned int frameLimit = 0);

	void UpdateWindowEvents();

	void Update();

	void Draw();

	void CreateText(std::string text, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelay = 0.0, sf::Color textColor = sf::Color::White, sf::Text::Style textStyle = sf::Text::Regular); //appeatingSpeed = мнгновенное появление, положительное значение - появление по % от текста, отрицательное - посимволам

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
	std::list<CObject*> Objects;
	std::list<UIObject*> UIObjects;

private:
	//Render stuff

	//UI
	std::vector<sf::RectangleShape> UIRects;
	std::vector<sf::Sprite> UISprites;
	std::vector<sf::Text> UITexts;
};

