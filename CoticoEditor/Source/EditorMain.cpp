#include "Core/CEngine.h"


int main()
{
	CEngine Engine;
	Engine.CreateWindow(1280, 720, "CoticoEngine", sf::Style::Default);
	ImGui::SFML::Init(*Engine.window);

	sf::Clock deltaClock;
	Engine.CreateText("Andrey", sf::Vector2f(400.0 , 400.0), sf::Vector2f(5.0, 6.0), "Content/Fonts/Calibri.ttf", 24, 0.0, sf::Color::Magenta, sf::Text::Bold);

	Engine.CreateText("Rostislav", sf::Vector2f(500.0 , 500.0), sf::Vector2f(15.0, 6.0), "Content/Fonts/Calibri.ttf", 35, 2e3, sf::Color::White, sf::Text::Bold);
	//Main loop
	while (Engine.window->isOpen())
	{
		Engine.UpdateWindowEvents();
		Engine.Update();
		Engine.Draw();
	}

	return 0;
}