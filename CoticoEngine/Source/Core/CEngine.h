#pragma once

#include "Core/CObject.h"
#include "UI/UIObject.h"
#include "UI/TextBlock.h"
#include "UI/Button.h"
#include "ImGui/ImGuiLayer.h"
#include "UI/Widget.h"

enum ApplicationTypes {Editor = 0, Game};

class CEngine
{

//FUNCTIONS
private:
	void Init();

public:
	CEngine();
	~CEngine();

	void AddIGLayer(ImGuiLayer* newLayer);

	void CreateAppWindow(unsigned int windowWidth, unsigned int windowHeight, std::string windowName, sf::Uint32 windowStyle, unsigned int frameLimit = 0);

	void UpdateWindowEvents();

	std::list<CObject*>::iterator GetObjectsBegin();

	void DeteleObject(std::list<CObject*>::iterator object);

	void Update();

	void Draw();

	std::list<CObject*>::iterator CreateText(std::list<CObject*>::iterator parentObject, std::string text, sf::Vector2f position, sf::Vector2f size, std::string pathToFont, int fontSize, float appearingDelay = 0.0, float lineSpacing = 15, sf::Color textColor = sf::Color::White, sf::Text::Style textStyle = sf::Text::Regular); //appeatingSpeed = мнгновенное появление, положительное значение - появление по % от текста, отрицательное - посимволам (округлится вниз)

	Button* CreateButton(std::list<CObject*>::iterator parentObject, sf::Vector2f position, sf::Vector2f size, sf::Color buttonIdleColor, sf::Color buttonHoverColor, sf::Color buttonPressedColor);

	void CreateWidget(Widget* widgetToCreate);
	//void Animation(std::vector<std::string> pictures, sf::Vector2f location, sf::Vector2f size);

	//void ResizedAnimation(std::vector<std::string> pictures, std::vector<sf::Vector2f> location, std::vector<sf::Vector2f> size);

	//void Sound(std::string pathToFile);

//VARIABLES
public:
	sf::Clock deltaClock;
	sf::RenderWindow* window;
	sf::Event* windowEvent;
	ApplicationTypes appType;

private:
	std::list<CObject*> Objects;
	std::list<UIObject*> UIObjects;
	std::list<ImGuiLayer*> ImGuiLayers;
	std::list<Widget*> widgets;

	sf::Vector2f ScalePosition(sf::Vector2f oldPosition);
};

