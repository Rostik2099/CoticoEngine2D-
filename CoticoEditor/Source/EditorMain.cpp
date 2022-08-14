#include "Core/CEngine.h"
#include "Properties.h"
#include "ElementsList.h"
#include "TestWidget.h"
#include "TWidget.h"

int main()
{
	CEngine Engine;
	Engine.appType = Editor;
	Engine.CreateAppWindow(1280, 720, "CoticoEngine", sf::Style::Default, 60);
	ImGui::SFML::Init(*Engine.window);

	CObject bebra;
	bebra.SetEngine(&Engine);

	Properties* Prop = new Properties;
	ElementsList* ElemList = new ElementsList;
	ElemList->currentWidget = bebra.CreateWidget<TestWidget>();
	Engine.AddIGLayer(Prop);
	Engine.AddIGLayer(ElemList);

	//Engine.CreateWidget("Content/Ruslan.cewidget");


	/*Engine.CreateText(Engine.GetObjectsBegin(), "Andrey", sf::Vector2f(400.0 , 400.0), sf::Vector2f(120.0, 30.0), "Content/Fonts/Calibri.ttf", 24, -20.0, 5, sf::Color::Magenta, sf::Text::Italic);

	Engine.CreateText(Engine.GetObjectsBegin(), "Rostislav", sf::Vector2f(500.0 , 500.0), sf::Vector2f(150.0, 60.0), "Content/Fonts/Calibri.ttf", 35, 30, 5, sf::Color::White, sf::Text::Bold);*/

	Engine.CreateText(Engine.GetObjectsBegin(), "Sometimes, I pull it so hard, I rip the skin. MMMMMMM MMMM MMM mMM MMM капец тебе копченный перец - Это кто тут у нас копченный?", sf::Vector2f(700.0 , 100.0), sf::Vector2f(400.0, 60.0), "Content/Fonts/Calibri.ttf", 35, -3, 30, sf::Color::White, sf::Text::Bold);

	//Engine.CreateText(Engine.GetObjectsBegin(), "Русяпрогеймер2008", sf::Vector2f(200.0 , 200.0), sf::Vector2f(300.0, 300.0), "Content/Fonts/Calibri.ttf", 50, -50, 5, sf::Color::Red, sf::Text::Bold);

	Button* test = Engine.CreateButton(sf::Vector2f(620.f, 320.f), sf::Vector2f(150.f, 80.f), sf::Color::Green, sf::Color::Yellow, sf::Color::Blue);
	Prop->button = test;
	//Однажды я сбегу копать тоннели в майнкрафт, и вы меня больше не найдете
	

	//Main loop
	while (Engine.window->isOpen())
	{
		Engine.UpdateWindowEvents();
		Engine.Update();
		Engine.Draw();

		if (test->isPressed())
			bebra.CreateWidget<TWidget>();
	}

	return 0;
}