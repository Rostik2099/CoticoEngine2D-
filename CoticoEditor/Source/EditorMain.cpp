#include "Core/CEngine.h"


int main()
{
	CEngine Engine;
	Engine.CreateWindow(1280, 720, "CoticoEngine", sf::Style::Default, 60);
	ImGui::SFML::Init(*Engine.window);

	sf::Clock deltaClock;
	Engine.CreateText("Andrey", sf::Vector2f(400.0 , 400.0), sf::Vector2f(120.0, 30.0), "Content/Fonts/Calibri.ttf", 24, -20.0, 5, sf::Color::Magenta, sf::Text::Italic);

	Engine.CreateText("Rostislav", sf::Vector2f(500.0 , 500.0), sf::Vector2f(150.0, 60.0), "Content/Fonts/Calibri.ttf", 35, 30, 5, sf::Color::White, sf::Text::Bold);

	Engine.CreateText("Sometimes, I pull it so hard, I rip the skin. MMMMMMM MMMM MMM mMM MMM капец тебе копченный перец - Это кто тут у нас копченный?", sf::Vector2f(700.0 , 100.0), sf::Vector2f(400.0, 60.0), "Content/Fonts/Calibri.ttf", 35, -3, 30, sf::Color::White, sf::Text::Bold);

	Engine.CreateText("Русяпрогеймер2008", sf::Vector2f(200.0 , 200.0), sf::Vector2f(300.0, 300.0), "Content/Fonts/Calibri.ttf", 50, -50, 5, sf::Color::Red, sf::Text::Bold);

	//Однажды я сбегу копать тоннели в майнкрафт, и вы меня больше не найдете

	//Main loop
	while (Engine.window->isOpen())
	{
		Engine.UpdateWindowEvents();
		Engine.Update();
		Engine.Draw();
	}

	return 0;
}