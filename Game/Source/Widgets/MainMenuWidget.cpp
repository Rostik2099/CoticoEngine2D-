#include "MainMenuWidget.h"
#include "UI/Button.h"
#include "Core/CEngine.h"
#include "Level.h"

MainMenuWidget::MainMenuWidget()
{
	this->pathToFile = "Content/Widgets/MainMenu.cewidget";
}

void MainMenuWidget::OnConstruct()
{
	newGame = Bind<Button>("NewGame");
	exit = Bind<Button>("Exit");
}

void MainMenuWidget::Tick(float dt)
{
	Widget::Tick(dt);

	if (newGame->isPressed() && newGame)
	{
		curLvl->OpenLevel("CoticCommi");
	}
	if (exit)
	{
		if (exit->isPressed() && exit)
			GetEngine()->window->close();
	}
}