#pragma once
#include "UI/UIObject.h"

enum ButtonState { Idle = 0, Hover, Pressed };

class Button : public UIObject
{

public:
	Button();
	Button(sf::Vector2f position, sf::Vector2f size, sf::Color buttonIdleColor, sf::Color buttonHoverColor, sf::Color buttonPressedColor);
	~Button();

	virtual sf::Drawable& GetForDraw() override;
	virtual void Tick() override;
	virtual void SetProperties(std::list<std::pair<std::string, std::string>> properties) override;

	bool isPressed() const;

private:
	sf::RectangleShape buttonShape;

	short unsigned buttonState;
public:
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressedColor;
};

