#include "OneButtonMenu.h"
#include "UI/Button.h"
#include "UI/TextBlock.h"
#include "Level.h"

OneButtonMenu::OneButtonMenu()
{
	this->pathToFile = "Content/Widgets/OneButton.cewidget";
}

void OneButtonMenu::OnConstruct()
{
	this->leftButton = Bind<Button>("LeftButton");
	this->leftText = Bind<TextBlock>("LeftText");
	this->mainText = Bind<TextBlock>("MainText");
}

void OneButtonMenu::Tick(float dt)
{
	Widget::Tick(dt);

	if (leftButton->isPressed())
		level->OpenLevel(this->leftLevel);
}

