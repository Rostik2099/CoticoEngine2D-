#include "HiddenWidget.h"
#include "UI/Button.h"
#include "Level.h"


void HiddenWidget::OnConstruct()
{
	button = Bind<Button>("Button");
}

void HiddenWidget::Tick(float dt)
{
	Widget::Tick(dt);

	if (button->isPressed())
		level->OpenLevel("WantDrink");
}
