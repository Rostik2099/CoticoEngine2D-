#include "TWidget.h"
#include "UI/Button.h"
#include "Render/Animation.h"

TWidget::TWidget()
{
	this->pathToFile = "Content/Bebra.cewidget";
}

void TWidget::Tick(float dt)
{
	Widget::Tick(dt);
	if (button && button2)
	{
		if (button->isPressed())
		{
			button2->idleColor = sf::Color::Magenta;
			this->anim->Continue();
		}
		if (button2->isPressed())
			this->anim->Stop();
	}
}

void TWidget::OnConstruct()
{
	button = Bind<Button>("Ruslan");
	button2 = Bind<Button>("2");
}

