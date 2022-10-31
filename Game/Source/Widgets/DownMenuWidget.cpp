#include "DownMenuWidget.h"
#include "UI/Button.h"
#include "UI/TextBlock.h"
#include "Level.h"

DownMenuWidget::DownMenuWidget()
{
	this->pathToFile = "Content/Widgets/DownMenu.cewidget";
}

void DownMenuWidget::OnConstruct()
{
	left = Bind<Button>("LeftButton");
	right = Bind<Button>("RightButton");

	leftText = Bind<TextBlock>("LeftText");
	rightText = Bind<TextBlock>("RightText");
	mainText = Bind<TextBlock>("MainText");
}

void DownMenuWidget::Tick(float dt)
{
	Widget::Tick(dt);

	if (left->isPressed() && left)
		level->OpenLevel(leftLevel);
	if (right->isPressed() && right)
		level->OpenLevel(rightLevel);
}

