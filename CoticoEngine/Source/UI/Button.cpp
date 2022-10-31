#include "Button.h"
#include "Core/InputManager.h"

Button::Button() {}

Button::~Button(){}

sf::Drawable& Button::GetForDraw()
{
	return buttonShape;
}

void Button::Tick(float dt)
{
	this->buttonState = Idle;
	if (IsMouseOver())
	{	
		this->buttonState = Hover;
		if (GetInputManager()->leftMousePressed)
		{
			this->buttonState = Pressed;
			GetInputManager()->leftMousePressed = false;
		}
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

void Button::SetProperties(std::list<std::pair<std::string, std::string>> properties)
{
	ButtonParams params = GetButtonParams(properties);
	this->buttonShape.setPosition(params.position);
	this->buttonShape.setSize(params.size);
	this->idleColor = params.idleColor;
	this->hoverColor = params.hovColor;
	this->pressedColor = params.pressedColor;
}


bool Button::isPressed() const
{
	if (this->buttonState == Pressed)
		return true;
	else return false;
}

bool Button::IsMouseOver()
{
	float mouseX = GetMousePosition().x;
	float mouseY = GetMousePosition().y;

	float btnPosX = this->buttonShape.getPosition().x;
	float btnPosY = this->buttonShape.getPosition().y;

	float btnPosWidth = this->buttonShape.getPosition().x + buttonShape.getLocalBounds().width;
	float btnPosHeight = this->buttonShape.getPosition().y + buttonShape.getLocalBounds().height;

	if (mouseX < btnPosWidth && mouseX > btnPosX && mouseY < btnPosHeight && mouseY > btnPosY)
	{
		return true;
	}
	return false;
}
