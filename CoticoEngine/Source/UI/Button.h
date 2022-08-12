#pragma once
#include "UI/UIObject.h"

enum ButtonState { Idle = 0, Hover, Pressed };

class Button : public UIObject
{

public:
	Button(sf::Vector2f position, sf::Vector2f size, sf::Color buttonIdleColor, sf::Color buttonHoverColor, sf::Color buttonPressedColor);
	~Button();

	virtual sf::Drawable& GetForDraw() override;
	virtual void AddTick() override;

	bool isPressed() const;

private:
	sf::RectangleShape buttonShape;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressedColor;

	short unsigned buttonState;
};

