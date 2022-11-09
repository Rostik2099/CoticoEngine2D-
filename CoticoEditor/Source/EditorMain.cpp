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
	Engine.AddIGLayer(Prop);
	Engine.AddIGLayer(ElemList);

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