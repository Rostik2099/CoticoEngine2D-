#include "Core/CEngine.h"
#include "GUI/Properties.h"
#include "GUI/ElementsList.h"
#include "Tests/TestAnim.h"

int main()
{
	CEngine Engine;
	Engine.appType = Editor;
	Engine.CreateAppWindow(1280, 720, "CoticoEngine", sf::Style::Default, 60);
	ImGui::SFML::Init(*Engine.window);

	TestAnim* testAnim = new TestAnim;
	Engine.AddObject(testAnim);

	Properties* Prop = new Properties;
	ElementsList* ElemList = new ElementsList;
	ElemList->currentWidget = testAnim->widget;
	ElemList->props = Prop;
	Engine.AddIGLayer(Prop);
	Engine.AddIGLayer(ElemList);

	Engine.CreateText(Engine.GetObjectsBegin(), "Andrey", sf::Vector2f(0.3 , 0.3), sf::Vector2f(0.1, 0.04), "Content/Fonts/Calibri.ttf", 24, -20.0, 5, sf::Color::Magenta, sf::Text::Italic);

	Engine.CreateText(Engine.GetObjectsBegin(), "Sometimes, I pull it so hard, I rip the skin. MMMMMMM MMMM MMM mMM MMM капец тебе копченный перец - Это кто тут у нас копченный?", sf::Vector2f(0.55 , 0.14), sf::Vector2f(0.31, 0.08), "Content/Fonts/Calibri.ttf", 35, -300, 30, sf::Color::White, sf::Text::Bold);

	//Однажды я сбегу копать тоннели в майнкрафт, и вы меня больше не найдете

	//Main loop
	while (Engine.window->isOpen())
	{
		Engine.Update();
		Engine.UpdateWindowEvents();
		Engine.Draw();
	}

	return 0;
}