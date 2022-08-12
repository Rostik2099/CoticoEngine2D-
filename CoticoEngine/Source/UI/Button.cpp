#include "Button.h"

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color buttonIdleColor, sf::Color buttonHoverColor, sf::Color buttonPressedColor)
{
	this->buttonState = Idle;
	this->buttonShape.setSize(size);
	this->buttonShape.setPosition(position);
	this->buttonShape.setFillColor(buttonIdleColor);
	this->idleColor = buttonIdleColor;
	this->hoverColor = buttonHoverColor;
	this->pressedColor = buttonPressedColor;
}

Button::~Button()
{
}

sf::Drawable& Button::GetForDraw()
{
	return buttonShape;
}

void Button::Tick()
{
	this->buttonState = Idle;
	if (this->buttonShape.getGlobalBounds().contains(GetMousePosition()))
	{
		this->buttonState = Hover;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->buttonState = Pressed;
	}

	switch (this->buttonState)
	{
	case Idle:
		this->buttonShape.setFillColor(this->idleColor);
		break;
	case Hover:
		this->buttonShape.setFillColor(this->hoverColor);
		break;
	case Pressed:
		this->buttonShape.setFillColor(this->pressedColor);
		break;
	default:
		std::cout << "Button error" << std::endl;
		break;
	}
}

bool Button::isPressed() const
{
	if (this->buttonState == Pressed)
		return true;
	else return false;
}
