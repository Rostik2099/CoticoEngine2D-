#include "Core/CEngine.h"


int main()
{
	CEngine Engine;
	Engine.CreateWindow(1280, 720, "CoticoEngine", sf::Style::Default);
	ImGui::SFML::Init(*Engine.window);

	sf::Text text;
	Engine.CreateText("RuslanKaban", sf::Vector2f(100.f, 200.f), sf::Vector2f(100.f,150.f), "Content/Fonts/Calibri.ttf", 24);
	sf::CircleShape biba;

	std::vector<sf::Text> bebra;
	sf::Text boba;
	bebra.push_back(boba);
	//Main loop
	sf::Clock deltaClock;
	while (Engine.window->isOpen())
	{
		Engine.UpdateWindowEvents();
		Engine.Update();
		Engine.Draw(biba);
	}

	return 0;
}