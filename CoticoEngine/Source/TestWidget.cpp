#include "TestWidget.h"
#include "UI/Button.h"


TestWidget::TestWidget() { this->pathToFile = "Content/Bebra.cewidget"; }

void TestWidget::Tick(float dt)
{
	Widget::Tick(dt);
	if (button && button2)
	{
		if (button->isPressed())
			button2->idleColor = sf::Color::Magenta;
	}
}

void TestWidget::OnConstruct()
{
	button = Bind<Button>("Ruslan");
	button2 = Bind<Button>("2");
}
